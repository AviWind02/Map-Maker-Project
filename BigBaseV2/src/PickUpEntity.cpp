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
#include "../CamMode.h"

using namespace big;
namespace PickUpEntity
{

	void holdEntity(Entity Handle, float ObjectDistanceEdit, float ObjectHightEdit)
	{
		Vector3 CameraRotation = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 Cameradirection = rot_to_direction(&CameraRotation);
		Vector3 CameraCoords = CAM::GET_GAMEPLAY_CAM_COORD();
		Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);

		float HoldDistance = (get_distance(&CameraCoords, &PlayerCoords) + ObjectDistanceEdit);
		Vector3 spawnPosition = add(&CameraCoords, &multiply(&Cameradirection, HoldDistance));
		isReal(Handle) ? ENTITY::SET_ENTITY_COORDS_NO_OFFSET(isPedInVehicle(Handle), spawnPosition.x, spawnPosition.y, (spawnPosition.z + ObjectHightEdit), 1, 1, 1) : NULL;
	}

	Entity isPedInVehicle(Entity Handle)
	{
		return ENTITY::IS_ENTITY_A_PED(Handle) && PED::IS_PED_IN_ANY_VEHICLE(Handle, true) ? 
			PED::GET_VEHICLE_PED_IS_IN(Handle, false) : Handle;
	}
	bool isPed(Entity Handle)
	{
		return ENTITY::IS_ENTITY_A_PED(Handle);
	}
	bool isObject(Entity Handle)
	{
		return ENTITY::IS_ENTITY_AN_OBJECT(Handle);
	}
	bool isVehicle(Entity Handle)
	{
		return ENTITY::IS_ENTITY_A_VEHICLE(Handle);
	}
	bool isReal(Entity Handle)
	{
		return ENTITY::DOES_ENTITY_EXIST(Handle);
	}
}