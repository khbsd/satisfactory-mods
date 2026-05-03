#pragma once
#include "ModuleInterface.h"

class VaporizedModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
};
