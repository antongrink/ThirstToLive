// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "TTLPlayerController.generated.h"

class AInteractable;
class UInventoryComponent;

UCLASS()
class THIRSTTOLIVE_API ATTLPlayerController : public APlayerController {
  GENERATED_BODY()

public:
  UInventoryComponent *GetInventory() const { return InventoryComponent; }

  UFUNCTION(BlueprintGetter)
  AInteractable *GetCurrentInteractable() const { return CurrentInteractable; }

  UFUNCTION(BlueprintCallable)
  void SetCurrentInteractable(AInteractable *NewInteractable) {
    CurrentInteractable = NewInteractable;
  }

protected:
  virtual void BeginPlay() override;
  virtual void SetupInputComponent() override;
  void Interact();

private:
  UPROPERTY()
  AInteractable *CurrentInteractable;

  UPROPERTY()
  UInventoryComponent *InventoryComponent;
};
