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
	Vector3 Rotation;
	void editEntityRoll()
	{
		if (GetAsyncKeyState(VK_LSHIFT))
			if (GetAsyncKeyState(VK_KEY_A))
				EntityControl::EditEntityRotation(LockedEntity, EntityControl::Roll, Rotation.x += 1);
			else
				Rotation.x = 0;

	}
	void editEntityPitch()
	{
		if (GetAsyncKeyState(VK_LSHIFT))
			if (GetAsyncKeyState(VK_KEY_W))
				EntityControl::EditEntityRotation(LockedEntity, EntityControl::Pitch, Rotation.y += 1);
			else
				Rotation.y = 0;
	}
	void editEntityYaw()
	{
		if (GetAsyncKeyState(VK_LSHIFT))
			if (GetAsyncKeyState(VK_KEY_S))
				EntityControl::EditEntityRotation(LockedEntity, EntityControl::Yaw, Rotation.z += 1);
			else
				Rotation.z = 0;
	}
	void deleteEntity()
	{
		if (GetAsyncKeyState(VK_LSHIFT))
			if (GetAsyncKeyState(VK_KEY_D))
				EntityControl::Delete(LockedEntity);
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