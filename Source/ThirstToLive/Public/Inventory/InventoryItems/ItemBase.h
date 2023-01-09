#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemBase.generated.h"

class UInventoryComponent;

UCLASS(Abstract)
class THIRSTTOLIVE_API AItemBase : public AActor {
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintCallable)
  void Rotate();

  UFUNCTION(BlueprintCallable)
  FIntPoint GetDimensions() const;

  UFUNCTION(BlueprintGetter)
  UMaterialInterface *GetIconImage() const;

  UFUNCTION(BlueprintGetter)
  bool IsRotated() const { return IsImageRotated; }

protected:
  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Base Item Data",
            meta = (ClampMin = 1))
  FName ItemID;

  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Base Item Data")
  FText Name;

  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Base Item Data")
  int32 Weight;

  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Base Item Data")
  UMaterialInterface *Thumbnail;

  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Base Item Data")
  UMaterialInterface *RotatedThumbnail;

  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Base Item Data")
  bool IsImageRotated = false;

  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Base Item Data",
            meta = (MultiLine = true))
  FText Description;

  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Base Item Data")
  UStaticMeshComponent *PickupMesh;

  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Base Item Data")
  bool bStackable;

  UPROPERTY(BlueprintReadOnly, meta = (EditCondition = "bStackable"),
            meta = (ClampMin = 1))
  uint8 Count;

  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (ClampMin = 1))
  FIntPoint Dimensions;

private:
  friend class UInventoryComponent;
};
