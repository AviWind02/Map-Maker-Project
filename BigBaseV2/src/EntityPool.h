#pragma once
namespace EntityPool
{
	void setObjectPool(const char* prop);
	void setVehiclePool(const char* prop);
	void setPedPool(const char* prop);

	const char* getObjectPool();
	const char* getVehiclePool();
	const char* getPedPool();

	int getObjectPoolNum();
	int getVehiclePoolNum();
	int getPedPoolNum();
}
