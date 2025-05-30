// PratoPyLibUtils.h

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PratoPyLibUtils.generated.h"

UCLASS()
class UPratoPyLibUtils : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    /**
     * Gets the screen coordinates (Top-Left and Bottom-Right) of the active editor viewport.
     * @param TopLeft       (Output) The top-left corner position in absolute screen coordinates.
     * @param BottomRight   (Output) The bottom-right corner position in absolute screen coordinates.
     * @return              True if the position was successfully retrieved, false otherwise (e.g., no active viewport).
     */
    
    UFUNCTION(BlueprintCallable, Category = "PratoPyLib|Utils")
    static FVector4 GetEditorViewportPositionAsVector4();

    UFUNCTION(BlueprintCallable, Category = "PratoPyLib|Utils")
    static FVector GetEditorViewportMouseWorldPosition();

    UFUNCTION(BlueprintCallable, Category = "PratoPyLib|Utils")
    static FVector GetEditorViewportMouseWorldFarPosition(float Distance = 10000.0f);
};