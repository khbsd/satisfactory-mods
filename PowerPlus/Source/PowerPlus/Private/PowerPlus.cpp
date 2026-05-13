// Copyright Epic Games, Inc. All Rights Reserved.

#include "PowerPlus.h"

#include "AutomationCommon.h"
#include "FGBuildableGenerator.h"
#include "FGBuildableSubsystem.h"
#include "NativeHookManager.h"
#include "PowerPlusWorldModule.h"
#include "Buildables/FGBuildableResourceExtractorBase.h"

#define LOCTEXT_NAMESPACE "FPowerPlusModule"

FPowerPlusModule::FPowerPlusModule()
{

}

void FPowerPlusModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	UE_LOG( LogPowerPlus, Log, TEXT("beepboop") );
	if(FPlatformProperties::RequiresCookedData())
	{
		AFGBuildableSubsystem* Subsystem = GetMutableDefault<AFGBuildableSubsystem>();
		AFGBuildableGenerator* Generator = GetMutableDefault<AFGBuildableGenerator>();
			
		SUBSCRIBE_METHOD_VIRTUAL(
    		AFGBuildableSubsystem::BeginPlay, 
    		Subsystem, 
    		[](TCallScope<void(*)(AFGBuildableSubsystem*)>& scope,  
    		AFGBuildableSubsystem* selfref)
		{
    		UE_LOG(LogPowerPlus, Log, TEXT("greeting buildings..."));
    		//UPowerPlusWorldModule::PrepareBuildings(selfref, selfref->GetWorld());
		});
		
		SUBSCRIBE_METHOD(
			AFGBuildableGenerator::Factory_TickPowerProduction,
			[](TCallScope<void(*)(AFGBuildableGenerator*, float)>& scope, 
			AFGBuildableGenerator* selfRef, float dt)
		{
			//float TempCapacity = selfRef->mPowerProduction * 2;
			//if (selfRef->GetDefaultPowerProductionCapacity() < TempCapacity)
				//selfRef->mPowerProduction *= 2;

			
				
			UE_LOG( LogPowerPlus, Log, TEXT("beepboop %s makes %f power"), *selfRef->GetName(), selfRef->mPowerProduction );
		});
		
		SUBSCRIBE_METHOD(
			AFGBuildableGenerator::GetDefaultPowerProductionCapacity,
			[](TCallScope<float(*)(const AFGBuildableGenerator*)>& scope, 
			const AFGBuildableGenerator* selfRef)
		{
			scope.Override(selfRef->mPowerProduction * 2);
		});
		
		SUBSCRIBE_METHOD(
			AFGBuildableGenerator::GetPowerProductionCapacity,
			[](TCallScope<float(*)(const AFGBuildableGenerator*)>& scope, 
			const AFGBuildableGenerator* selfRef)
		{
			scope.Override(selfRef->mPowerProduction * 2);
		});
		
		SUBSCRIBE_METHOD(
			AFGBuildableGenerator::CalcPowerProductionCapacityForPotential,
			[](TCallScope<float(*)(const AFGBuildableGenerator*, float)>& scope, 
			const AFGBuildableGenerator* selfRef, float potential)
		{
			scope.Override(selfRef->mPowerProduction * 2);
		});

		SUBSCRIBE_METHOD(
			AFGBuildableGenerator::CalcPowerProductionCapacityForPotential,
			[](TCallScope<float(*)(const AFGBuildableGenerator*, float)>& scope, 
			const AFGBuildableGenerator* selfRef, float potential)
		{
			scope.Override(selfRef->mPowerProduction * 2);
		});
	}
}

void FPowerPlusModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPowerPlusModule, PowerPlus);