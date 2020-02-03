// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "Speechly.h"

#include "SpeechlyBlueprintFunctionLibrary.generated.h"


/**
 * 
 */
UCLASS()
class SPEECH_API USpeechlyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(Category = "Speechly", BlueprintCallable)
	static FString PrintResponse(const FSpeechlyResponse& Response);
};
