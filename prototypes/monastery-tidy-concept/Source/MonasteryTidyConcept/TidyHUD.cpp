// PROTOTYPE - NOT FOR PRODUCTION
// Question: Does drag-drop tidy + purity meter feel like relaxing flow?
// Date: 2026-07-18

#include "TidyHUD.h"
#include "Engine/Canvas.h"

void ATidyHUD::DrawHUD()
{
	Super::DrawHUD();
	if (!Canvas)
	{
		return;
	}

	const float W = Canvas->SizeX;
	const float H = Canvas->SizeY;

	// Purity meter bar (sacred gold fill)
	const float BarW = W * 0.4f;
	const float BarH = 22.f;
	const float BarX = (W - BarW) * 0.5f;
	const float BarY = 40.f;

	DrawRect(FLinearColor(0.15f, 0.12f, 0.1f, 0.85f), BarX, BarY, BarW, BarH);
	DrawRect(FLinearColor(1.f, 0.84f, 0.f, 0.95f), BarX, BarY, BarW * FMath::Clamp(Purity01, 0.f, 1.f), BarH);

	const FString MeterText = FString::Printf(TEXT("Thanh tinh  %d / %d"), PropsHome, PropsTotal);
	DrawText(MeterText, FLinearColor(0.94f, 0.9f, 0.83f), BarX, BarY + 28.f);

	DrawText(TEXT("LMB drag props onto matching ghost homes"), FLinearColor(0.9f, 0.85f, 0.7f, 0.7f), 24.f, H - 48.f);

	if (bRevealed || RevealAlpha > 0.f)
	{
		const float A = FMath::Clamp(RevealAlpha, 0.f, 1.f);
		const float BookW = 80.f;
		const float BookH = 110.f;
		const float BookX = (W - BookW) * 0.5f;
		const float BookY = H * 0.35f;
		DrawRect(FLinearColor(1.f, 0.84f, 0.f, A), BookX, BookY, BookW, BookH);
		DrawText(TEXT("TAM TANG"), FLinearColor(0.2f, 0.12f, 0.05f, A), BookX + 8.f, BookY + BookH * 0.4f);
		DrawText(TEXT("Soft reveal @ 100%"), FLinearColor(1.f, 0.95f, 0.7f, A), BookX - 20.f, BookY + BookH + 12.f);
	}
}
