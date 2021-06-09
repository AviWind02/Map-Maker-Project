#pragma once
namespace ControlWhileHeld
{
	extern Entity LockedEntity;
	void pickUpObject();
	void editEntityRoll();
	void editEntityPitch();
	void editEntityYaw();
	void deleteEntity();
	extern bool LockMoveControl;
	bool ctrlDown();
	void Tick();
}