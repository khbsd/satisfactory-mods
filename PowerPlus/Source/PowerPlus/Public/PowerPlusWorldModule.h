// 

#pragma once

#include "CoreMinimal.h"
#include "FGBuildable.h"
#include "FGBuildableSubsystem.h"
#include "GameWorldModule.h"
#include "FGBuildableGenerator.h"
#include "ModuleInterface.h"
#include "FGUnlock.h"
#include "GameInstanceModule.h"
#include "ModSubsystem.h"
#include "PowerPlusWorldModule.generated.h"

DECLARE_LOG_CATEGORY_EXTERN( LogPowerPlusWorldModule, Log, All );
DEFINE_LOG_CATEGORY( LogPowerPlusWorldModule );

UCLASS()
class POWERPLUS_API UPowerPlusWorldModule : public UGameWorldModule
{
	GENERATED_BODY()

public:
	UPowerPlusWorldModule();
	
	virtual void StartupModule();
	static void GreetBuildings(AFGBuildableSubsystem* self, UWorld* world);
	static void PrepareBuildings(AFGBuildableSubsystem* self, UWorld* world);
	static void GreetGenerators(AFGBuildableGenerator* self, UWorld* world);
};
