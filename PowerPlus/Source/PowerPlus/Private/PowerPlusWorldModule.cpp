// 

#include "PowerPlusWorldModule.h"

#include "FGBuildableGeneratorFuel.h"
#include "Engine/GameInstance.h"
#include "NativeHookManager.h"
#include "PowerPlus.h"
#include "Buildables/FGBuildableResourceExtractorBase.h"

UPowerPlusWorldModule::UPowerPlusWorldModule()
{
}

void UPowerPlusWorldModule::StartupModule()
{
	//PrepareBuildings();
}

void UPowerPlusWorldModule::PrepareBuildings(AFGBuildableSubsystem* self, UWorld* world)
{
	UE_LOG(LogPowerPlusWorldModule, Log, TEXT("starting to greet buildings..."));
	GreetBuildings(self, world);
}

void UPowerPlusWorldModule::GreetBuildings(AFGBuildableSubsystem* self, UWorld* world)
{
	UE_LOG(LogPowerPlusWorldModule, Log, TEXT("world got for greetings..."));
	//TArray< AFGBuildable* > buildings;
	
	TArray< AFGBuildableFactory* > allBuildings;
	self->GetTypedBuildable(allBuildings);
	
	if (allBuildings.Num() > 0)
	{
		for (auto generator : allBuildings)
		{
			UE_LOG(LogPowerPlusWorldModule, Log, TEXT("hi building %s!!!!"), *generator->GetName());
		}
	} else {
		UE_LOG(LogPowerPlusWorldModule, Log, TEXT("no buildings found :("));
	}
}

void UPowerPlusWorldModule::GreetGenerators(AFGBuildableGenerator* self, UWorld* world)
{
}

//IMPLEMENT_MODULE(IPowerPlusWorldModule, PowerPlus)