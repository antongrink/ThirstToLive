#pragma once

#include "AutoPickup.generated.h"
#include "CoreMinimal.h"
#include "ItemBase.h"

class UInventoryComponent;
class USphereComponent;

UCLASS(Blueprintable, BlueprintType)
class THIRSTTOLIVE_API AAutoPickup : public AItemBase {
  GENERATED_BODY()

  UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Collision,
            meta = (AllowPrivateAccess))
  USphereComponent *SphereCollision;

protected:
  UFUNCTION(BlueprintGetter)
  FName GetItemID() const;

  virtual void BeginPlay() override;

public:
  AAutoPickup();

  UFUNCTION(BlueprintNativeEvent)
  void Collect(UInventoryComponent *InventoryComponent);
  virtual void Collect_Implementation(UInventoryComponent *InventoryComponent);

  UFUNCTION()
  virtual void OnOverlapBegin(class UPrimitiveComponent *newComp,
                              class AActor *OtherActor,
                              class UPrimitiveComponent *OtherComp,
                              int32 OtherBodyIndex, bool bFromSweep,
                              const FHitResult &SweepResult);

protected:
};