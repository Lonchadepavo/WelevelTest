// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomActor.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnValueChange, bool, ValueChanged);

UCLASS()
class ACustomActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACustomActor();

	FOnValueChange BooleanValueChangedEvent;

	// Small timer delegate to trigger the boolean change after 3 seconds since the game started.
	FTimerHandle TriggerBoolean;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(Replicated)
	bool bBoolean = false;

public:	
	UFUNCTION(Server, Reliable)
	void SetBooleanValue(const bool BooleanValue);

	void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;

};
