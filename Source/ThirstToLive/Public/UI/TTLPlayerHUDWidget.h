// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"
#include "TTLPlayerHUDWidget.generated.h"

/**
 *
 */
UCLASS()
class THIRSTTOLIVE_API UTTLPlayerHUDWidget : public UUserWidget {
  GENERATED_BODY()

public:
  UFUNCTION(BlueprintCallable, Category = "UI")
  float GetHealthPercent() const;
};
