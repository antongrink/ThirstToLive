// Fill out your copyright notice in the Description page of Project Settings.

#include "InventoryComponent.h"
#include "InventoryItems/Interactable.h"
#include "TTLGameState.h"

void UInventoryComponent::RemoveItem(AItemBase *ItemToRemove) {
  if (!ItemToRemove)
    return;
  for (int i = 0; i < Inventory.Num(); ++i) {
    if (Inventory[i] == ItemToRemove)
      Inventory[i] = nullptr;
  }

  OnInventoryChanged.Broadcast();
}

TMap<AItemBase *, FIntPoint> UInventoryComponent::GetAllItems() const {
  TMap<AItemBase *, FIntPoint> AllItems;
  int index{0};
  for (auto const &TempItem : Inventory) {
    if (TempItem && !AllItems.Contains(TempItem)) {
      AllItems.Add(TempItem, IndexToTile(index));
    }
    ++index;
  }

  return AllItems;
}

UInventoryComponent::UInventoryComponent() { InventoryWeightLimit = 500; }

int32 UInventoryComponent::GetInventoryWeight() // TODO:Поменять под
                                                // пространственный инвентарь
{
  int32 Weight = 0;
  for (auto &Item : Inventory) {
    Weight += Item->Weight;
  }

  return Weight;
}

void UInventoryComponent::BeginPlay() {
  Super::BeginPlay();
  Inventory.SetNum(InventoryColumns * InventoryRows);
}

bool UInventoryComponent::TryAddItemToInventory(AItemBase *Item) {
  if (!Item)
    return false;

  if (Item->bStackable) {
    AItemBase *UpdItem = *Inventory.FindByPredicate(
        [&](const AItemBase *Data) { return Data->ItemID == Item->ItemID; });
    if (UpdItem) {
      UpdItem->Count++;
      return true;
    }
  }

  for (unsigned int i = 0; i < 2;
       i++) // Two iteration for check item on inserting with other orientation
  {
    for (uint8 InvIndex{0}; InvIndex < Inventory.Num(); ++InvIndex) {
      if (IsRoomAvaliable(InvIndex, Item) /*&& GetInventoryWeight() + Item->Weight <= InventoryWeightLimit*/)
			{
        AddItemAt(Item, InvIndex);
        return true;
      }
    }
    Item->Rotate(); // Try other orientation
  }

  return false;
}

bool UInventoryComponent::IsRoomAvaliable(int TopLeftIndex,
                                          AItemBase *Item) const {
  const FIntPoint StartTile = IndexToTile(TopLeftIndex);
  const FIntPoint Dimensions = Item->GetDimensions();
  const auto XItemCoord = StartTile.X; //////Coordination in tiles if invenotry
  const auto YItemCoord = StartTile.Y;
  const auto ItemDimensionH = Dimensions.X - 1;
  const auto ItemDimensionV = Dimensions.Y - 1;
  for (int i = XItemCoord; i <= ItemDimensionH + XItemCoord; ++i) {
    for (int j = YItemCoord; j <= ItemDimensionV + YItemCoord; ++j) {
      if (!IsTileValid(i, j))
        return false;

      bool ValidIndex = true;
      if (GetItemAtIndex(TileToIndex(i, j), ValidIndex))
        return false;

      if (!ValidIndex)
        return false;
    }
  }

  return true;
}

FIntPoint UInventoryComponent::IndexToTile(int Index) const {
  checkf(InventoryColumns, TEXT("InventoryColumns = %i!"), InventoryColumns);

  return FIntPoint(Index % InventoryColumns, Index / InventoryColumns);
}

bool UInventoryComponent::IsTileValid(int Tile_X, int Tile_Y) const {
  return Tile_X >= 0 && Tile_Y >= 0 && Tile_X < InventoryColumns &&
         Tile_Y < InventoryRows;
}

uint8 UInventoryComponent::TileToIndex(int Tile_X, int Tile_Y) const {
  return Tile_Y * InventoryColumns + Tile_X;
}

void UInventoryComponent::AddItemAt(AItemBase *ItemToAdd, int TopLeftIndex) {
  const FIntPoint StartTile = IndexToTile(TopLeftIndex);
  const FIntPoint Dimensions = ItemToAdd->GetDimensions();
  const auto XItemCoord = StartTile.X;
  const auto YItemCoord = StartTile.Y;
  const auto ItemDimensionH = Dimensions.X - 1;
  const auto ItemDimensionV = Dimensions.Y - 1;
  for (int i = XItemCoord; i <= ItemDimensionH + XItemCoord; i++) {
    for (int j = YItemCoord; j <= ItemDimensionV + YItemCoord; j++) {
      Inventory[TileToIndex(i, j)] = ItemToAdd;
    }
  }
  OnInventoryChanged.Broadcast();
}

AItemBase *UInventoryComponent::GetItemAtIndex(int Index,
                                               bool &ValidIndex) const {
  if (!Inventory.IsValidIndex(Index)) {
    ValidIndex = false;
    return nullptr;
  }
  return Inventory[Index];
}
