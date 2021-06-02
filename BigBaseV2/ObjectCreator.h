#pragma once
#include <gta\natives.hpp>
namespace Objectcreator
{
	void spawnObject(const char* objectName, Vector3 pos = CamScript::Mycoord());
	void spawnVehicle(const char* vehicleName, Vector3 pos = CamScript::Mycoord());
	void spawnPed(const char* pedName, Vector3 pos = CamScript::Mycoord());
	void spawnEntity(const char* Entity, Vector3 pos = CamScript::Mycoord());
}