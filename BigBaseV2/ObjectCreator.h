#pragma once
#include <gta\natives.hpp>
namespace Objectcreator
{
	void spawnObject(const char* objectName, Vector3 pos);
	void spawnVehicle(const char* vehicleName, Vector3 pos);
	void spawnPed(const char* pedName, Vector3 pos);
	void spawnEntity(const char* EntityName);
}