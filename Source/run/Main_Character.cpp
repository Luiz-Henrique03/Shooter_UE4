// Fill out your copyright notice in the Description page of Project Settings.


#include "Main_Character.h"
#include "Components/CapsuleComponent.h"
#include "KillEmAllGameModeBase.h"
#include "GetPowerUp.h"
#include "GunActor.h"

// Sets default values
AMain_Character::AMain_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMain_Character::BeginPlay()
{
	Super::BeginPlay();

	Health = MaxHealth;

	Gun = GetWorld()->SpawnActor<AGunActor>(GunClass);
	GetMesh()->HideBoneByName(TEXT("Weapon"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("weaponSocket"));
	Gun->SetOwner(this);
	

}

bool AMain_Character::IsDead() const
{
	return Health <= 0;
}

float AMain_Character::GetPercentHealth() const
{
	return Health / MaxHealth;
}

// Called every frame
void AMain_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

float AMain_Character::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float DamageAplied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	DamageAplied = FMath::Min(Health, DamageAplied);
	Health -= DamageAplied;
	UE_LOG(LogTemp, Warning, TEXT("Health left: %f "), Health);

	if (IsDead()) {
		AKillEmAllGameModeBase* GameMode = GetWorld()->GetAuthGameMode<AKillEmAllGameModeBase>();
			if (GameMode != nullptr) {
				GameMode->PawnKilled(this);
			}
		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		
	}

	return DamageAplied;
}

// Called to bind functionality to input
void AMain_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMain_Character::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveBack"), this, &AMain_Character::MoveBack);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMain_Character::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("MoveLeft"), this, &AMain_Character::MoveLeft);
	PlayerInputComponent->BindAxis(TEXT("LooksY"), this, &AMain_Character::LooksY);
	PlayerInputComponent->BindAxis(TEXT("LooksX"), this, &AMain_Character::LooksX);
	PlayerInputComponent->BindAction(TEXT("Jump"),EInputEvent::IE_Pressed,this,&ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Fire"), EInputEvent::IE_Pressed, this, &AMain_Character::Fire);


}

void AMain_Character::MoveForward(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AMain_Character::MoveBack(float AxisValue)
{
	AddMovementInput(GetActorForwardVector() * AxisValue);
}

void AMain_Character::MoveRight(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AMain_Character::MoveLeft(float AxisValue)
{
	AddMovementInput(GetActorRightVector() * AxisValue);
}

void AMain_Character::LooksY(float AxisValue)
{
	AddControllerPitchInput(AxisValue);
}

void AMain_Character::LooksX(float AxisValue)
{
	AddControllerYawInput(AxisValue);
}



void AMain_Character::Fire()
{
	Gun->PullTrigger();
}

