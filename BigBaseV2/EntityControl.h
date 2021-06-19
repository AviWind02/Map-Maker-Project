namespace EntityControl
{
	enum Rotation
	{
		Pitch,
		Roll,
		Yaw
	};
	extern float entityDistanceFromCam, hightFromCrosshire;

	void holdEntity(Entity Handle, float distance = entityDistanceFromCam, float Zhight = hightFromCrosshire);
	
	void EditEntityRotation(Entity Handle, Rotation rotation, bool toggle);
	void AttachEntityToEntity(Entity fromHandle, Entity toHandle, Vector3 coords, int boneindex);
	extern bool EntityLocked;
	void Delete(Entity Handle);

	namespace quickFunction
	{
		void Attach(Entity fromHandle, Entity toHandle, Vector3 coords = { 0, 0, 0 });
	}
}