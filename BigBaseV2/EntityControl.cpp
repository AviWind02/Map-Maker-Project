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
#include "EditEntity.h"
#include "CamControl.h"

using namespace big;
namespace EntityControl
{
	bool EntityLocked;
	float entityDistanceFromCam = 6.f, hightFromCrosshire = .1f;
	bool DeletePhase;
	void holdEntity(Entity Handle, float distance, float Zhight)
	{

		Vector3 CameraRotation = CAM::GET_GAMEPLAY_CAM_ROT(0);
		Vector3 CameraDirection = rot_to_direction(&CameraRotation);
		Vector3 Cameracoord = CamScript::Cameracoord();;

		Vector3 playerPosition = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		float holdPosDistance = /*(get_distance(&Cameracoord, &playerPosition)+*/ distance; // );
		Vector3 holdingPos = add(&Cameracoord, &multiply(&CameraDirection, holdPosDistance));
		if (!DeletePhase)
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

	void EditEntityRotation(Entity Handle, Rotation rotation)  
	{
		Vector3 Rotation = EntityEdit::getRotation(Handle);
		switch (rotation)
		{
		case Pitch: 
			ControlWhileHeld::ctrlDown() ? Rotation.x-- : Rotation.x++;
				break;
		case Roll:
			ControlWhileHeld::ctrlDown() ? Rotation.y-- : Rotation.y++;
			break;
		case Yaw:
			ControlWhileHeld::ctrlDown() ? Rotation.z-- : Rotation.z++;
				break;
		}

		EntityEdit::setRotation(Handle, Rotation);

	}
	void AttachEntityToEntity(Entity fromHandle, Entity toHandle, Vector3 coords, int boneindex)
	{
		bool IsPed = ENTITY::IS_ENTITY_A_PED(fromHandle);
		ENTITY::ATTACH_ENTITY_TO_ENTITY(fromHandle, toHandle, boneindex, coords.x, coords.y, coords.z, NULL, NULL, NULL, NULL, false, true, IsPed, NULL, NULL);
	}
	void Delete(Entity Handle)
	{
		g_fiber_pool->queue_job([=] {

			if (ENTITY::DOES_ENTITY_EXIST(Handle))
			{
				DeletePhase = true;
				ENTITY::IS_ENTITY_ATTACHED(Handle) ? ENTITY::DETACH_ENTITY(Handle, false, true) : NULL;
					EntityEdit::setCoords(Handle, { 0.f, 0.f, -500.f });//cant delete, oh will
					EntityEdit::setNoLongerNeeded(Handle);
				DeletePhase = false;
			}
		});
	}
	namespace quickFunction 
	{
		void Attach(Entity fromHandle, Entity toHandle, Vector3 coords)
		{

			AttachEntityToEntity(fromHandle, toHandle, coords, NULL);
		}
	}
}