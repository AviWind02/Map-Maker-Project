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
#include "PedList.h"
#include "PropList.h"
#include "VehicleList.h"


using namespace big;
namespace Objectcreator
{
	void spawnObject(const char* objectName, Vector3 pos)
	{
		g_fiber_pool->queue_job([=] {

			Hash ObjectHash = $(objectName);
			if (STREAMING::IS_MODEL_VALID(ObjectHash)
				&& STREAMING::IS_MODEL_IN_CDIMAGE(ObjectHash))
			{
				STREAMING::REQUEST_MODEL(ObjectHash);
				while (!STREAMING::HAS_MODEL_LOADED(ObjectHash))
					script::get_current()->yield();

				Object object = OBJECT::CREATE_OBJECT_NO_OFFSET(ObjectHash, pos.x, pos.y, pos.z, g_pointers->m_is_session_started ? true : false, true, false);

				EntityPool::setObjectPool(objectName, object);

				AddLog("Object Added to Pool: ");
				AddLog(objectName);
			}
			else
				AddLog("Object not found");
		});
	}
	void spawnVehicle(const char* vehicleName, Vector3 pos)
	{
		g_fiber_pool->queue_job([=] {

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

				AddLog("Vehicle Added to Pool: ");
				AddLog(vehicleName);
			}
			else
				AddLog("Vehicle not found");
		});
	}
	void spawnPed(const char* pedName, Vector3 pos)
	{
		g_fiber_pool->queue_job([=] {

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

				AddLog("Ped Added to Pool: ");
				AddLog(pedName);

			}
			else
				AddLog("Ped not found");
		});
	}
	bool in_array(const std::string& value, const std::vector<std::string>& array)
	{
		return std::find(array.begin(), array.end(), value) != array.end();
	}

	bool isPedInList(const char* Entity)
	{
		for(int i = 0; i < 857; i++)
			if (PedList[i] == Entity)
				return true;
		return false;
	}
	bool isVehicleInList(const char* Entity)
	{
		for (int i = 0; i < 719; i++)
			if (VehicleList[i] == Entity)
				return true;
		return false;
	}
	bool isPropInList(const char* Entity)
	{
		for (int i = 0; i < 15746; i++)
			if (Prop[i] == Entity)
				return true;
		return false;
	}

	void spawnEntity(const char* Entity, Vector3 pos)
	{
		if (isPedInList(Entity))
			spawnPed(Entity, pos);
		else if (isVehicleInList(Entity))
			spawnVehicle(Entity, pos);
		else if (isPropInList(Entity))
			spawnObject(Entity, pos);
		else
			AddLog("Entity not found in database");
	}
}