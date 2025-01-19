// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Engine/DataTable.h"
#include "Types.generated.h"

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Aim_State UMETA(DisplayName = "AimState"),
	AimWalk_State UMETA(DisplayName = "AimWalkState"),
	Walk_State UMETA(DisplayName = "WalkState"),
	Run_State UMETA(DisplayName = "RunState"),
	SprintRun_State UMETA(DisplayName = "SprintRunState"),
	};

USTRUCT(BlueprintType)
struct FCharacterSpeed
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Movement")
	float AimSpeedNormal = 300.f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Movement")
	float WalkSpeedNormal = 200.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Movement")
	float RunSpeedNormal = 600.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Movement")
	float AimSpeedWalk = 100.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Movement")
	float SprintRunSpeedRun = 1200.0f;
};

USTRUCT(BlueprintType)
struct FProjectileInfo
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSetting")
	TSubclassOf<class AProjectileDefault> Projectile = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSetting")
	UStaticMesh* ProjectileStaticMesh = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSetting")
	FTransform ProjectileStaticMeshOffset = FTransform();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSetting")
	UParticleSystem* ProjectileTrailFx = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSetting")
	FTransform ProjectileTrailFxOffset = FTransform();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSetting")
	float ProjectileDamage = 20.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSetting")
	float ProjectileLifeTime = 20.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSetting")
	float ProjectileInitSpeed = 2000.0f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX")
	TMap<TEnumAsByte<EPhysicalSurface>, UMaterialInterface*> HitDecals;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX")
	USoundBase* HitSound = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX")
	TMap<TEnumAsByte<EPhysicalSurface>, UParticleSystem*> HitFXs;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Explode")
	UParticleSystem* ExploseFX = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Explode")
	USoundBase* ExploseSound = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Explode")
	float ProjectileMaxRadiusDamage = 200.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Explode")
	float ProjectileMinRadiusDamage = 200.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Explode")
	float ExploseMaxDamage = 40.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Explode")
	float ExplodeFalloffCoef = 1.0f;
	
	//Timer add
};

USTRUCT(BlueprintType)
struct FWeaponDispersion
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
	float Aim_StateDispersionAimMax = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
	float Aim_StateDispersionAimMin = 0.3f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
	float Aim_StateDispersionAimRecoil = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
	float Aim_StateDispersionReduction = 0.3f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
	float AimWalk_StateDispersionAimMax = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
	float AimWalk_StateDispersionAimMin = 0.1f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
	float AimWalk_StateDispersionAimRecoil = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
	float AimWalk_StateDispersionReduction = 0.4f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
	float Walk_StateDispersionAimMax = 5.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
	float Walk_StateDispersionAimMin = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
	float Walk_StateDispersionAimRecoil = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
	float Walk_StateDispersionReduction = 0.2f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
	float Run_StateDispersionAimMax = 10.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
	float Run_StateDispersionAimMin = 4.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
	float Run_StateDispersionAimRecoil = 1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
	float Run_StateDispersionReduction = 0.1f;
};
USTRUCT(BlueprintType)
struct FAnimationWeaponInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim Char")
	UAnimMontage* AnimCharFire = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim Char")
	UAnimMontage* AnimCharFireAim = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim Char")
	UAnimMontage* AnimCharReload = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim Char")
	UAnimMontage* AnimCharReloadAim = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim Weapon")
	UAnimMontage* AnimWeaponReload = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim Weapon")
	UAnimMontage* AnimWeaponReloadAim = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim Weapon")
	UAnimMontage* AnimWeponFire = nullptr;
};

USTRUCT(BlueprintType)
struct FDropMeshInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DropMesh")
	UStaticMesh* DropMesh = nullptr;
	//0.0f immediatly drop
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DropMesh")
	float DropMeshTime = -1.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DropMesh")
	float DropMeshLifeTime = 5.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DropMesh")
	FTransform DropMeshOffset = FTransform();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DropMesh")
	FVector DropMeshImpulseDir = FVector(0.0f);
	float PowerImpulse = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DropMesh")
	float ImpulseRandomDispersion = 0.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DropMesh")
	float CustomMass = 0.0f;

};



USTRUCT(BlueprintType)
struct FWeaponInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Class")
	TSubclassOf<class AWeaponDefault> WeaponClass = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	float RateOfFire = 0.5f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	float ReloadTime = 2.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	int32 MaxRound = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "State")
	int32 NumberProjectileByShot = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dispersion")
	FWeaponDispersion DispersionWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundBase* SoundFireWeapon = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
	USoundBase* SoundReloadWeapon = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FX")
	UParticleSystem* EffectFireWeapon = nullptr;
	//if null use trace logic (TSubclassOf<class AProjectileDefault> Projectile = nullptr)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectile")
	FProjectileInfo ProjectileSetting;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	float WeaponDamage = 20.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace")
	float DistanceTrace = 2000.f;
	//on decal on all?

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HitEffect")
	UDecalComponent* DecalHit = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim")
	FAnimationWeaponInfo AnimWeaponInfo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	FDropMeshInfo ClipDropMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	FDropMeshInfo ShellBullets;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim")
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Anim")
	//UAnimMontage* AnimCharReload = nullptr;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	//UStaticMesh* MagazineDrop = nullptr;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	//UStaticMesh* ShellBullets = nullptr;
};

USTRUCT(BlueprintType)
struct FAddicionalWeaponInfo
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WeaponStats")
	int32 Round = 10;
};

UCLASS()
class TDS_API UTypes : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
};