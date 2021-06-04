#include "common.hpp"
#include "natives.hpp"
#include "gui.hpp"
#include <imgui.h>
#include <imgui_internal.h>
#include <d3d11.h>
#include <renderer.hpp>
#include <features.hpp>
#include "../CamMode.h"
#include "../ObjectCreator.h"
#include "./CamUI.h"
#include "../CamControl.h"
#include "./EntityPool.h"

using namespace big;

bool FirstLoad;

void Test()
{
    if (!FirstLoad)
        AddLog("Loaded!");
    FirstLoad = true;
}
bool CamTicked;
void MainMenuBase()
{
    Test();
    DrawLogBox("Log (X to move)");
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(400, 600));
    ImGui::PushStyleColor(ImGuiCol_WindowBg, Black);
    if (ImGui::Begin("Object-Manager"))
    {
        if (CamTicked)
        {
            CamMode::controlTick();
            lockcontrols();
            crosshiar::Tick();
        }

        if (ImGui::Button("Un-Inject"))
            g_running = false;
        if (ImGui::Button("CamTick"))
        {
            CamMode::Tick();
            CamTicked = true;
        }
        if (ImGui::Button("Stop CamTick"))
        {
            CamMode::stopTick();
            CamTicked = false;
        }
        if (ImGui::Button("Spawn object"))
            Objectcreator::spawnEntity("prop_windmill_01");
        if (ImGui::Button("Spawn Vehicle"))
            Objectcreator::spawnEntity("adder");
        if (ImGui::Button("Spawn ped"))
            Objectcreator::spawnEntity("a_c_cat_01");

        CamUI::Tick();
        ControlWhileHeld::Tick();
        EntityPool::DevBlock();
    }
    ImGui::PopStyleColor();
    ImGui::End();
}