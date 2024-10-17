// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ColliderMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Collider.generated.h"

UCLASS()
class FIRSTPROJECT_API ACollider : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACollider();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	USphereComponent* SphereComponent;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, Category = "Movement")
	UColliderMovementComponent* OurMovementComponent;

	virtual UPawnMovementComponent* GetMovementComponent() const override;
	
	FORCEINLINE UStaticMeshComponent* MeshComponent1() const
	{
		return MeshComponent;
	}
	FORCEINLINE void SetMeshComponent(UStaticMeshComponent* Mesh)
	{
		this->MeshComponent = Mesh;
	}
	FORCEINLINE USphereComponent* SphereComponent1() const
	{
		return SphereComponent;
	}
	FORCEINLINE void SetSphereComponent(USphereComponent* Sphere)
	{
		this->SphereComponent = Sphere;
	}

	FORCEINLINE UCameraComponent* Camera1() const
	{
		return Camera;
	}
	FORCEINLINE void SetCamera(UCameraComponent* InCamera)
	{
		this->Camera = InCamera;
	}
	FORCEINLINE USpringArmComponent* SpringArm1() const
	{
		return SpringArm;
	}
	FORCEINLINE void SetSpringArm(USpringArmComponent* InSpringArm)
	{
		this->SpringArm = InSpringArm;
	}

private:

	void MoveForward(float input);
	void MoveRight(float input);

	void PitchCamera(float AxisValue);
	void YawCamera(float AxisValue);

	FVector2D CameraInput;
};
