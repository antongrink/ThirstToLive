#include "InventoryItems/ItemBase.h"
#include "InventoryComponent.h"

void AItemBase::Rotate() { IsImageRotated = !IsImageRotated; }

FIntPoint AItemBase::GetDimensions() const {
  if (!IsImageRotated)
    return Dimensions;

  return FIntPoint(Dimensions.Y, Dimensions.X);
}

UMaterialInterface *AItemBase::GetIconImage() const {
  if (IsImageRotated)
    return RotatedThumbnail;

  return Thumbnail;
}
