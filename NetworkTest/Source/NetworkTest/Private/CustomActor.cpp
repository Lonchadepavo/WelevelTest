#include "CustomActor.h"
#include "Net/UnrealNetwork.h"

// Sets default values
ACustomActor::ACustomActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ACustomActor::BeginPlay()
{
	Super::BeginPlay();

	FTimerDelegate Delegate;
	Delegate.BindUFunction(this, "SetBooleanValue", true);
	GetWorld()->GetTimerManager().SetTimer(TriggerBoolean, Delegate, 3.0f, false);
}

void ACustomActor::SetBooleanValue_Implementation(const bool BooleanValue)
{
	bBoolean = BooleanValue;
	BooleanValueChangedEvent.Broadcast(BooleanValue);
}

void ACustomActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ACustomActor, bBoolean);
}

