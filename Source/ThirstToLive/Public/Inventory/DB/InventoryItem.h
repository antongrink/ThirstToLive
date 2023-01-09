﻿#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "InventoryItem.generated.h"

USTRUCT(BlueprintType)
struct FInventoryItem : public FTableRowBase {
  GENERATED_BODY()

public:
  FInventoryItem();

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FName ItemID;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FText Name;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int32 Weight;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  int32 Value;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  UTexture2D *Thumbnail;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  FText Description;

  UPROPERTY(EditAnywhere, BlueprintReadWrite)
  bool bStackable;

  UPROPERTY(EditAnywhere, BlueprintReadWrite,
            meta = (EditCondition = "!bStackable"),
            meta = (ClampMin = 1)) // add condition specifier
  uint8 Count;

  bool operator==(const FInventoryItem &OtherItem) const {
    if (ItemID == OtherItem.ItemID)
      return true;
    return false;
  }
};