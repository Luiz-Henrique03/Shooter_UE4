// Fill out your copyright notice in the Description page of Project Settings.


#include "GunActor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

// Sets default values
AGunActor::AGunActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	GunMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Gun"));
	GunMesh->SetupAttachment(Root);

}

void AGunActor::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, GunMesh, TEXT("b_gun_muzzleflash"));
	UGameplayStatics::SpawnSoundAttached(FireSound, GunMesh, TEXT("b_gun_muzzleflash"));

	FHitResult Hit;
	FVector ShootDirection;

	if (GunTrace(Hit,ShootDirection)) {
	
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactEffect, Hit.Location, ShootDirection.Rotation());
		UGameplayStatics::SpawnSoundAtLocation(GetWorld(), ImpactSound, Hit.Location);

		AActor* HitActor = Hit.GetActor();

		if ( HitActor != nullptr) {
			FPointDamageEvent DamageEvent(Damage, Hit, ShootDirection, nullptr);
			AController* OwnerController = GetOwnerController();
			HitActor->TakeDamage(Damage, DamageEvent, OwnerController, this);
		}
	}
	
}

// Called when the game starts or when spawned
void AGunActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGunActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AGunActor::GunTrace(FHitResult& Hit, FVector& ShootDirection)
{

	AController* OwnerController = GetOwnerController();
	if (OwnerController == nullptr) return false;

	FVector Location;
	FRotator Rotation;

	OwnerController->GetPlayerViewPoint(Location, Rotation);
	FVector End = Location + Rotation.Vector() * MaxRange;

	ShootDirection = -Rotation.Vector();

	//DrawDebugCamera(GetWorld(), Location, Rotation, 90,2,FColor::White,true);
	//DrawDebugPoint(GetWorld(), Location, 20, FColor::White, true);
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());

	return GetWorld()->LineTraceSingleByChannel(Hit, Location, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
}

AController* AGunActor::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr) return nullptr;

	return OwnerPawn->GetController();
	
}

