#include "Components/TTLHealthComponent.h"
#include "Engine/World.h"
#include "TimerManager.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthComponent, All, All)

UTTLHealthComponent::UTTLHealthComponent() {
  PrimaryComponentTick.bCanEverTick = false;
}

void UTTLHealthComponent::BeginPlay() {
  Super::BeginPlay();

  checkf(MaxHealth > 0.0f, TEXT("Max Health = 0!"));

  SetHealth(MaxHealth);

  AActor *ComponentOwner = GetOwner();
  if (ComponentOwner)
    ComponentOwner->OnTakeAnyDamage.AddDynamic(
        this, &UTTLHealthComponent::OnTakeAnyDamageHandle);
}

void UTTLHealthComponent::OnTakeAnyDamageHandle(AActor *DamagedActor,
                                                float Damage,
                                                const UDamageType *DamageType,
                                                AController *InstigatedBy,
                                                AActor *DamageCauser) {
  if (Damage <= 0.0f || IsDead() && !GetWorld())
    return;

  SetHealth(Health - Damage);
  GetWorld()->GetTimerManager().ClearTimer(AutoHealTimerHandle);

  if (IsDead()) {
    OnDeath.Broadcast();
  } else if (AutoHeal) {
    GetOwner()->GetWorldTimerManager().SetTimer(
        AutoHealTimerHandle, this, &UTTLHealthComponent::HealUpdate,
        HealUpdateTime, true, HealDelay);
  }

  UE_LOG(LogHealthComponent, Display, TEXT("Damage: %f"), Damage);
}

void UTTLHealthComponent::HealUpdate() {
  SetHealth(Health + HealModifier);
  OnHealthChanged.Broadcast(Health);

  if (FMath::IsNearlyEqual(Health, MaxHealth) && GetWorld()) {
    GetWorld()->GetTimerManager().ClearTimer(AutoHealTimerHandle);
  }
}

void UTTLHealthComponent::SetHealth(float NewHealth) {
  Health = FMath::Clamp(NewHealth, 0.0f, MaxHealth);
  OnHealthChanged.Broadcast(Health);
}
