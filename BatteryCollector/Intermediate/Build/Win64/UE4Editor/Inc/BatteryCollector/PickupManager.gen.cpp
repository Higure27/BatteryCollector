// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "PickupManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePickupManager() {}
// Cross Module References
	BATTERYCOLLECTOR_API UClass* Z_Construct_UClass_APickupManager_NoRegister();
	BATTERYCOLLECTOR_API UClass* Z_Construct_UClass_APickupManager();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_BatteryCollector();
	BATTERYCOLLECTOR_API UFunction* Z_Construct_UFunction_APickupManager_GetIsActive();
	BATTERYCOLLECTOR_API UFunction* Z_Construct_UFunction_APickupManager_SetActiveState();
	BATTERYCOLLECTOR_API UFunction* Z_Construct_UFunction_APickupManager_WasCollected();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	static FName NAME_APickupManager_WasCollected = FName(TEXT("WasCollected"));
	void APickupManager::WasCollected()
	{
		ProcessEvent(FindFunctionChecked(NAME_APickupManager_WasCollected),NULL);
	}
	void APickupManager::StaticRegisterNativesAPickupManager()
	{
		UClass* Class = APickupManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetIsActive", (Native)&APickupManager::execGetIsActive },
			{ "SetActiveState", (Native)&APickupManager::execSetActiveState },
			{ "WasCollected", (Native)&APickupManager::execWasCollected },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_APickupManager_GetIsActive()
	{
		struct PickupManager_eventGetIsActive_Parms
		{
			bool ReturnValue;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_ReturnValue_SetBit = [](void* Obj){ ((PickupManager_eventGetIsActive_Parms*)Obj)->ReturnValue = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Bool, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000580, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(PickupManager_eventGetIsActive_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_ReturnValue_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ReturnValue,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Pickup" },
				{ "ModuleRelativePath", "PickupManager.h" },
				{ "ToolTip", "BluprintPure/callable are both things defined in code but can be called from Blueprints\nBluprintPure can modify things but in general they shouldn't, on everytime they are used.\nBetter for fast calculation that are frequent to change\nReturns if Pickup is active or not" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_APickupManager, "GetIsActive", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14020401, sizeof(PickupManager_eventGetIsActive_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_APickupManager_SetActiveState()
	{
		struct PickupManager_eventSetActiveState_Parms
		{
			bool newState;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			auto NewProp_newState_SetBit = [](void* Obj){ ((PickupManager_eventSetActiveState_Parms*)Obj)->newState = 1; };
			static const UE4CodeGen_Private::FBoolPropertyParams NewProp_newState = { UE4CodeGen_Private::EPropertyClass::Bool, "newState", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(PickupManager_eventSetActiveState_Parms), &UE4CodeGen_Private::TBoolSetBitWrapper<decltype(NewProp_newState_SetBit)>::SetBit, METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_newState,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Pickup" },
				{ "ModuleRelativePath", "PickupManager.h" },
				{ "ToolTip", "BlueprintCallable Only runs when execution pin is hit, saves their result in the out put pins\nBetter for expensive calculations that aren't expected to change\nAllows other classes to change to activate and deactivate the Pickup" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_APickupManager, "SetActiveState", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(PickupManager_eventSetActiveState_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_APickupManager_WasCollected()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "ModuleRelativePath", "PickupManager.h" },
				{ "ToolTip", "some behavior set up in code, other in blueprints\nFunction to call when pickup is collected" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_APickupManager, "WasCollected", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020C00, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_APickupManager_NoRegister()
	{
		return APickupManager::StaticClass();
	}
	UClass* Z_Construct_UClass_APickupManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AActor,
				(UObject* (*)())Z_Construct_UPackage__Script_BatteryCollector,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_APickupManager_GetIsActive, "GetIsActive" }, // 3791892254
				{ &Z_Construct_UFunction_APickupManager_SetActiveState, "SetActiveState" }, // 3033750301
				{ &Z_Construct_UFunction_APickupManager_WasCollected, "WasCollected" }, // 1694119882
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "IncludePath", "PickupManager.h" },
				{ "ModuleRelativePath", "PickupManager.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PickupMesh_MetaData[] = {
				{ "AllowPrivateAccess", "true" },
				{ "Category", "Pickup" },
				{ "EditInline", "true" },
				{ "ModuleRelativePath", "PickupManager.h" },
				{ "ToolTip", "Statich mesh to represent pickups in the level" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_PickupMesh = { UE4CodeGen_Private::EPropertyClass::Object, "PickupMesh", RF_Public|RF_Transient|RF_MarkAsNative, 0x00400000000a001d, 1, nullptr, STRUCT_OFFSET(APickupManager, PickupMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(NewProp_PickupMesh_MetaData, ARRAY_COUNT(NewProp_PickupMesh_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_PickupMesh,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<APickupManager>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&APickupManager::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900080u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APickupManager, 3571621528);
	static FCompiledInDefer Z_CompiledInDefer_UClass_APickupManager(Z_Construct_UClass_APickupManager, &APickupManager::StaticClass, TEXT("/Script/BatteryCollector"), TEXT("APickupManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APickupManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
