// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/GameStateBase.h"
#include "InventoryItems/ItemBase.h"
#include "TTLGameState.generated.h"

class AItemBase;

UCLASS()
class THIRSTTOLIVE_API ATTLGameState : public AGameStateBase {
  GENERATED_BODY()
public:
  ATTLGameState();

  UDataTable *GetItemDB() const;

protected:
  UPROPERTY(EditDefaultsOnly)
  UDataTable *ItemDB;

  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
  float DistanceToDrop;

private:
  UFUNCTION(BlueprintCallable)
  void SpawnActorOnDrop(AActor *Actor, AItemBase *ItemToDrop,
                        bool GroundClamp) const;
};
