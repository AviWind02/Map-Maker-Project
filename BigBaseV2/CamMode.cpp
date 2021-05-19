#include "common.hpp"
#include "natives.hpp"
#include "gui.hpp"
#include <imgui.h>
#include <imgui_internal.h>
#include <d3d11.h>
#include <renderer.hpp>
#include "./Math/Math.hpp"
#include <Raycast.h>
#include <Crosshiar.hpp>
#include "fiber_pool.hpp"
#include "./features.hpp"
#include "./EntityControl.h"


using namespace big;
namespace EntityControl
{

}
namespace CamScript
{
	Cam cam;
	Player Me;
	Vector3 CameraRotation;
	Vector3 Playercoord;
	Vector3 Cameracoord_Move;
	void setCamStat()
	{
		Me = PLAYER::PLAYER_PED_ID();
		CameraRotation = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Playercoord = ENTITY::GET_ENTITY_COORDS(Me, 1);
	}
	Cam getCam()
	{
		return cam;
	}
	Vector3 Cameracoord()
	{
		return CAM::GET_CAM_COORD(CamScript::getCam());
	}
	void setCamScript()
	{
		if (!CAM::DOES_CAM_EXIST(cam)) {

			cam = CAM::CREATE_CAM("DEFAULT_SCRIPTED_CAMERA", 1);
			CAM::SET_CAM_ROT(cam, CameraRotation.x, CameraRotation.y, CameraRotation.z, 0);
			CAM::SET_CAM_COORD(cam, Playercoord.x, Playercoord.y, Playercoord.z + 10.f);
		}
		else
			AddLog("Cam found");
	}
	void renderCamScript(bool render)
	{
		if (CAM::DOES_CAM_EXIST(cam)) {

			CAM::RENDER_SCRIPT_CAMS(render, true, 700, 1, 1);
			CAM::SET_CAM_ACTIVE(cam, true);
		}
	}
	void stopCamScript()
	{
		if (CAM::DOES_CAM_EXIST(cam)) {

			CAM::SET_CAM_ACTIVE(cam, false);
			CAM::DESTROY_CAM(cam, false);
			renderCamScript(false);
			PLAYER::SET_PLAYER_CONTROL(Me, true, 0);
			cam = NULL;
		}
	}

	namespace Control
	{
		float Speed;
		void setCamCoord()
		{
			Cameracoord_Move = add(&CAM::GET_CAM_COORD(cam), &multiply(&rot_to_direction(&CameraRotation), Speed));
			CAM::SET_CAM_COORD(cam, Cameracoord_Move.x, Cameracoord_Move.y, Cameracoord_Move.z);
		}
		void setCamRotation()
		{
			CameraRotation = CAM::GET_GAMEPLAY_CAM_ROT(0);
			CAM::SET_CAM_ROT(cam, CameraRotation.x, CameraRotation.y, CameraRotation.z, 0);
		}
		void forward()
		{
			if (IsKeyDown(VK_KEY_S))
			{
				Speed = -.5f;
				setCamCoord();
			}
		}
		void backward()
		{
			if (IsKeyDown(VK_KEY_W))
			{
				if (IsKeyDown(VK_LSHIFT))
					Speed = 1.f; else Speed = .5f;
				setCamCoord();
			}
		}
		void pickUpObject()
		{
			if (GetAsyncKeyState(VK_LBUTTON))
			{
				if (Cast::shouldEntityBeheld())
				{
					EntityControl::holdEntity(Cast::getCastedEntity(), 6.f, 0);
					EntityControl::EntityLocked = true;
				}
			}
			else
			{
				EntityControl::EntityLocked = false;
			}
		}
		void Tick()
		{
			forward();
			backward();
			setCamRotation();
			pickUpObject();
		}
	}

	namespace misc
	{
		void setPlayerAtCam()
		{
			ENTITY::SET_ENTITY_COORDS(PED::IS_PED_IN_ANY_VEHICLE(Me, 0) ? PED::GET_VEHICLE_PED_IS_IN(Me, false) : Me,
				Cameracoord().x, Cameracoord().y, Cameracoord().z, 0, 0, 0, 1);
		}
		void setFrameHide()
		{
			UI::HIDE_HUD_AND_RADAR_THIS_FRAME();
		}
	}

}				

namespace CamMode
{
	using namespace CamScript;
	void Tick()
	{
		AddLog("Cam Mode On");
		g_fiber_pool->queue_job([] {
			setCamStat();
			setCamScript();
			renderCamScript(true);
		});
	}
	void stopTick()
	{
		AddLog("Cam Mode Off");
		g_fiber_pool->queue_job([] {
			stopCamScript();
		});
	}
	void controlTick()
	{
		g_fiber_pool->queue_job([] {
			Control::Tick();
			misc::setFrameHide();
		});
	}
}