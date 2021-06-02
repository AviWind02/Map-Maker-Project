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

	void editEntityRoll()
	{
		
	}
	void editEntityPitch()
	{

	}
	void editEntityYaw()
	{

	}

	void deleteEntity()
	{

	}
	void Tick()
	{
		pickUpObject();
	}
}