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



namespace EntityPool
{// i may be wrong but each entity maybe about 1000 Kibibit
	int ObjectLimt = 2046;//Mb i might be wrong tho

	int ObjectPool;
	int VehiclePool;
	int PedPool;

	const char* ObjectPoolName[682];
	const char* VehiclePoolName[682];
	const char* PedPoolName[682];

	Object ObjectSpawned[682];
	Vehicle VehicleSpawned[682];
	Ped PedSpawned[682];

	void setObjectPool(const char* prop, Object object)
	{
		ObjectPool += 1;
		ObjectPoolName[ObjectPool] = prop;
		ObjectSpawned[ObjectPool] = object;
		
	}
	void setVehiclePool(const char* prop, Vehicle vehicle)
	{
		VehiclePool += 1;
		VehiclePoolName[VehiclePool] = prop;
		VehicleSpawned[VehiclePool] = vehicle;
	

	}
	void setPedPool(const char* prop, Ped ped)
	{
		PedPool += 1;
		PedPoolName[PedPool] = prop;
		PedSpawned[PedPool] = ped;
	
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
	int getTotalPoolNum()
	{
		return PedPool + VehiclePool + ObjectPool;
	}
	void DevBlock()
	{
		for (int i = 0; i < getObjectPoolNum(); i++)
			SmallWindow("Prop", getObjectPool(), i);
		for (int i = 0; i < getPedPoolNum(); i++)
			SmallWindow("Ped", getPedPool(), i);
		for (int i = 0; i < getVehiclePoolNum(); i++)
			SmallWindow("Vehicle", getVehiclePool(), i);
	}
}
