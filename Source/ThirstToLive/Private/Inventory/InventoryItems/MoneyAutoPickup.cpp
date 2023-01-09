#include "InventoryItems/MoneyAutoPickup.h"
#include "InventoryComponent.h"

AMoneyAutoPickup::AMoneyAutoPickup() {
  Super::ItemID = FName("money");
  Value = 1;
}

void AMoneyAutoPickup::Collect_Implementation(
    UInventoryComponent *InventoryComponent) {
  InventoryComponent->IncreaseMoney(Value);
  Destroy();
}
