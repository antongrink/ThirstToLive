// Fill out your copyright notice in the Description page of Project Settings.

#include "Character/TTLPlayerController.h"
#include "InventoryItems/Interactable.h"
#include "ThirstToLiveMainCharacter.h"

void ATTLPlayerController::BeginPlay() {
  Super::BeginPlay();

  const auto TTLCharacter = Cast<AThirstToLiveMainCharacter>(GetPawn());
  if (TTLCharacter)
    InventoryComponent = TTLCharacter->GetInventory();
}

void ATTLPlayerController::SetupInputComponent() {
  Super::SetupInputComponent();

  InputComponent->BindAction("Interact", IE_Pressed, this,
                             &ATTLPlayerController::Interact);
}

void ATTLPlayerController::Interact() {
  if (CurrentInteractable)
    CurrentInteractable->Interact(InventoryComponent);
}
