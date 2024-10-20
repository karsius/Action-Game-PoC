// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingPlatform.generated.h"

UCLASS()
class FIRSTPROJECT_API AFloatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingPlatform();

	/** mesh for platform */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Platform")
	UStaticMeshComponent* Mesh;

	//creeate start and end points for our platform
	UPROPERTY(EditAnywhere)
	FVector StartPoint;

	//create visualization widget to manipulate endpoint vector in the UE editor
	UPROPERTY(EditAnywhere, meta = (MakeEditWidget = "true"))
	FVector EndPoint;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform")
	float InterpSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform")
	float InterpTime;
	
	FTimerHandle InterpTimer;

	//is the platform interpolating
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Platform")
	bool bInterping;

	float Distance;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ToggleInterping();

	void SwapVectors(FVector& VecOne, FVector& VecTwo);

};
