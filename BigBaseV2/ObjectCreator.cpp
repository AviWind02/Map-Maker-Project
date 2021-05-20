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
#include <pointers.hpp>
#include "script.hpp"
#include "./EntityPool.h"
#include "CamMode.h"


using namespace big;
namespace Objectcreator
{
	void spawnObject(const char* objectName, Vector3 pos)
	{
		Hash ObjectHash = $(objectName);
		if (STREAMING::IS_MODEL_VALID(ObjectHash)
			&& STREAMING::IS_MODEL_IN_CDIMAGE(ObjectHash))
		{
			STREAMING::REQUEST_MODEL(ObjectHash);
			while (!STREAMING::HAS_MODEL_LOADED(ObjectHash))
				script::get_current()->yield();

			Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(ObjectHash, pos.x, pos.y, pos.z, g_pointers->m_is_session_started ? true : false, true, false);

			EntityPool::setObjectPool(objectName, object);
		}
		else
			AddLog("Object not found");
	}
	void spawnVehicle(const char* vehicleName, Vector3 pos)
	{
		Hash vehicleHash = $(vehicleName);
		if (STREAMING::IS_MODEL_VALID(vehicleHash)
			&& STREAMING::IS_MODEL_IN_CDIMAGE(vehicleHash))
		{
			STREAMING::REQUEST_MODEL(vehicleHash);
			while (!STREAMING::HAS_MODEL_LOADED(vehicleHash))
				script::get_current()->yield();

			float MyHeading = ENTITY::GET_ENTITY_HEADING(PLAYER::PLAYER_PED_ID());
			Vehicle vehicle = VEHICLE::CREATE_VEHICLE(vehicleHash, pos.x, pos.y, pos.z, MyHeading, g_pointers->m_is_session_started ? true : false, true);

			EntityPool::setVehiclePool(vehicleName, vehicle);
		}
		else
			AddLog("Vehicle not found");
	}
	void spawnPed(const char* pedName, Vector3 pos)
	{
		Hash pedHash = $(pedName);
		if (STREAMING::IS_MODEL_VALID(pedHash)
			&& STREAMING::IS_MODEL_IN_CDIMAGE(pedHash))
		{
			STREAMING::REQUEST_MODEL(pedHash);
			while (!STREAMING::HAS_MODEL_LOADED(pedHash))
				script::get_current()->yield();

			int pedtype = PED::GET_PED_TYPE(pedHash);
			Ped ped = PED::CREATE_PED(pedtype, pedHash, pos.x, pos.y, pos.z, 1.f, g_pointers->m_is_session_started ? true : false, true);

			EntityPool::setPedPool(pedName, ped);
		}
		else
			AddLog("Ped not found");
	}

	void spawnEntity(const char* EntityName)
	{
		Hash Entity = $(EntityName);

		if (ENTITY::IS_ENTITY_A_PED(Entity))
			spawnPed(EntityName, CamScript::Cameracoord());
		else if (ENTITY::IS_ENTITY_A_VEHICLE(Entity))
			spawnVehicle(EntityName, CamScript::Cameracoord());
		else if (ENTITY::IS_ENTITY_AN_OBJECT(Entity))
			spawnObject(EntityName, CamScript::Cameracoord());
		else
			AddLog("Entity Name not a entity type");
	}
	
}