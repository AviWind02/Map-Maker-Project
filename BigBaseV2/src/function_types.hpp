#pragma once
#include "common.hpp"
#include "gta/fwddec.hpp"
#include "gta/natives.hpp"

namespace big::functions
{
	using run_script_threads_t = bool(*)(std::uint32_t ops_to_execute);
	using get_native_handler_t = rage::scrNativeHandler(*)(rage::scrNativeRegistrationTable*, rage::scrNativeHash);
	using fix_vectors_t = void(*)(rage::scrNativeCallContext*);
	using GetLabelText = const char* (__fastcall*)(int64_t script, const char* label);
	using getEventData = BOOL(__fastcall*)(int32_t eventGroup, int32_t eventIndex, int32_t* argStruct, int32_t argStructSize);//sub19
	using TaskEvents = bool(*) (std::uintptr_t thisptr, std::uintptr_t sourcePlayer, std::uintptr_t targetPlayer);
	typedef bool(__cdecl* IsDLCPresent)();
	using FileRegister = uint32_t * (*)(int* a1, const char* a2, bool a3, const char* a4, bool a5);

}
