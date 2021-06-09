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

namespace EntityEdit
{

	
	void setAsMission(Entity handle)
	{
		ENTITY::SET_ENTITY_AS_MISSION_ENTITY(handle, NULL, NULL);

	}
	void setNoLongerNeeded(Entity handle)
	{
		ENTITY::SET_ENTITY_AS_NO_LONGER_NEEDED(&handle);

	}
	void setCanBeDamaged(Entity handle, bool damage)
	{
		ENTITY::SET_ENTITY_CAN_BE_DAMAGED(handle, damage);

	}
	void setCollision(Entity handle, bool collision)
	{
		ENTITY::SET_ENTITY_COLLISION(handle, collision, true);

	}
	void setDynamic(Entity handle, bool dynamic)
	{
		ENTITY::SET_ENTITY_DYNAMIC(handle, dynamic);

	}
	void setHeading(Entity handle, float head)
	{
		ENTITY::SET_ENTITY_HEADING(handle, head);

	}
	void setHealth(Entity handle, int health)
	{
		ENTITY::SET_ENTITY_HEALTH(handle, health);

	}
	void setInvincible(Entity handle, bool invincible)
	{
		ENTITY::SET_ENTITY_INVINCIBLE(handle, invincible);

	}
	void setLight(Entity handle, bool light)
	{
		ENTITY::SET_ENTITY_LIGHTS(handle, light);

	}
	void setMaxSpeed(Entity handle, float speed)
	{
		ENTITY::SET_ENTITY_MAX_SPEED(handle, speed);
	}
	void setDamageByPlayerOnly(Entity handle, bool damage)
	{
		ENTITY::SET_ENTITY_ONLY_DAMAGED_BY_PLAYER(handle, damage);

	}
	void setDamageType(Entity handle, bool bulletProof, bool fireProof,
		bool explosionProof, bool collisionProof, bool meleeProof,
		bool steamProof, bool smokeProof, bool drownProof)
	{
		ENTITY::SET_ENTITY_PROOFS(handle, bulletProof, fireProof,
			explosionProof, collisionProof, meleeProof,
			steamProof, smokeProof, drownProof);

	}
	void setVisible(Entity handle, bool visible)
	{
		ENTITY::SET_ENTITY_VISIBLE(handle, visible, NULL);
	}
	void setVelocity(Entity handle, Vector3 velocity)
	{
		ENTITY::SET_ENTITY_VELOCITY(handle, velocity.x, velocity.y, velocity.z);
	}
	void setGravity(Entity handle, bool gravity)
	{
		ENTITY::SET_ENTITY_HAS_GRAVITY(handle, gravity);

	}
	void setLOD(Entity handle, int LOD)
	{
		ENTITY::SET_ENTITY_LOD_DIST(handle, LOD);

	}
	void setAlpha(Entity handle, int alpha)
	{
		ENTITY::SET_ENTITY_ALPHA(handle, alpha, false);

	}
	void resetAlpha(Entity handle)
	{
		ENTITY::RESET_ENTITY_ALPHA(handle);

	}
	void setPreRender(Entity handle)
	{
		ENTITY::SET_ENTITY_ALWAYS_PRERENDER(handle, true);
	}
	void setRenderScroeched(Entity handle)
	{
		ENTITY::SET_ENTITY_RENDER_SCORCHED(handle, true);
	}
	Vector3 Get_Position(Entity entity)
	{
		return ENTITY::GET_ENTITY_COORDS(entity, ENTITY::IS_ENTITY_A_PED(entity));
	}
	bool is_it_there(Entity entity, Vector3 pos)
	{
		if (ENTITY::IS_ENTITY_AT_COORD(entity, pos.x, pos.y, pos.z,
			100, 100, 100, true, false,
			1)) return true;
		return false;
	}
	Vector3 GetOffsetInWorldCoords(Entity entity, Vector3 offset)
	{
		return ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(entity, offset.x, offset.y, offset.z);
	}
	Vector3 GetOffsetInWorldCoords(Entity entity, float X, float Y, float Z)
	{
		return ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(entity, X, Y, Z);
	}
	bool isPlayerInWater()
	{
		return ENTITY::IS_ENTITY_IN_WATER(PLAYER::PLAYER_PED_ID());
	}
	bool isEntityInWater(Entity entity)
	{
		return ENTITY::IS_ENTITY_IN_WATER(entity);
	}
	Vector3 getPlayerPosition()
	{
		return ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
	}
	void setCoords(Entity entity, Vector3 pos)
	{
		ENTITY::SET_ENTITY_COORDS(entity, pos.x, pos.y, pos.z,
			true, true, true, false);
	}
	Vector3 getRotation(Entity entity, int rotationOrder)
	{
		return ENTITY::GET_ENTITY_ROTATION(entity, rotationOrder);
	}
	void setRotation(Entity entity, Vector3 rotation, int rotationOrder)
	{
		ENTITY::SET_ENTITY_ROTATION(entity, rotation.x, rotation.y, rotation.z, rotationOrder, 1);
	}
}