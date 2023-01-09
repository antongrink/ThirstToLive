#pragma once

#include "CoreMinimal.h"
#include "Interactable.h"
#include "ManPickup.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable, BlueprintType)
class THIRSTTOLIVE_API AManPickup : public AInteractable {
  GENERATED_BODY()

public:
  AManPickup();

  UFUNCTION(BlueprintCallable)
  void
  Interact_Implementation(UInventoryComponent *InventoryComponent) override;
};
