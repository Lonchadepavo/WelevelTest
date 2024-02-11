// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "CheckBooleanAsync.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnValueChangeDetect, bool, ValueChanged);

UCLASS()
class UCheckBooleanAsync : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FOnValueChangeDetect ValueChangedEvent;

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true", WorldContext = "WorldContextObject", DefaultToSelf = "ListenActor"), Category = "Flow Control")
	static UCheckBooleanAsync* WaitForBooleanChange(AActor* ListenActor, ACustomActor* TargetActor);

	virtual void Activate() override;

	UFUNCTION()
	void OnValueChanged(bool ValueChanged);

private:
	UPROPERTY()
	AActor* ListenActor;

	UPROPERTY()
	class ACustomActor* TargetActor;

};
