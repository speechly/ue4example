// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeechlyBlueprintFunctionLibrary.h"
#include "..\Public\SpeechlyBlueprintFunctionLibrary.h"


FString USpeechlyBlueprintFunctionLibrary::PrintResponse(const FSpeechlyResponse& Response)
{
	FString Output;
	bool bIsFirst = true;
	auto AddOutput = [&](const FString& Text)
	{
		if (!bIsFirst)
		{
			Output += TEXT("\n");
		}
		bIsFirst = false;
		Output += Text;
	};
	if (!Response.Transcript.IsEmpty())
	{
		AddOutput(TEXT("Transcript: ") + Response.Transcript);
	}
	if (!Response.Intent.IsEmpty())
	{
		AddOutput(TEXT("Intent: ") + Response.Intent);
	}
	if (Response.Entities.Num() != 0)
	{
		AddOutput(TEXT("Entities:"));
		for (auto Entity : Response.Entities)
		{
			Output += FString::Printf(TEXT("\n  %s: %s"), *Entity.Key, *Entity.Value);
		}
	}
	FString FinalStr = Response.bIsFinal ? TEXT("YES") : TEXT("NO");
	AddOutput(TEXT("Final: ") + FinalStr);
	return Output;
}
