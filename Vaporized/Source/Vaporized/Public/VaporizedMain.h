

#pragma once

#include "CoreMinimal.h"

VAPORIZED_API DECLARE_LOG_CATEGORY_EXTERN(VaporizedLogging, Log, All);
VAPORIZED_API DEFINE_LOG_CATEGORY(VaporizedLogging)

/**
 * 
 */
class VAPORIZED_API VaporizedMain
{
public:
	VaporizedMain();
	~VaporizedMain();
	static void TestLogging();
};
