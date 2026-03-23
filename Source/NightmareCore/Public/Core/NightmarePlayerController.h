#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "Blueprint/UserWidget.h"

#include "NightmarePlayerController.generated.h"

UCLASS()
class ANightmarePlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void BeginPlayingState() override;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="UserInterface")
	void CreateScrapUI();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="UserInterface")
	void CreateWeaponUI();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="UserInterface")
	void CreateRadioUI();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="UserInterface")
	void CreateInventoryUI();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="UserInterface")
	void CreateWorkbenchUI();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="UserInterface")
	void FocusWidget(UUserWidget* InWidget, bool ShowCursor = true);
	
};
