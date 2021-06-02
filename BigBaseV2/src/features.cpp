#include "common.hpp"
#include "features.hpp"
#include "logger.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "gui.hpp"
#include <imgui.h>
#include <imgui_internal.h>
#include <d3d11.h>
#include <renderer.hpp>
namespace big
{
	void features::run_tick()
	{
	}

	void features::script_func()
	{
		while (true)
		{
			run_tick();
			script::get_current()->yield();
		}
	}
}

char* StringToChar(std::string string)
{
	return _strdup(string.c_str());
}
#define IM_PRINTFARGS(FMT)
ImGuiTextBuffer     Buf;
bool                ScrollToBottom;
void Clear() { Buf.clear(); }
std::string line = "\n";
void AddLog(const char* fmt, ...) IM_PRINTFARGS(2)
{
	va_list args;
	va_start(args, fmt);
	Buf.appendfv(StringToChar(fmt + line), args);
	va_end(args);
	ScrollToBottom = true;
}
bool SETDEBUGWINDOWPOS = true;
void DrawLogBox(const char* title)
{
	if (SETDEBUGWINDOWPOS)
	{
		ImGui::SetNextWindowSize(ImVec2(382, 156), ImGuiCond_FirstUseEver);
		ImGui::SetNextWindowPos(ImVec2(1512, 13), ImGuiCond_FirstUseEver);
		SETDEBUGWINDOWPOS = false;
	}
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(ImColor(0, 0, 0, 150)));
	ImGui::Begin(title, NULL, 0);
	ImGui::PopStyleColor();
	ImGui::TextUnformatted(Buf.begin());
	if (ScrollToBottom)
		ImGui::SetScrollHere(1.0f);
	ScrollToBottom = false;
	ImGui::End();
}
void lockcontrols()
{
	//selective disabled
	CONTROLS::DISABLE_CONTROL_ACTION(2, 0, true); //ControlNextCamera
	CONTROLS::DISABLE_CONTROL_ACTION(2, 12, true); //ControlWeaponWheelUpDown
	CONTROLS::DISABLE_CONTROL_ACTION(2, 13, true); //ControlWeaponWheelLeftRight
	CONTROLS::DISABLE_CONTROL_ACTION(2, 14, true); //ControlWeaponWheelNext
	CONTROLS::DISABLE_CONTROL_ACTION(2, 15, true); //ControlWeaponWheelPrev
	CONTROLS::DISABLE_CONTROL_ACTION(2, 16, true); //CONTROLSelectNextWeapon
	CONTROLS::DISABLE_CONTROL_ACTION(2, 17, true); //CONTROLSelectPrevWeapon
	CONTROLS::DISABLE_CONTROL_ACTION(2, 263, true); //ControlMeleeAttack1
	CONTROLS::DISABLE_CONTROL_ACTION(2, 264, true); //ControlMeleeAttack2
	CONTROLS::DISABLE_CONTROL_ACTION(2, 257, true); //ControlAttack2
	CONTROLS::DISABLE_CONTROL_ACTION(2, 24, true); //ControlAttack
	CONTROLS::DISABLE_CONTROL_ACTION(2, 25, true); //ControlAim
	CONTROLS::DISABLE_CONTROL_ACTION(2, 140, true); //ControlMeleeAttackLight
	CONTROLS::DISABLE_CONTROL_ACTION(2, 141, true); //ControlMeleeAttackHeavy
	CONTROLS::DISABLE_CONTROL_ACTION(2, 142, true); //ControlMeleeAttackAlternate
	CONTROLS::DISABLE_CONTROL_ACTION(2, 144, true); //ControlParachuteDeploy
	CONTROLS::DISABLE_CONTROL_ACTION(2, 145, true); //ControlParachuteDetach
	CONTROLS::DISABLE_CONTROL_ACTION(2, 81, true); //ControlVehiclePrevRadio
	CONTROLS::DISABLE_CONTROL_ACTION(2, 82, true); //ControlVehicleRadioWheel
	CONTROLS::DISABLE_CONTROL_ACTION(2, 332, true); //ControlRadioWheelUpDown
	CONTROLS::DISABLE_CONTROL_ACTION(2, 333, true); //ControlRadioWheelLeftRight
	CONTROLS::DISABLE_CONTROL_ACTION(2, 53, true); // ControlWeaponSpecial
	CONTROLS::DISABLE_CONTROL_ACTION(2, 54, true); // ControlWeaponSpecial2
	CONTROLS::DISABLE_CONTROL_ACTION(2, 37, true); // CONTROLSelectWeapon
	CONTROLS::DISABLE_CONTROL_ACTION(2, 56, true); // ControlDropWeapon
	CONTROLS::DISABLE_CONTROL_ACTION(2, 262, true); // ControlNextWeapon
	CONTROLS::DISABLE_CONTROL_ACTION(2, 261, true); // ControlPrevWeapon
	// always disabed while open
	CONTROLS::DISABLE_CONTROL_ACTION(2, 19, true); // ControlCharacterWheel
	CONTROLS::DISABLE_CONTROL_ACTION(2, 23, true); // ControlEnter
	CONTROLS::DISABLE_CONTROL_ACTION(2, 27, true); // CControlPhone
	CONTROLS::DISABLE_CONTROL_ACTION(2, 44, true); // ControlCover
	CONTROLS::DISABLE_CONTROL_ACTION(2, 45, true); //ControlReload
	CONTROLS::DISABLE_CONTROL_ACTION(2, 58, true); //ControlThrowGrenade
	CONTROLS::DISABLE_CONTROL_ACTION(2, 51, true); //ControlContext
	CONTROLS::DISABLE_CONTROL_ACTION(2, 52, true); // ControlContextSecondary
	CONTROLS::DISABLE_CONTROL_ACTION(2, 75, true); //ControlVehicleExit
	CONTROLS::DISABLE_CONTROL_ACTION(2, 80, true); //ControlVehicleCinCam
	CONTROLS::DISABLE_CONTROL_ACTION(2, 85, true); // ControlVehicleRadioWheel
	CONTROLS::DISABLE_CONTROL_ACTION(2, 180, true); //
	//ControlPhoneScrollForward
	CONTROLS::DISABLE_CONTROL_ACTION(2, 181, true); //ControlPhoneScrollBackward
	CONTROLS::DISABLE_CONTROL_ACTION(2, 199, true); ////ControlFrontendPause
	CONTROLS::DISABLE_CONTROL_ACTION(2, 200, true); // ControlFrontendPauseAlternate
	CONTROLS::DISABLE_CONTROL_ACTION(2, 245, true); //ControlMpTextChatAll
	CONTROLS::DISABLE_CONTROL_ACTION(2, 246, true); // ControlMpTextChatTeam
	CONTROLS::DISABLE_CONTROL_ACTION(2, 247, true); // ControlMpTextChatFriends
	CONTROLS::DISABLE_CONTROL_ACTION(2, 248, true); // ControlMpTextChatCrew
    CONTROLS::DISABLE_CONTROL_ACTION(2, 106, true); // VehicleMouseControlOverride

	CONTROLS::DISABLE_CONTROL_ACTION(2, 31, true); // MoveAblePlayer
	CONTROLS::DISABLE_CONTROL_ACTION(2, 32, true); // MoveAblePlayer
	CONTROLS::DISABLE_CONTROL_ACTION(2, 33, true); // MoveAblePlayer
	CONTROLS::DISABLE_CONTROL_ACTION(2, 34, true); // MoveAblePlayer
	CONTROLS::DISABLE_CONTROL_ACTION(2, 35, true); // MoveAblePlayer
	CONTROLS::DISABLE_CONTROL_ACTION(2, 35, true); // MoveAblePlayer

}