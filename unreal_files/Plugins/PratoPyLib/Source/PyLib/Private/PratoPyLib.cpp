// PratoPyLib.cpp

#include "PratoPyLib.h"
#include "Widgets/SViewport.h"

#define LOCTEXT_NAMESPACE "FPratoPyLibModule"

void FPratoPyLibModule::StartupModule()
{
    // Initialization code
    UE_LOG(LogTemp, Warning, TEXT("PratoPyLib Module Started!"));
}

void FPratoPyLibModule::ShutdownModule()
{
    // Cleanup code
    UE_LOG(LogTemp, Warning, TEXT("PratoPyLib Module Shutdown!"));
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FPratoPyLibModule, PratoPyLib)