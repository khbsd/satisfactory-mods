#include "VaporizedMain.h"
#include "VaporizedModule.h"

VaporizedMain::VaporizedMain()
{
	new VaporizedModule;
}

VaporizedMain::~VaporizedMain()
{
	UE_LOG(VaporizedLogging, Error, TEXT("taw ih taw"));
}

void VaporizedMain::TestLogging()
{
	UE_LOG(VaporizedLogging, Error, TEXT("taw ih taw"));
}
