#pragma once
#include "GameWorldModule.h"
#include "ModuleInterface.h"

class VAPORIZED_API VaporizedModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
};
