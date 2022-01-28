// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
//#include <Runtime/CoreUObject/Public/UObject/ObjectMacros.h>
#include "Item.generated.h"


UCLASS(Abstract, BlueprintType, Blueprintable, EditInLineNew, DefaultToInstanced)
class INVENTORYSYSTEM_API UItem : public UObject
{
	GENERATED_BODY()

public:

	UItem();

	virtual class UWorld* GetWorld() const { return World; };

	UPROPERTY(Transient)
	class UWorld* World;

	//The text for using the item
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	FText UseActionText;

	//The mesh to display for this items pickup
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	class UStaticMesh* PickUpMesh;

	//The thumbnail for this item
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Item")
	class UTexture2D* Thumbnail;

	//The display name for this item in the inventory
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
	FText ItemDisplayName;

	//An extra description for the item
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (MultiLine = true))
	FText ItemDescription;

	//The weight of the item
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
	float Weight;

	//The inventory that owns the item
	UPROPERTY()
	class UInventoryComponent* OwningInventory;

	//An abstract version of the use function
	virtual void Use(class AInventorySystemCharacter* Character);


	
	UFUNCTION(BlueprintImplementableEvent)
	void OnUse(class AInventorySystemCharacter* Character);

};	
