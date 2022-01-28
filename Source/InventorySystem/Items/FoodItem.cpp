// Fill out your copyright notice in the Description page of Project Settings.


#include "FoodItem.h"
#include "InventoryComponent.h"
#include "InventorySystemCharacter.h"



void UFoodItem::Use(AInventorySystemCharacter* Character)
{
	//Heal the character by the item's Health to heal variable
	if (Character)
	{
		Character->Health += HealthToHeal;

		//If the item has been used then remove it from the inventory
		if (OwningInventory)
		{
			OwningInventory->RemoveItem(this);
		}
	}
}