#include "PratoPyLibUtils.h"
#include "Editor.h"
#include "EditorViewportClient.h"
#include "Widgets/SWidget.h"
#include "SLevelViewport.h"
#include "Widgets/SViewport.h"
#include "Engine/Engine.h"


FVector4 UPratoPyLibUtils::GetEditorViewportPositionAsVector4()
{
    FVector2D TopLeft = FVector2D::ZeroVector;
    FVector2D BottomRight = FVector2D::ZeroVector;

    if (GEditor && GEditor->GetActiveViewport())
    {
        FViewport* Viewport = GEditor->GetActiveViewport();
        FEditorViewportClient* ViewportClient = static_cast<FEditorViewportClient*>(Viewport->GetClient());

        if (ViewportClient)
        {
            TSharedPtr<SWidget> Widget = ViewportClient->GetEditorViewportWidget();
            TSharedPtr<SViewport> ViewportWidget = Widget.IsValid() ? StaticCastSharedPtr<SViewport>(Widget) : nullptr;

            if (ViewportWidget.IsValid())
            {
                FGeometry Geometry = ViewportWidget->GetCachedGeometry();

                TopLeft = Geometry.GetAbsolutePosition();
                BottomRight = TopLeft + Geometry.GetAbsoluteSize();

                UE_LOG(LogTemp, Log, TEXT("PratoPyLib: Viewport: TL(%.2f, %.2f) BR(%.2f, %.2f)"),
                    TopLeft.X, TopLeft.Y, BottomRight.X, BottomRight.Y);

                return FVector4(TopLeft.X, TopLeft.Y, BottomRight.X, BottomRight.Y);
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("PratoPyLib: Editor viewport widget is not an SViewport."));
            }
        }
    }

    UE_LOG(LogTemp, Warning, TEXT("PratoPyLib: Failed to get viewport geometry."));
    return FVector4(0, 0, 0, 0);
}

FVector UPratoPyLibUtils::GetEditorViewportMouseWorldPosition()
{
#if WITH_EDITOR
    if (GEditor && GEditor->GetActiveViewport())
    {
        FViewport* Viewport = GEditor->GetActiveViewport();
        FEditorViewportClient* ViewportClient = static_cast<FEditorViewportClient*>(Viewport->GetClient());

        if (ViewportClient)
        {
            // Get mouse position in viewport
            FIntPoint MousePos;
            Viewport->GetMousePos(MousePos);

            // Build a scene view for deprojection
            FSceneViewFamilyContext ViewFamily(FSceneViewFamily::ConstructionValues(
                Viewport,
                ViewportClient->GetScene(),
                ViewportClient->EngineShowFlags
            ));
            FSceneView* SceneView = ViewportClient->CalcSceneView(&ViewFamily);

            if (SceneView)
            {
                FVector WorldOrigin, WorldDirection;
                SceneView->DeprojectFVector2D(MousePos, WorldOrigin, WorldDirection);

                // Trace from camera into the world (for simplicity, return a point 1000 units away)
                return WorldOrigin + WorldDirection;
            }
        }
    }
#endif
    return FVector::ZeroVector;
}

FVector UPratoPyLibUtils::GetEditorViewportMouseWorldFarPosition(float Distance)
{
#if WITH_EDITOR
    if (GEditor && GEditor->GetActiveViewport())
    {
        FViewport* Viewport = GEditor->GetActiveViewport();
        FEditorViewportClient* ViewportClient = static_cast<FEditorViewportClient*>(Viewport->GetClient());

        if (ViewportClient)
        {
            // Get mouse position in viewport
            FIntPoint MousePos;
            Viewport->GetMousePos(MousePos);

            // Build a scene view for deprojection
            FSceneViewFamilyContext ViewFamily(FSceneViewFamily::ConstructionValues(
                Viewport,
                ViewportClient->GetScene(),
                ViewportClient->EngineShowFlags
            ));
            FSceneView* SceneView = ViewportClient->CalcSceneView(&ViewFamily);

            if (SceneView)
            {
                FVector WorldOrigin, WorldDirection;
                SceneView->DeprojectFVector2D(MousePos, WorldOrigin, WorldDirection);

                // Return a point far along the ray (e.g., 10,000 units)
                return WorldOrigin + WorldDirection * Distance;
            }
        }
    }
#endif
    return FVector::ZeroVector;
}

