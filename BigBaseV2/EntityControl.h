namespace EntityControl
{
	enum Rotation
	{
		Pitch,
		Roll,
		Yaw
	};
	void holdEntity(Entity Handle, float distance = 6.f, float Zhight = 0.1f);
	Vector3 getRotation(Entity Handle);
	void EditEntityRotation(Entity Handle, Rotation rotation, float rotate);
	void AttachEntityToEntity(Entity fromHandle, Entity toHandle, Vector3 coords, int boneindex);
	extern bool EntityLocked;

}