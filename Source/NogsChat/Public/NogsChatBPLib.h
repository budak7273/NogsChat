#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Components/EditableText.h" 
#include "Components/Widget.h"
#include "Blueprint/UserWidget.h" 
#include "NogsChatBPLib.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FOnWidgetCreated, UUserWidget*, Widget);

/**
 * 
 */
UCLASS()
class NOGSCHAT_API UNogsChatBPLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	


public:
	UFUNCTION(BlueprintCallable)
		static void EditableText_OnCommitted(UEditableTextBox* Object, const FText& InText, ETextCommit::Type CommitMethod);

	UFUNCTION(BlueprintCallable, meta = (DeprecatedFunction))
		static void NogsChatBindOnWidgetConstruct(const TSubclassOf<UUserWidget> WidgetClass, FOnWidgetCreated Binding);
	
	static FOnWidgetCreated OnWidgetCreated;
};
