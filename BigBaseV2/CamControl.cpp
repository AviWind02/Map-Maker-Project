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
#include "./CamUI.h"
#include "../ObjectSpawner.h"
namespace ControlWhileHeld
{

	Entity LockedEntity;
	void pickUpObject()
	{
		
		if (GetAsyncKeyState(VK_LBUTTON))
			EntityControl::holdEntity(LockedEntity);
		else
			LockedEntity = Cast::getCastedEntity();
		
	}
	bool LockMoveControl;
	bool ctrlDown()
	{
		return GetAsyncKeyState(VK_LCONTROL);
	}
	Vector3 Rotation;
	void editEntityRoll()
	{
			if (GetAsyncKeyState(VK_KEY_Q))
				EntityControl::EditEntityRotation(LockedEntity, EntityControl::Roll);

	}
	void editEntityPitch()
	{
			if (GetAsyncKeyState(VK_KEY_E))
				EntityControl::EditEntityRotation(LockedEntity, EntityControl::Pitch);
	}
	void editEntityYaw()
	{
			if (GetAsyncKeyState(VK_KEY_R))
				EntityControl::EditEntityRotation(LockedEntity, EntityControl::Yaw);
	}
	void deleteEntity()
	{
			if (GetAsyncKeyState(VK_KEY_F))
				EntityControl::Delete(Cast::getCastedEntity());
	}
	void Tick()
	{
		pickUpObject();
		editEntityRoll();
		editEntityPitch();
		editEntityYaw();
		deleteEntity();
	}
}