// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef BATTERYCOLLECTOR_PickupManager_generated_h
#error "PickupManager.generated.h already included, missing '#pragma once' in PickupManager.h"
#endif
#define BATTERYCOLLECTOR_PickupManager_generated_h

#define BatteryCollector_Source_BatteryCollector_PickupManager_h_14_RPC_WRAPPERS \
	virtual void WasCollected_Implementation(); \
 \
	DECLARE_FUNCTION(execWasCollected) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->WasCollected_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetActiveState) \
	{ \
		P_GET_UBOOL(Z_Param_newState); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetActiveState(Z_Param_newState); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsActive) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetIsActive(); \
		P_NATIVE_END; \
	}


#define BatteryCollector_Source_BatteryCollector_PickupManager_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execWasCollected) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->WasCollected_Implementation(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execSetActiveState) \
	{ \
		P_GET_UBOOL(Z_Param_newState); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetActiveState(Z_Param_newState); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetIsActive) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(bool*)Z_Param__Result=this->GetIsActive(); \
		P_NATIVE_END; \
	}


#define BatteryCollector_Source_BatteryCollector_PickupManager_h_14_EVENT_PARMS
#define BatteryCollector_Source_BatteryCollector_PickupManager_h_14_CALLBACK_WRAPPERS
#define BatteryCollector_Source_BatteryCollector_PickupManager_h_14_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPickupManager(); \
	friend BATTERYCOLLECTOR_API class UClass* Z_Construct_UClass_APickupManager(); \
public: \
	DECLARE_CLASS(APickupManager, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/BatteryCollector"), NO_API) \
	DECLARE_SERIALIZER(APickupManager) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define BatteryCollector_Source_BatteryCollector_PickupManager_h_14_INCLASS \
private: \
	static void StaticRegisterNativesAPickupManager(); \
	friend BATTERYCOLLECTOR_API class UClass* Z_Construct_UClass_APickupManager(); \
public: \
	DECLARE_CLASS(APickupManager, AActor, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/BatteryCollector"), NO_API) \
	DECLARE_SERIALIZER(APickupManager) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define BatteryCollector_Source_BatteryCollector_PickupManager_h_14_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APickupManager(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APickupManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APickupManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APickupManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APickupManager(APickupManager&&); \
	NO_API APickupManager(const APickupManager&); \
public:


#define BatteryCollector_Source_BatteryCollector_PickupManager_h_14_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APickupManager(APickupManager&&); \
	NO_API APickupManager(const APickupManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APickupManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APickupManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APickupManager)


#define BatteryCollector_Source_BatteryCollector_PickupManager_h_14_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__PickupMesh() { return STRUCT_OFFSET(APickupManager, PickupMesh); }


#define BatteryCollector_Source_BatteryCollector_PickupManager_h_11_PROLOG \
	BatteryCollector_Source_BatteryCollector_PickupManager_h_14_EVENT_PARMS


#define BatteryCollector_Source_BatteryCollector_PickupManager_h_14_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BatteryCollector_Source_BatteryCollector_PickupManager_h_14_PRIVATE_PROPERTY_OFFSET \
	BatteryCollector_Source_BatteryCollector_PickupManager_h_14_RPC_WRAPPERS \
	BatteryCollector_Source_BatteryCollector_PickupManager_h_14_CALLBACK_WRAPPERS \
	BatteryCollector_Source_BatteryCollector_PickupManager_h_14_INCLASS \
	BatteryCollector_Source_BatteryCollector_PickupManager_h_14_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BatteryCollector_Source_BatteryCollector_PickupManager_h_14_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BatteryCollector_Source_BatteryCollector_PickupManager_h_14_PRIVATE_PROPERTY_OFFSET \
	BatteryCollector_Source_BatteryCollector_PickupManager_h_14_RPC_WRAPPERS_NO_PURE_DECLS \
	BatteryCollector_Source_BatteryCollector_PickupManager_h_14_CALLBACK_WRAPPERS \
	BatteryCollector_Source_BatteryCollector_PickupManager_h_14_INCLASS_NO_PURE_DECLS \
	BatteryCollector_Source_BatteryCollector_PickupManager_h_14_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BatteryCollector_Source_BatteryCollector_PickupManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
