// Fill out your copyright notice in the Description page of Project Settings.


#include "CheckBooleanAsync.h"
#include "CustomActor.h"

void UCheckBooleanAsync::Activate()
{
  Super::Activate();
  if (!TargetActor) return;

  TargetActor->BooleanValueChangedEvent.AddDynamic(this, &UCheckBooleanAsync::OnValueChanged);
}

UCheckBooleanAsync* UCheckBooleanAsync::WaitForBooleanChange(AActor* _ListenActor, ACustomActor* _TargetActor)
{
  if (!_TargetActor) return nullptr;
  if (!_ListenActor) return nullptr;

  UCheckBooleanAsync* Task = NewObject<UCheckBooleanAsync>();
  Task->ListenActor = _ListenActor;
  Task->TargetActor = _TargetActor;
  Task->RegisterWithGameInstance(_ListenActor->GetWorld());

  return Task;
}

void UCheckBooleanAsync::OnValueChanged(bool ValueChanged)
{
  ValueChangedEvent.Broadcast(ValueChanged);
}
