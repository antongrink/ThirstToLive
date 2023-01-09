#include "InventoryItems/AutoPickup.h"

#include "EnvironmentQuery/EnvQueryTypes.h"
#include "InventoryComponent.h"
#include "MovieSceneSequenceID.h"
#include "ThirstToLiveMainCharacter.h"

AAutoPickup::AAutoPickup() {
  SphereCollision =
      CreateDefaultSubobject<USphereComponent>("Sphere Collision");
  SphereCollision->SetSphereRadius(32);

  PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>("PickupMesh");
  SphereCollision->SetupAttachment(PickupMesh);

  ItemID = FName("No ID");
}

void AAutoPickup::BeginPlay() {
  Super::BeginPlay();
  SphereCollision->OnComponentBeginOverlap.AddDynamic(
      this, &AAutoPickup::OnOverlapBegin);
}

void AAutoPickup::Collect_Implementation(
    UInventoryComponent *InventoryComponent) {
  if (InventoryComponent->TryAddItemToInventory(this)) {
    SetActorHiddenInGame(true);
    SetActorEnableCollision(false);
    SetActorTickEnabled(false);
  }
}

FName AAutoPickup::GetItemID() const { return ItemID; }

void AAutoPickup::OnOverlapBegin(UPrimitiveComponent *newComp,
                                 AActor *OtherActor,
                                 UPrimitiveComponent *OtherComp,
                                 int32 OtherBodyIndex, bool bFromSweep,
                                 const FHitResult &SweepResult) {
  auto const ATLCharacter = Cast<AThirstToLiveMainCharacter>(OtherActor);
  if (ATLCharacter) {
    Collect(ATLCharacter->GetInventory());
  }
}
