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
#include "EntityControl.h"
#include "CamMode.h"
#include "EditEntity.h"
#include "CamControl.h"
#include "EntityMenu.h"
#include "EntityPool.h"



/*
Attach Option
Edit Placement option 
A bunch of random edit functions for all entity
Vehicle LSC
Object Edit
Ped Functions

*/
namespace EntityMenu
{
	namespace EditPlacement
	{

		void Placement(Entity Handle, Coords rotation, bool toggle)
		{
			Vector3 EntityPOS = EntityEdit::Get_Position(Handle);
			switch (rotation)
			{
			case X:
				toggle ? EntityPOS.x-- : EntityPOS.x++;
				break;
			case Y:
				toggle ? EntityPOS.y-- : EntityPOS.y++;
				break;
			case Z:
				toggle ? EntityPOS.z-- : EntityPOS.z++;
				break;
			}

			EntityEdit::setCoords(Handle, EntityPOS);

		}
	}
	namespace EditAttach
	{
	
		void Attach(Entity Handle, Entity Handle2)
		{
			EntityControl::AttachEntityToEntity(Handle, Handle2, {0, 0, 0}, 0);
		}
		bool Attched(Entity Handle)
		{
			return ENTITY::IS_ENTITY_ATTACHED(Handle);
		}
		void Placement(Entity Handle, Entity Handle2, Coords rotation, bool toggle)
		{
			Entity Attched = ENTITY::GET_ENTITY_ATTACHED_TO(Handle);

			
			Vector3 coords = EntityEdit::GetOffsetInWorldCoords(Handle, EntityEdit::Get_Position(Handle));
			switch (rotation)
			{
			case X:
				toggle ? coords.x-- : coords.x++;
				break;
			case Y:
				toggle ? coords.y-- : coords.y++;
				break;
			case Z:
				toggle ? coords.z-- : coords.z++;
				break;
			}

			EntityControl::AttachEntityToEntity(Handle, Handle2, coords, 0);
		}
	}
	namespace TestMenu
	{
		int pickkede;
		void Tick()
		{
			
			for (int i = 1; i < EntityPool::getObjectPoolNum(); i++)
				if (ENTITY::DOES_ENTITY_EXIST(EntityPool::ObjectSpawned[i]))
				{
					if (ImGui::Button(EntityPool::ObjectPoolName[i]))
					{
						EditAttach::Attach(EntityPool::ObjectSpawned[1], EntityPool::ObjectSpawned[i]);
						AddLog(EntityPool::ObjectPoolName[1]);
						AddLog(EntityPool::ObjectPoolName[i]);
						pickkede = i;
					}
				}
			if (ImGui::Button("X"))
				EditAttach::Placement(EntityPool::ObjectSpawned[0], EntityPool::ObjectSpawned[pickkede], X, true);
			
		}
	}
}