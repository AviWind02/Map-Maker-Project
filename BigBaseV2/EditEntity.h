#include "natives.hpp"
namespace EntityEdit
{
	void setAsMission(Entity handle);
	void setNoLongerNeeded(Entity handle);
	void setCanBeDamaged(Entity handle, bool damage);
	void setCollision(Entity handle, bool collision);
	void setDynamic(Entity handle, bool dynamic);
	void setHeading(Entity handle, float head);
	void setHealth(Entity handle, int health);
	void setInvincible(Entity handle, bool invincible);
	void setLight(Entity handle, bool light);
	void setMaxSpeed(Entity handle, float speed);
	void setDamageByPlayerOnly(Entity handle, bool damage);
	void setDamageType(Entity handle, bool bulletProof, bool fireProof,
		bool explosionProof, bool collisionProof, bool meleeProof,
		bool steamProof, bool smokeProof, bool drownProof);
	void setVisible(Entity handle, bool visible);
	void setVisible(Entity handle, bool visible);
	void setVelocity(Entity handle, Vector3 velocity);
	void setGravity(Entity handle, bool gravity);
	void setLOD(Entity handle, int LOD);
	void setAlpha(Entity handle, int alpha);
	void resetAlpha(Entity handle);
	void setPreRender(Entity handle);
	void setRenderScroeched(Entity handle);
	Vector3 Get_Position(Entity entity);
	bool is_it_there(Entity entity, Vector3 pos);
	Vector3 GetOffsetInWorldCoords(Entity entity, Vector3 offset);
	Vector3 GetOffsetInWorldCoords(Entity entity, float X, float Y, float Z);
	bool isPlayerInWater();
	bool isEntityInWater(Entity entity);
	Vector3 getPlayerPosition();
	void setCoords(Entity entity, Vector3 pos);
	Vector3 getRotation(Entity entity, int rotationOrder = 2);
	void setRotation(Entity entity, Vector3 rotation, int rotationOrder = 2);
	Vector3 offsetFromEntityGivenWorld(Entity entity, Vector3 coord);

}
