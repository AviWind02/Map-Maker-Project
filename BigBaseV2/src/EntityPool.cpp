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

using namespace big;

int ObjectLimt = 2048;

int ObjectPool;
int VehiclePool;
int PedPool;

const char* ObjectPoolName[];
const char* VehiclePoolName[];
const char* PedPoolName[];

namespace EntityPool
{

	void setObjectPool(const char* prop)
	{
		ObjectPool += 1;
		ObjectPoolName[ObjectPool] = prop;
	}
	void setVehiclePool(const char* prop)
	{
		VehiclePool += 1;
		VehiclePoolName[VehiclePool] = prop;
	}
	void setPedPool(const char* prop)
	{
		PedPool += 1;
		PedPoolName[PedPool] = prop;
	}
	const char* getObjectPool()
	{
		for(int i = 0; i < ObjectPool; i++)
			return ObjectPoolName[ObjectPool];
	}
	const char* getVehiclePool()
	{
		for (int i = 0; i < VehiclePool; i++)
			return VehiclePoolName[VehiclePool];
	}
	const char* getPedPool()
	{
		for (int i = 0; i < PedPool; i++)
			return PedPoolName[PedPool];
	}
	int getObjectPoolNum()
	{
		return ObjectPool;
	}
	int getVehiclePoolNum()
	{
		return VehiclePool;
	}
	int getPedPoolNum()
	{
		return PedPool;
	}
}
