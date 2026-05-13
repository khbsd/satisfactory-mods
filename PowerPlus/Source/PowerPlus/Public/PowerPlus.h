// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN( LogPowerPlus, Log, All );
DEFINE_LOG_CATEGORY( LogPowerPlus );

class POWERPLUS_API FPowerPlusModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	FPowerPlusModule();
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
