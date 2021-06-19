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
#include "EntityPool.h"
#include "../CamControl.h"
#include "../EntityControl.h"
#include "../EditEntity.h"


using namespace big;



namespace CamUI
{
	
	const char* entityType;
	const char* entityAttach;
	//should have used a fucking for loop and return function for EntityType and EntityAttach oh will--------------
	void EntityType()
	{
		if (ENTITY::IS_ENTITY_A_PED(ControlWhileHeld::LockedEntity))
			entityType = "Ped";
		else if (ENTITY::IS_ENTITY_A_VEHICLE(ControlWhileHeld::LockedEntity))
			entityType = "Vehicle";
		else if (ENTITY::IS_ENTITY_AN_OBJECT(ControlWhileHeld::LockedEntity))
			entityType = "Object";
		else 
			entityType = "NULL";
		Infobox("Type:", entityType, 4);

	}
	void pool()
	{
		Infobox("Total Pool:", std::to_string(EntityPool::getTotalPoolNum()) + "/2046", 0);
		Infobox("Object Pool:", std::to_string(EntityPool::getObjectPoolNum()) + "/682", 1);
		Infobox("Vehicle Pool:", std::to_string(EntityPool::getVehiclePoolNum()) + "/682", 2);
		Infobox("Ped Pool:", std::to_string(EntityPool::getPedPoolNum()) + "/682", 3);
	}
	void EntityAttach()
	{

		if (ENTITY::IS_ENTITY_ATTACHED_TO_ANY_OBJECT(ControlWhileHeld::LockedEntity))
			entityAttach = "To Object";
		else if (ENTITY::IS_ENTITY_ATTACHED_TO_ANY_PED(ControlWhileHeld::LockedEntity))
			entityAttach = "To Ped";
		else if (ENTITY::IS_ENTITY_ATTACHED_TO_ANY_VEHICLE(ControlWhileHeld::LockedEntity))
			entityAttach = "To Vehicle";
		else if (ENTITY::IS_ENTITY_ATTACHED(ControlWhileHeld::LockedEntity))
			entityAttach = "To Entity";
		else
			entityAttach = "Nothing";

		Infobox("Attched:", entityAttach, 5);

	}
	void EntityPOS()
	{
		Vector3 Coords = ENTITY::GET_ENTITY_COORDS(ControlWhileHeld::LockedEntity, false);
		Vector3 Rotation = EntityEdit::getRotation(ControlWhileHeld::LockedEntity);
		Vector3 Speed = ENTITY::GET_ENTITY_SPEED_VECTOR(ControlWhileHeld::LockedEntity, true);
		Vector3 forward = ENTITY::GET_ENTITY_FORWARD_VECTOR(ControlWhileHeld::LockedEntity);
		float Heading = ENTITY::GET_ENTITY_HEADING(ControlWhileHeld::LockedEntity);
		float Physicsheading = ENTITY::_GET_ENTITY_PHYSICS_HEADING(ControlWhileHeld::LockedEntity);
		float aboveGroundHight = ENTITY::GET_ENTITY_HEIGHT_ABOVE_GROUND(ControlWhileHeld::LockedEntity);



		Infobox("Rotation(Pitch, Roll, Yaw):", (RemoveDPoint(Rotation.x, ", ") + RemoveDPoint(Rotation.y, ", ") + RemoveDPoint(Rotation.z)), 6);
		Infobox("Coords(XYZ):", (RemoveDPoint(Coords.x, ", ") + RemoveDPoint(Coords.y, ", ") + RemoveDPoint(Coords.z)), 7);
		Infobox("Speed(XYZ):", (RemoveDPoint(Speed.x, ", ") + RemoveDPoint(Speed.y, ", ") + RemoveDPoint(Speed.z)), 8);
		Infobox("Forward(XYZ):", (RemoveDPoint(forward.x, ", ") + RemoveDPoint(forward.y, ", ") + RemoveDPoint(forward.z)), 9);
		Infobox("Heading/Facing:", RemoveDPoint(Heading), 10);
		Infobox("Physics heading:", RemoveDPoint(Physicsheading), 11);
		Infobox("From Ground Hight:", RemoveDPoint(aboveGroundHight), 12);
	}
	void misc()
	{
	

		Infobox("Static:", ENTITY::IS_ENTITY_STATIC(ControlWhileHeld::LockedEntity) ? "Yes" : "No", 13);
		Infobox("Upside-down:", ENTITY::IS_ENTITY_UPSIDEDOWN(ControlWhileHeld::LockedEntity) ? "Yes" : "No", 14);
		Infobox("Occluded:", ENTITY::IS_ENTITY_OCCLUDED(ControlWhileHeld::LockedEntity) ? "Yes" : "No", 15);
		Infobox("Level of detail distance:", std::to_string(ENTITY::GET_ENTITY_LOD_DIST(ControlWhileHeld::LockedEntity)), 16);
		Infobox("Waiting on World Collision:", ENTITY::IS_ENTITY_WAITING_FOR_WORLD_COLLISION(ControlWhileHeld::LockedEntity) ? "Yes" : "No", 17);
		Infobox("Alpha:", std::to_string(ENTITY::GET_ENTITY_ALPHA(ControlWhileHeld::LockedEntity)), 18);
		Infobox("Visible:", ENTITY::IS_ENTITY_VISIBLE(ControlWhileHeld::LockedEntity) ? "Yes" : "No", 19);
		Infobox("Visible to script:", ENTITY::IS_ENTITY_VISIBLE_TO_SCRIPT(ControlWhileHeld::LockedEntity) ? "Yes" : "No", 20);
		Infobox("Mission/Script/Important Entity:", ENTITY::IS_ENTITY_A_MISSION_ENTITY(ControlWhileHeld::LockedEntity) ? "Yes" : "No", 21);
		Infobox("Health:", std::to_string(ENTITY::GET_ENTITY_HEALTH(ControlWhileHeld::LockedEntity)), 22);
		Infobox("Max health:", std::to_string(ENTITY::GET_ENTITY_MAX_HEALTH(ControlWhileHeld::LockedEntity)), 23);
		Infobox("Belong to this script:", ENTITY::DOES_ENTITY_BELONG_TO_THIS_SCRIPT(ControlWhileHeld::LockedEntity, true) ? "Yes" : "No", 24);
		Infobox("Have drawable:", ENTITY::DOES_ENTITY_HAVE_DRAWABLE(ControlWhileHeld::LockedEntity) ? "Yes" : "No", 25);
		Infobox("Have Physics:", ENTITY::DOES_ENTITY_HAVE_PHYSICS(ControlWhileHeld::LockedEntity) ? "Yes" : "No", 26);
		Infobox("Distance From Cam(F):", RemoveDPoint(EntityControl::entityDistanceFromCam), 27);
		Infobox("Hight From crosshire(F):", RemoveDPoint(EntityControl::hightFromCrosshire), 28);


	}

	void Tick()
	{
		pool();
		EntityType();
		EntityAttach();
		EntityPOS();
		misc();

	}
}