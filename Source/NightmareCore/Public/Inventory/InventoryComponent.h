#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "Inventory/ItemSlot.h"
#include "Inventory/Item.h"

#include "InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnInventoryContentsChangedSignature, TArray<UItem*>, ItemList, TArray<FItemSlotArray>, ItemSlotList);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnInventorySizeChangedSignature, FIntPoint, NewSize);

UCLASS(Blueprintable, BlueprintType)
class UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, Category="Inventory")
	FOnInventoryContentsChangedSignature OnInventoryContentsChanged;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, Category="Inventory")
	FOnInventorySizeChangedSignature OnInventorySizeChanged;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Inventory")
	TArray<UItem*> ItemList;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Inventory")
	TArray<FItemSlotArray> ItemSlotRows;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Inventory")
	FIntPoint InventorySize = FIntPoint(4,3);

	UFUNCTION(BlueprintCallable, Category="Inventory")
	void AddItem(UItem* Item);

	UFUNCTION(BlueprintCallable, Category="Inventory")
	void RemoveItem(UItem* Item);

	UFUNCTION(BlueprintPure, BlueprintCallable, Category="Inventory")
	bool CanItemFit(UItem* Item, FIntPoint& OutFirstValidLocation);

	UFUNCTION(BlueprintPure, BlueprintCallable, Category="Inventory")
	bool CanItemFitAtLocation(FIntPoint ItemSize, FIntPoint Location);

	UFUNCTION(BlueprintPure, BlueprintCallable, Category="Inventory")
	UItem* GetItemFromSlot(FIntPoint Location);

	UFUNCTION(BlueprintPure, BlueprintCallable, Category="Inventory")
	bool IsValidSlot(FIntPoint Location);
	
};