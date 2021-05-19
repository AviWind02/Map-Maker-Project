#pragma once
namespace Cast
{
	Entity getCastedEntity();
	Vector3 getSurfaceNormalCoord();
	Vector3 getEndCoord();
	BOOL hasRayHit();
	void getRay();
	bool isEntityHitPed();
	bool isEntityHitObject();
	bool isEntityHitVehicle();
	bool shouldEntityBeheld();//checks is entity is real etc

}