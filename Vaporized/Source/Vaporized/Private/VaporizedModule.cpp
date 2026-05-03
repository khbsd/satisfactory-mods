#include "VaporizedModule.h"
#include "VaporizedMain.h"

#include "Patching/NativeHookManager.h"

#include "Buildables/FGBuildableGenerator.h"
#include "Buildables/FGBuildableGeneratorFuel.h"
#include "Buildables/FGBuildableResourceExtractorBase.h"

void VaporizedModule::StartupModule()
{
#if !WITH_EDITOR
	SUBSCRIBE_METHOD_VIRTUAL( 
		AFGBuildableResourceExtractorBase::BeginPlay, 
		GetMutableDefault<AFGBuildableResourceExtractorBase>(), 
		[](CallScope<void(*)(AFGBuildableResourceExtractorBase*)>& scope, 
		AFGBuildableResourceExtractorBase* selfref)
		{
			selfref->mAllowedResourceForms.AddUnique(EResourceForm::RF_GAS); UE_LOG(VaporizedLogging, Log, TEXT("make Gas Valid: %s"), *selfref->GetName());
		} );
	
	VaporizedMain::TestLogging();
#endif
}

IMPLEMENT_GAME_MODULE(VaporizedModule, VaporizedMain);