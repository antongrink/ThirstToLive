#include "InventoryItems/Interactable.h"
#include "InventoryComponent.h"

AInteractable::AInteractable() { Action = "interact"; }

void AInteractable::Interact_Implementation(
    UInventoryComponent *InventoryComponent) {
  return;
}

FString AInteractable::GetInteractText() const {
  return FString::Printf(TEXT("%s: Press F to %s"), *Name.ToString(), *Action);
}