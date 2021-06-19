#pragma once
namespace EntityPool
{
	void setObjectPool(const char* prop, Object object);
	void setVehiclePool(const char* prop, Vehicle vehicle);
	void setPedPool(const char* prop, Ped ped);


	extern const char* ObjectPoolName[682];
	extern const char* VehiclePoolName[682];
	extern const char* PedPoolName[682];


	extern Object ObjectSpawned[682];
	extern Vehicle VehicleSpawned[682];
	extern Ped PedSpawned[682];

	const char* getObjectPool();
	const char* getVehiclePool();
	const char* getPedPool();

	int getObjectPoolNum();
	int getVehiclePoolNum();
	int getPedPoolNum();
	int getTotalPoolNum();

	void DevBlock();
}
