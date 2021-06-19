#pragma once
namespace EntityMenu
{
	enum Coords
	{
		X,
		Y,
		Z
	};
	namespace EditPlacement
	{

		void Placement(Entity Handle, Coords rotation, bool toggle);

	}
	namespace EditAttach
	{

		void Attach(Entity Handle, Entity Handle2);
		bool Attched(Entity Handle);
		void Placement(Entity Handle, Coords rotation, bool toggle);
			
	}
	namespace TestMenu
	{
		extern int pickkede;
		void Tick();
			
	}
	
}