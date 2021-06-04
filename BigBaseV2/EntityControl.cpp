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
#include "EntityControl.h"
#include "CamMode.h"

using namespace big;
namespace EntityControl
{
	bool EntityLocked;
	float entityDistanceFromCam = 6.f, hightFromCrosshire = .1f;
	void holdEntity(Entity Handle, float distance, float Zhight)
	{

		Vector3 CameraRotation = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 CameraDirection = rot_to_direction(&CameraRotation);
		Vector3 Cameracoord = CamScript::Cameracoord();;

		Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		float holdPosDistance = /*(get_distance(&Cameracoord, &playerPosition)+*/ distance; // );
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
	void AttachEntityToEntity(Entity fromHandle, Entity toHandle, Vector3 coords, int boneindex)
	{
		bool IsPed = ENTITY::IS_ENTITY_A_PED(fromHandle);
		ENTITY::ATTACH_ENTITY_TO_ENTITY(fromHandle, toHandle, boneindex, coords.x, coords.y, coords.z, NULL, NULL, NULL, NULL, false, true, IsPed, NULL, NULL);
	}
	void Delete(Entity Handle)
	{
		g_fiber_pool->queue_job([=] {

			Hash handleHash = ENTITY::GET_ENTITY_MODEL(Handle);
			if (ENTITY::DOES_ENTITY_EXIST(Handle))
			{
				ENTITY::IS_ENTITY_ATTACHED(Handle) ? ENTITY::DETACH_ENTITY(Handle, false, true) : NULL;
				ENTITY::DELETE_ENTITY(&(int)Handle);

			}
		});
	}
	namespace quickFunction 
	{
		void Attach(Entity fromHandle, Entity toHandle, Vector3 coords = {0, 0, 0})
		{

			AttachEntityToEntity(fromHandle, toHandle, coords, NULL);
		}
	}
}