#pragma once

#include "CoreMinimal.h"
#include "Interface.h"
#include "ItemInstance.h"
#include "UsableInterface.h"

#include "EquippableInterface.generated.h"

UINTERFACE(MinimalAPI)
class UEquippableInterface 
	: public UUsableInterface
{
	GENERATED_BODY()
};

class RPGBASE_API IEquippableInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "RPG Base|Item|Equippable")
	bool CanEquip(AActor* TargetWearer, FItemInstance& ItemInstance, FName TargetSocket = TEXT(""), int32 TargetSlot = -1);
	virtual bool CanEquip_Implementation(AActor* TargetWearer, FItemInstance& ItemInstance, FName TargetSocket = TEXT(""), int32 TargetSlot = -1) = 0;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "RPG Base|Item|Equippable")
	void Equip(AActor* TargetWearer, FItemInstance& ItemInstance, FName TargetSocket = TEXT(""), int32 TargetSlot = -1);
	virtual void Equip_Implementation(AActor* TargetWearer, FItemInstance& ItemInstance, FName TargetSocket = TEXT(""), int32 TargetSlot = -1) = 0;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "RPG Base|Item|Equippable")
	void UnEquip(AActor* Wearer, FItemInstance& ItemInstance, FName Socket, int32 Slot);
	virtual void UnEquip_Implementation(AActor* Wearer, FItemInstance& ItemInstance, FName Socket = TEXT(""), int32 Slot = -1) = 0;
};
