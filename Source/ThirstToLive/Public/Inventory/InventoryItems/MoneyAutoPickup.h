#pragma once

#include "AutoPickup.h"
#include "CoreMinimal.h"
#include "MoneyAutoPickup.generated.h"

class UInventoryComponent;

UCLASS(Blueprintable, BlueprintType)
class THIRSTTOLIVE_API AMoneyAutoPickup : public AAutoPickup {
  GENERATED_BODY()

public:
  AMoneyAutoPickup();

  void Collect_Implementation(UInventoryComponent *InventoryComponent) override;

private:
  UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Money Pickup",
            meta = (AllowPrivateAccess))
  int32 Value;
};
