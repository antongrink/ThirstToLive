// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SphereComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TTLDevDamageActor.generated.h"

class AThirstToLiveMainCharacter;
UCLASS()
class THIRSTTOLIVE_API ATTLDevDamageActor : public AActor {
  GENERATED_BODY()

public:
  // Sets default values for this actor's properties
  ATTLDevDamageActor();

  UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
  USceneComponent *SceneComponent;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float Radius = 300.0f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FColor SphereColor = FColor::Blue;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  float Damage = 10.0f;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  bool DoFullDamage = false;

  UPROPERTY(EditDefaultsOnly, Category = "Collision")
  USphereComponent *SphereCollision;

  UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage",
            meta = (ClampMin = 0.01f));
  float DamageRate = 0.1f;

protected:
  // Called when the game starts or when spawned
  virtual void BeginPlay() override;

public:
  // Called every frame
  virtual void Tick(float DeltaTime) override;

private:
  UFUNCTION()
  void OnBeginOverlap(UPrimitiveComponent *OverlappedComponent,
                      AActor *OtherActor, UPrimitiveComponent *OtherComp,
                      int32 OtherBodyIndex, bool bFromSweep,
                      const FHitResult &SweepResult);

  UFUNCTION()
  void OnEndOverlap(UPrimitiveComponent *OverlappedComponent,
                    AActor *OtherActor, UPrimitiveComponent *OtherComp,
                    int32 OtherBodyIndex);

  FTimerHandle DamageTimerHandle;

  UFUNCTION()
  void ApplyDamage(AThirstToLiveMainCharacter *DamagedCharacter);

  TSubclassOf<UDamageType> DamageType;
};
