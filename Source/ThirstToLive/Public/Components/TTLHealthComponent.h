// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "CoreMinimal.h"
#include "Preferences/PhysicsAssetEditorOptions.h"
#include "TTLHealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDeath)
DECLARE_MULTICAST_DELEGATE_OneParam(FOnHealthChanged, float)

    UCLASS(ClassGroup = (Custom),
           meta = (BlueprintSpawnableComponent)) class THIRSTTOLIVE_API
    UTTLHealthComponent : public UActorComponent {
  GENERATED_BODY()

public:
  UTTLHealthComponent();

  float GetHealth() const { return Health; }

  UFUNCTION(BlueprintCallable)
  bool IsDead() const { return FMath::IsNearlyZero(Health); }

  FOnDeath OnDeath;
  FOnHealthChanged OnHealthChanged;

  UFUNCTION(BlueprintCallable, Category = "Health")
  float GetHealthPercent() const { return Health / MaxHealth; }

protected:
  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Health",
            meta = (ClampMin = "0.0", ClampMax = "1000.0"))
  float MaxHealth = 100.0f;

  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal")
  bool AutoHeal = false;

  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal",
            meta = (ClampMin = "0.0"), meta = (EditCondition = "AutoHeal"))
  float HealUpdateTime = 1.0f;

  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal",
            meta = (ClampMin = "0.0"), meta = (EditCondition = "AutoHeal"))
  float HealDelay = 3.0f;

  UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Heal",
            meta = (ClampMin = "0.0"), meta = (EditCondition = "AutoHeal"))
  float HealModifier = 1.0f;

  virtual void BeginPlay() override;

private:
  FTimerHandle AutoHealTimerHandle;

  float Health = 0.0f;

  UFUNCTION()
  void OnTakeAnyDamageHandle(AActor *DamagedActor, float Damage,
                             const class UDamageType *DamageType,
                             class AController *InstigatedBy,
                             AActor *DamageCauser);

  void HealUpdate();
  void SetHealth(float NewHealth);

public:
  void DecreaseHealth(float HealthDecrease) {
    SetHealth(Health - HealthDecrease);
  }
};
