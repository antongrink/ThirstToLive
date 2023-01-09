// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "TTLGameHUD.generated.h"

/**
 *
 */
UCLASS()
class THIRSTTOLIVE_API ATTLGameHUD : public AHUD {
  GENERATED_BODY()

  virtual void BeginPlay() override;

protected:
  UPROPERTY(EditDefaultsOnly, Category = "UI")
  TSubclassOf<UUserWidget> PlayerHUDWidgetClass;

private:
};
