#pragma once

#include "Engine.h"
#include "InventoryComponent.generated.h"

class AItemBase;
class AInteractable;

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryChanged);

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent),
       BlueprintType)
class THIRSTTOLIVE_API UInventoryComponent : public UActorComponent {
  GENERATED_BODY()

public:
  UPROPERTY(BlueprintAssignable, meta = (HideInDetailPanel))
  FOnInventoryChanged OnInventoryChanged;

  UFUNCTION(BlueprintCallable)
  void RemoveItem(AItemBase *ItemToRemove);

  UFUNCTION(BlueprintGetter, Category = "Inventory")
  TMap<AItemBase *, FIntPoint> GetAllItems() const;

  UInventoryComponent();

  UFUNCTION(BlueprintImplementableEvent)
  void ReloadInventory();

  UFUNCTION(BlueprintGetter, Category = "Inventory")
  int32 GetInventoryWeight();

  UFUNCTION(BlueprintCallable, Category = "Inventory")
  bool TryAddItemToInventory(AItemBase *Item);

  void IncreaseMoney(int32 MoneyToAdd) { Money += MoneyToAdd; };

private:
  UPROPERTY(BlueprintReadOnly, Category = "Inventory",
            meta = (AllowPrivateAccess))
  TArray<AItemBase *> Inventory;

  UPROPERTY(BlueprintReadOnly, Category = "Inventory",
            meta = (AllowPrivateAccess))
  int32 Money;

  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Inventory",
            meta = (AllowPrivateAccess))
  int32 InventoryWeightLimit;

  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory",
            meta = (AllowPrivateAccess))
  int32 InventoryColumns;

  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Inventory",
            meta = (AllowPrivateAccess))
  int32 InventoryRows;

protected:
  virtual void BeginPlay() override;

private:
  UFUNCTION(BlueprintCallable)
  bool IsRoomAvaliable(int TopLeftIndex, AItemBase *Item) const;

  UFUNCTION(BlueprintCallable)
  uint8 TileToIndex(int Tile_X, int Tile_Y) const;

  UFUNCTION(BlueprintCallable)
  void AddItemAt(AItemBase *ItemToAdd, int TopLeftIndex);

  FIntPoint IndexToTile(int Index) const;
  bool IsTileValid(int Tile_X, int Tile_Y) const;
  AItemBase *GetItemAtIndex(int Index, bool &ValidIndex) const;
};
