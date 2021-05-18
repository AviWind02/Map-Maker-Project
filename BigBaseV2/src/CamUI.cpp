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
#include "EntityPool.h"


using namespace big;



namespace CamUI
{
	void addText(std::string text, std::string Right, short line)
	{
		float YPostion = 20.f * line;
		ImVec2 TextPos{ ImGui::GetCursorScreenPos().x + 6.f, ImGui::GetCursorScreenPos().y + YPostion };
		Text(text, White, TextPos, NULL, false);
		if(Right != "NULL")
			Text(Right, White, { TextPos.x + 4.f, TextPos.y }, NULL, true);

	}
	void EntityPool()
	{
		addText("Object Pool: ", std::to_string(EntityPool::getObjectPoolNum()), 0);
		addText("Vehicle Pool: ", std::to_string(EntityPool::getVehiclePoolNum()), 1);
		addText("Ped Pool: ", std::to_string(EntityPool::getPedPoolNum()), 2);

	}
	void EntityType()
	{

	}
	void EntityInfo()
	{

	}
	void misc()
	{

	}

	void Tick()//normal move-able window for testing find spot later
	{
		ImGui::PushStyleColor(ImGuiCol_WindowBg, Black);
		if (ImGui::Begin("Entity Info"))
		{
			EntityPool();
		}
		ImGui::PopStyleColor();
		ImGui::End();
	}
}