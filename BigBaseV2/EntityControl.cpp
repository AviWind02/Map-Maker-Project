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

using namespace big;
namespace EntityControl
{
	enum Rotation
	{
		Pitch,
		Roll,
		Yaw
	};
	void holdEntity(Entity Handle, float distance, float Zhight)
	{

		Vector3 CameraRotation = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 CameraDirection = rot_to_direction(&CameraRotation);
		Vector3 Cameracoord = CAM::GET_GAMEPLAY_CAM_COORD();

		Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		float holdPosDistance = (get_distance(&Cameracoord, &playerPosition) + distance);
		Vector3 holdingPos = add(&Cameracoord, &multiply(&CameraDirection, holdPosDistance));

		ENTITY::SET_ENTITY_COORDS_NO_OFFSET(Handle, holdingPos.x, holdingPos.y, (holdingPos.z + Zhight), 1, 1, 1);
	}
	Vector3 getRotation(Entity Handle)
	{
		Vector3 Rotation = {
			ENTITY::GET_ENTITY_PITCH(Handle),
			ENTITY::GET_ENTITY_ROLL(Handle),
			ENTITY::GET_ENTITY_HEADING(Handle)//yaw
		};
		return Rotation;
	}
	void EditEntityRotation(Entity Handle, Rotation rotation, float rotate)
	{
		Vector3 Rotation = {
			ENTITY::GET_ENTITY_PITCH(Handle),
			ENTITY::GET_ENTITY_ROLL(Handle),
			ENTITY::GET_ENTITY_HEADING(Handle)//yaw
		};
	
		switch (rotation)
		{
		case Pitch: 
			ENTITY::SET_ENTITY_ROTATION(Handle, (Rotation.x + rotate), Rotation.y, Rotation.z, 2, 1);
			break;
		case Roll:
			ENTITY::SET_ENTITY_ROTATION(Handle, Rotation.x, (Rotation.y + rotate), Rotation.z, 2, 1);
			break;
		case Yaw:
			ENTITY::SET_ENTITY_ROTATION(Handle, Rotation.x, Rotation.y, (Rotation.z + rotate), 2, 1);
			break;
		}
	}
}