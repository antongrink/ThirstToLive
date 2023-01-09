// Fill out your copyright notice in the Description page of Project Settings.

#include "UI/TTLPlayerHUDWidget.h"
#include "Components/TTLHealthComponent.h"

float UTTLPlayerHUDWidget::GetHealthPercent() const {
  const auto Player = GetOwningPlayerPawn();
  if (!Player)
    return 0.0f;

  const auto Component =
      Player->GetComponentByClass(UTTLHealthComponent::StaticClass());
  const auto HealthComponent = Cast<UTTLHealthComponent>(Component);
  if (!HealthComponent)
    return 0.0f;

  return HealthComponent->GetHealthPercent();
}
