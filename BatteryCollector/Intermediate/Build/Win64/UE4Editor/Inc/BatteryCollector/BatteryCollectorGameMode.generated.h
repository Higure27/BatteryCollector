// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
enum class EBatteryPlayState : uint8;
#ifdef BATTERYCOLLECTOR_BatteryCollectorGameMode_generated_h
#error "BatteryCollectorGameMode.generated.h already included, missing '#pragma once' in BatteryCollectorGameMode.h"
#endif
#define BATTERYCOLLECTOR_BatteryCollectorGameMode_generated_h

#define BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_24_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetCurrState) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EBatteryPlayState*)Z_Param__Result=this->GetCurrState(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPowerToWin) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetPowerToWin(); \
		P_NATIVE_END; \
	}


#define BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetCurrState) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(EBatteryPlayState*)Z_Param__Result=this->GetCurrState(); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execGetPowerToWin) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		*(float*)Z_Param__Result=this->GetPowerToWin(); \
		P_NATIVE_END; \
	}


#define BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_24_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABatteryCollectorGameMode(); \
	friend BATTERYCOLLECTOR_API class UClass* Z_Construct_UClass_ABatteryCollectorGameMode(); \
public: \
	DECLARE_CLASS(ABatteryCollectorGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/BatteryCollector"), BATTERYCOLLECTOR_API) \
	DECLARE_SERIALIZER(ABatteryCollectorGameMode) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_24_INCLASS \
private: \
	static void StaticRegisterNativesABatteryCollectorGameMode(); \
	friend BATTERYCOLLECTOR_API class UClass* Z_Construct_UClass_ABatteryCollectorGameMode(); \
public: \
	DECLARE_CLASS(ABatteryCollectorGameMode, AGameModeBase, COMPILED_IN_FLAGS(0 | CLASS_Transient), 0, TEXT("/Script/BatteryCollector"), BATTERYCOLLECTOR_API) \
	DECLARE_SERIALIZER(ABatteryCollectorGameMode) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_24_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	BATTERYCOLLECTOR_API ABatteryCollectorGameMode(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABatteryCollectorGameMode) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(BATTERYCOLLECTOR_API, ABatteryCollectorGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABatteryCollectorGameMode); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	BATTERYCOLLECTOR_API ABatteryCollectorGameMode(ABatteryCollectorGameMode&&); \
	BATTERYCOLLECTOR_API ABatteryCollectorGameMode(const ABatteryCollectorGameMode&); \
public:


#define BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_24_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	BATTERYCOLLECTOR_API ABatteryCollectorGameMode(ABatteryCollectorGameMode&&); \
	BATTERYCOLLECTOR_API ABatteryCollectorGameMode(const ABatteryCollectorGameMode&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(BATTERYCOLLECTOR_API, ABatteryCollectorGameMode); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABatteryCollectorGameMode); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABatteryCollectorGameMode)


#define BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_24_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__decayRate() { return STRUCT_OFFSET(ABatteryCollectorGameMode, decayRate); } \
	FORCEINLINE static uint32 __PPO__powerToWin() { return STRUCT_OFFSET(ABatteryCollectorGameMode, powerToWin); } \
	FORCEINLINE static uint32 __PPO__HUDWidgetClass() { return STRUCT_OFFSET(ABatteryCollectorGameMode, HUDWidgetClass); } \
	FORCEINLINE static uint32 __PPO__currentWidget() { return STRUCT_OFFSET(ABatteryCollectorGameMode, currentWidget); }


#define BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_21_PROLOG
#define BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_24_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_24_PRIVATE_PROPERTY_OFFSET \
	BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_24_RPC_WRAPPERS \
	BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_24_INCLASS \
	BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_24_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_24_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_24_PRIVATE_PROPERTY_OFFSET \
	BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_24_RPC_WRAPPERS_NO_PURE_DECLS \
	BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_24_INCLASS_NO_PURE_DECLS \
	BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h_24_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID BatteryCollector_Source_BatteryCollector_BatteryCollectorGameMode_h


#define FOREACH_ENUM_EBATTERYPLAYSTATE(op) \
	op(EBatteryPlayState::EPlaying) \
	op(EBatteryPlayState::EGameOver) \
	op(EBatteryPlayState::EWon) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
