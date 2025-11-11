// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "firstperson415Projectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS(config=Game)
class Afirstperson415Projectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
		USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
		UProjectileMovementComponent* ProjectileMovement;

		// Mesh for the projectile
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* ballMesh;

		/// Base material for the projectile
	UPROPERTY(EditAnywhere)
		UMaterial* baseMat;

		// Random color for each projectile
	UPROPERTY()
		FLinearColor randColor;

		// Material for the projectile
	UPROPERTY(EditAnywhere)
		UMaterialInterface* projMat;

		// Dynamic material instance for the projectile
	UPROPERTY()
		UMaterialInstanceDynamic* dmiMat;


public:
	Afirstperson415Projectile();

protected:
	virtual void BeginPlay();

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }
};

