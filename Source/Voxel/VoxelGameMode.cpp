

#include "Voxel.h"
#include "VoxelGameMode.h"
#include "VoxelPlayerController.h"

AVoxelGameMode::AVoxelGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	//backup
	PlayerControllerClass = AVoxelPlayerController::StaticClass();

	//Blueprinted Version, relies on the "Copy Reference" asset path you get from Editor
	static ConstructorHelpers::FObjectFinder<UBlueprint> VictoryPCOb(TEXT("Blueprint'/Game/VoxelPlayerControllerBP.VoxelPlayerControllerBP'"));
	if (VictoryPCOb.Object != NULL)
	{
		PlayerControllerClass = (UClass*)VictoryPCOb.Object->GeneratedClass;
	}
}


