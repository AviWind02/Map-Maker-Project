#include "common.hpp"
#include "fiber_pool.hpp"
#include "gta/player.hpp"
#include "gta_util.hpp"
#include "gui.hpp"
#include "logger.hpp"
#include "memory/module.hpp"
#include "memory/pattern.hpp"
#include "natives.hpp"
#include "pointers.hpp"
#include "renderer.hpp"
#include "script.hpp"
#include "renderer.hpp"
#include <imgui.h>
#include <StackWalker.h>
namespace big
{
    bool doFunctionTick;

	void gui::dx_init()
	{

	}


	void gui::dx_on_tick()
	{
        doFunctionTick = true;//function loops once menu has been opened
	}
    void gui::script_on_tick()
    {
        
        if (g_gui.m_opened)
        {
            //selective disabled
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

            CONTROLS::DISABLE_CONTROL_ACTION(2, 245, true); //ControlMpTextChatAll
            CONTROLS::DISABLE_CONTROL_ACTION(2, 246, true); // ControlMpTextChatTeam
            CONTROLS::DISABLE_CONTROL_ACTION(2, 247, true); // ControlMpTextChatFriends
            CONTROLS::DISABLE_CONTROL_ACTION(2, 248, true); // ControlMpTextChatCrew


            UI::HIDE_HUD_AND_RADAR_THIS_FRAME();
            //UI::THEFEED_REMOVE_ITEM(UI::THEFEED_GET_FIRST_VISIBLE_DELETE_REMAINING());
        }
        
    }


	void gui::script_func()
	{

		while (true)
		{
            g_gui.script_on_tick();
			script::get_current()->yield();
		}
	}
}