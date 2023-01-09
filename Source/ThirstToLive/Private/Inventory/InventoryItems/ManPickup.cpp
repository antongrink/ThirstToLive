#include "InventoryItems/ManPickup.h"
#include "InventoryComponent.h"

AManPickup::AManPickup() {
  PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");
  RootComponent = Cast<USceneComponent>(PickupMesh);

  ItemID = FName("No ID");

  Super::Name = FText::FromString("Item");
  Super::Action = "pickup";
}

void AManPickup::Interact_Implementation(
    UInventoryComponent *InventoryComponent) {
  Super::Interact_Implementation(InventoryComponent);

  if (InventoryComponent->TryAddItemToInventory(this)) {
    SetActorHiddenInGame(true);
    SetActorEnableCollision(false);
    SetActorTickEnabled(false);
  }
}
