#include "NogsChatBPLib.h"

#include "Components/EditableText.h" 
#include "Components/EditableTextBox.h"

#include "Blueprint/UserWidget.h"
#include "Patching/BlueprintHookHelper.h"
#include "Patching/BlueprintHookManager.h"


void UNogsChatBPLib::EditableText_OnCommitted(UEditableTextBox* Object, const FText& InText, ETextCommit::Type CommitMethod)
{
	if (Object)
		Object->OnTextCommitted.Broadcast(InText, CommitMethod);
};

void UNogsChatBPLib::NogsChatBindOnWidgetConstruct(const TSubclassOf<UUserWidget> WidgetClass, FOnWidgetCreated Binding) {
	if (!WidgetClass)
		return;
	UFunction* ConstructFunction = WidgetClass->FindFunctionByName(TEXT("Construct"));
	if (!ConstructFunction || ConstructFunction->IsNative())
	{
		return;
	}
	UBlueprintHookManager* HookManager = GEngine->GetEngineSubsystem<UBlueprintHookManager>();
	HookManager->HookBlueprintFunction(ConstructFunction, [Binding](FBlueprintHookHelper& HookHelper) {
		Binding.ExecuteIfBound(Cast<UUserWidget>(HookHelper.GetContext()));
		}, EPredefinedHookOffset::Return);
};
