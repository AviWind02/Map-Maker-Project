#pragma once
namespace EntityPool
{
	void setObjectPool(const char* prop, Object object);
	void setVehiclePool(const char* prop, Vehicle vehicle);
	void setPedPool(const char* prop, Ped ped);

	const char* getObjectPool();
	const char* getVehiclePool();
	const char* getPedPool();

	int getObjectPoolNum();
	int getVehiclePoolNum();
	int getPedPoolNum();
	int getTotalPoolNum();

	void DevBlock();
}
