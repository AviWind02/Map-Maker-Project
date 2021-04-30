#include "common.hpp"
#include "natives.hpp"
#include "gui.hpp"
#include <imgui.h>
#include <imgui_internal.h>
#include <d3d11.h>
#include <renderer.hpp>
#include "./Math/Math.hpp"
#include "Raycast.h"
#include "./features.hpp"

using namespace big;
namespace Cast
{ 
	BOOL Hit;
	Vector3 Endcoord;
	Vector3 surfaceNormalcoord;
	Entity CastedEntity;

	void getRay()
	{
		Vector3 CamCoord = CAM::GET_GAMEPLAY_CAM_COORD();
		Vector3 EndOfCamCoord = add(&CAM::GET_GAMEPLAY_CAM_COORD(), &multiply(&rot_to_direction(&CAM::GET_GAMEPLAY_CAM_ROT(0)), 5000.f));
		int ray = WORLDPROBE::_START_SHAPE_TEST_RAY(CamCoord.x, CamCoord.y, CamCoord.z, EndOfCamCoord.x, EndOfCamCoord.y, EndOfCamCoord.z, -1, PLAYER::PLAYER_PED_ID(), 7);
		WORLDPROBE::GET_SHAPE_TEST_RESULT(ray, &Hit, &Endcoord, &surfaceNormalcoord, &CastedEntity);
	}

	BOOL hasRayHit()
	{
		getRay();
		return Hit;
	}

	Vector3 getEndCoord()
	{
		getRay();
		return Endcoord;
	}

	Vector3 getSurfaceNormalCoord()
	{
		getRay();
		return surfaceNormalcoord;
	}

	Entity getCastedEntity()
	{
		getRay();
		return CastedEntity;
	}

	bool isEntityHitVehicle()
	{
		if (hasRayHit())
		{
			if (ENTITY::DOES_ENTITY_EXIST(getCastedEntity()))
			{
				if (ENTITY::IS_ENTITY_A_VEHICLE(getCastedEntity()))
				{
					return true;
				}
			}
		}
		return false;
	}

	bool isEntityHitObject()
	{
		if (hasRayHit())
		{
			if (ENTITY::DOES_ENTITY_EXIST(getCastedEntity()))
			{
				if (ENTITY::IS_ENTITY_AN_OBJECT(getCastedEntity()))
				{
					return true;
				}
			}
		}
		return false;
	}

	bool isEntityHitPed()
	{
		if (hasRayHit())
		{
			if (ENTITY::DOES_ENTITY_EXIST(getCastedEntity()))
			{
				if (ENTITY::IS_ENTITY_A_PED(getCastedEntity()))
				{
					return true;
				}
			}
		}
		return false;
	}
}

