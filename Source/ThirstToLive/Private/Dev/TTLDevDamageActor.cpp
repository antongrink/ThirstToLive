// Fill out your copyright notice in the Description page of Project Settings.

#include "Dev/TTLDevDamageActor.h"
#include "Builders/SheetBuilder.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "MovieSceneSequenceID.h"
#include "TTLHealthComponent.h"
#include "ThirstToLiveMainCharacter.h"
#include "ThumbnailHelpers.h"

// Sets default values
ATTLDevDamageActor::ATTLDevDamageActor() {
  // Set this actor to call Tick() every frame.  You can turn this off to
  // improve performance if you don't need it.
  PrimaryActorTick.bCanEverTick = true;

  SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
  SetRootComponent(SceneComponent);

  SphereCollision = CreateDefaultSubobject<USphereComponent>("ShereComponent");
  SphereCollision->SetupAttachment(RootComponent);
  SphereCollision->SetSphereRadius(Radius);
}

// Called when the game starts or when spawned
void ATTLDevDamageActor::BeginPlay() {
  Super::BeginPlay();
  SphereCollision->OnComponentBeginOverlap.AddDynamic(
      this, &ATTLDevDamageActor::OnBeginOverlap);
  SphereCollision->OnComponentEndOverlap.AddDynamic(
      this, &ATTLDevDamageActor::OnEndOverlap);
}

// Called every frame
void ATTLDevDamageActor::Tick(float DeltaTime) {
  Super::Tick(DeltaTime);
  if (!GetWorld())
    return;
  DrawDebugSphere(GetWorld(), GetActorLocation(), Radius, 24, SphereColor);
}

void ATTLDevDamageActor::OnBeginOverlap(
    UPrimitiveComponent *OverlappedComponent, AActor *OtherActor,
    UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep,
    const FHitResult &SweepResult) {
  if (!GetWorld())
    return;

  FTimerDelegate BeginOverlapDelegate;
  TArray<AActor *> OverlappedActors;
  SphereCollision->GetOverlappingActors(OverlappedActors);
  auto TTLCharacter = Cast<AThirstToLiveMainCharacter>(OverlappedActors[0]);

  if (!TTLCharacter)
    return;

  BeginOverlapDelegate.BindUFunction(this, FName("ApplyDamage"), TTLCharacter);

  GetWorldTimerManager().SetTimer(DamageTimerHandle, BeginOverlapDelegate,
                                  DamageRate, true);
}

void ATTLDevDamageActor::ApplyDamage(
    AThirstToLiveMainCharacter *DamagedCharacter) {
  UGameplayStatics::ApplyDamage(DamagedCharacter, Damage, nullptr, this,
                                DamageType);
}

void ATTLDevDamageActor::OnEndOverlap(UPrimitiveComponent *OverlappedComponent,
                                      AActor *OtherActor,
                                      UPrimitiveComponent *OtherComp,
                                      int32 OtherBodyIndex) {
  if (!GetWorld())
    return;

  GetWorldTimerManager().ClearTimer(DamageTimerHandle);
}
