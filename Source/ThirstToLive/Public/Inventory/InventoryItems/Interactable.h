#pragma once

#include "CoreMinimal.h"

#include "Interactable.generated.h"
#include "ItemBase.h"

class UInventoryComponent;

UCLASS(Blueprintable, BlueprintType)
class THIRSTTOLIVE_API AInteractable : public AItemBase {
  GENERATED_BODY()

protected:
  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite,
            Category = "Interactable Item Data")
  FString Action;

public:
  AInteractable();

  UFUNCTION(BlueprintNativeEvent)
  void Interact(UInventoryComponent *InventoryComponent);
  virtual void Interact_Implementation(UInventoryComponent *InventoryComponent);

  UFUNCTION(BlueprintGetter)
  FString GetInteractText() const;
};
