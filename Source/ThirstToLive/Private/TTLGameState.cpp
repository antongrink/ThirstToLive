// Fill out your copyright notice in the Description page of Project Settings.

#include "TTLGameState.h"

ATTLGameState::ATTLGameState() {
  static ConstructorHelpers::FObjectFinder<UDataTable> BP_ItemDB(
      TEXT("/Script/Engine.DataTable'/Game/Inventory/Data/ItemsDB.ItemsDB'"));
  ItemDB = BP_ItemDB.Object;
}

UDataTable *ATTLGameState::GetItemDB() const { return ItemDB; }

void ATTLGameState::SpawnActorOnDrop(AActor *Actor, AItemBase *ItemToDrop,
                                     bool GroundClamp) const {
  FVector ItemDropLocation = Actor->GetActorLocation() +
                             Actor->GetActorForwardVector() * DistanceToDrop;

  if (GroundClamp) {
    FHitResult HitResult = FHitResult(ForceInit);
    FCollisionQueryParams QueryParams;
    QueryParams.AddIgnoredActor(this);

    bool bIsHit = GetWorld()->LineTraceSingleByChannel(
        HitResult, ItemDropLocation, ItemDropLocation - FVector(0, 0, 1000),
        ECC_Visibility, QueryParams);

    if (bIsHit) {
      ItemDropLocation = HitResult.Location + FVector(0, 0, 200);
    }

    ItemToDrop->SetActorLocation(ItemDropLocation);
    ItemToDrop->SetActorHiddenInGame(false);
    ItemToDrop->SetActorEnableCollision(true);
    ItemToDrop->SetActorTickEnabled(true);
  }
}
