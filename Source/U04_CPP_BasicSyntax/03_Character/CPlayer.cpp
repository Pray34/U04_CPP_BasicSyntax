#include "CPlayer.h"
#include "CAnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Global.h"
#include "Materials/MaterialInstanceConstant.h"

ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);


	//Set SkeletalMesh(Mannequin)
	ConstructorHelpers::FObjectFinder<USkeletalMesh> meshAsset(TEXT("SkeletalMesh'/Game/Character/Mesh/SK_Mannequin.SK_Mannequin'"));
	if (meshAsset.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(meshAsset.Object);
		GetMesh()->SetRelativeRotation(FRotator(0, -90.0f, 0));
		GetMesh()->SetRelativeLocation(FVector(0, 0, -88.0f));
	}
	ConstructorHelpers::FClassFinder<UCAnimInstance> animClass(TEXT("AnimBlueprint'/Game/Player/ABP_CPlayer.ABP_CPlayer_C'"));
	if (animClass.Succeeded())
		GetMesh()->SetAnimInstanceClass(animClass.Class); //.Class : 래퍼런스 클래스를 리턴해줌


	//Component Setting (SpringArm, Camera)
	SpringArm->SetRelativeLocation(FVector(0, 0, 60));
	SpringArm->TargetArmLength = 200.0f;
	SpringArm->bDoCollisionTest = false;
	SpringArm->bUsePawnControlRotation = true;


	//Movement Setting
	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->MaxWalkSpeed = 400.0f;
}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();
	
	//[ Create DynamicInstance ]
	//Get Material Instance
	UObject* obj;
	obj = StaticLoadObject(UMaterialInstanceConstant::StaticClass(), nullptr, TEXT("MaterialInstanceConstant'/Game/Character/Materials/M_UE4Man_Body_Inst.M_UE4Man_Body_Inst'"));
	UMaterialInstanceConstant* bodyMaterialAsset = Cast<UMaterialInstanceConstant>(obj);
	if (!bodyMaterialAsset) return;

	obj = StaticLoadObject(UMaterialInstanceConstant::StaticClass(), nullptr, TEXT("MaterialInstanceConstant'/Game/Character/Materials/M_UE4Man_ChestLogo_Inst.M_UE4Man_ChestLogo_Inst'"));
	UMaterialInstanceConstant* logoMaterialAsset = Cast<UMaterialInstanceConstant>(obj);
	if (!logoMaterialAsset) return;

	//Create Dynamic Material
	BodyMaterialDynamic = UMaterialInstanceDynamic::Create(bodyMaterialAsset, nullptr);
	LogoMaterialDynamic = UMaterialInstanceDynamic::Create(logoMaterialAsset, nullptr);
	//Set DynamicMaterial to SkelMesh
	GetMesh()->SetMaterial(0, BodyMaterialDynamic);
	GetMesh()->SetMaterial(1, LogoMaterialDynamic);
}

void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//축 매핑
	PlayerInputComponent->BindAxis("MoveForward", this, &ACPlayer::OnMoveForward); //멤버 함수의 주소는 class타입까지 넣어줘야한다
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPlayer::OnMoveRight); //언리얼 이벤트 이름이 틀리면 안된다

	PlayerInputComponent->BindAxis("HorizontalLook", this, &ACPlayer::OnHorizontalLook);
	PlayerInputComponent->BindAxis("VerticalLook", this, &ACPlayer::OnVerticalLook);

	//액션 매핑
	PlayerInputComponent->BindAction("Run", EInputEvent::IE_Pressed, this, &ACPlayer::OnRun);
	PlayerInputComponent->BindAction("Run", EInputEvent::IE_Released, this, &ACPlayer::OffRun);
	PlayerInputComponent->BindAction("Interact", EInputEvent::IE_Released, this, &ACPlayer::OnInteract);
	PlayerInputComponent->BindAction("Rifle", EInputEvent::IE_Released, this, &ACPlayer::OnRifle);
}


void ACPlayer::OnMoveForward(float InAxis)
{
	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(rotator).GetForwardVector().GetSafeNormal2D();

	AddMovementInput(direction, InAxis);
}

void ACPlayer::OnMoveRight(float InAxis)
{
	FRotator rotator = FRotator(0, GetControlRotation().Yaw, 0);
	FVector direction = FQuat(rotator).GetRightVector().GetSafeNormal2D();

	AddMovementInput(direction, InAxis);
}

void ACPlayer::OnHorizontalLook(float InAxis)
{
	AddControllerYawInput(InAxis);
}

void ACPlayer::OnVerticalLook(float InAxis)
{
	AddControllerPitchInput(InAxis);
}

void ACPlayer::OnRun()
{
	GetCharacterMovement()->MaxWalkSpeed = 600;
}

void ACPlayer::OffRun()
{
	GetCharacterMovement()->MaxWalkSpeed = 400;
}

void ACPlayer::OnInteract()
{
	if(OnInteractEvent.IsBound())
		OnInteractEvent.Broadcast();
}

void ACPlayer::OnRifle()
{
}

void ACPlayer::ChangeBodyColor(FLinearColor InBodyColor, FLinearColor InLogoColor)
{
	BodyMaterialDynamic->SetVectorParameterValue("BodyColor", InBodyColor);
	LogoMaterialDynamic->SetVectorParameterValue("BodyColor", InLogoColor);
}