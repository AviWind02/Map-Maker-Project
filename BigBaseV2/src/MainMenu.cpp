#include "common.hpp"
#include "natives.hpp"
#include "gui.hpp"
#include <imgui.h>
#include <imgui_internal.h>
#include <d3d11.h>
#include <renderer.hpp>
#include <features.hpp>
#include "../CamMode.h"
using namespace big;

void getEntityAimAt();
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
    getEntityAimAt();
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(400, 600));
    ImGui::PushStyleColor(ImGuiCol_WindowBg, Black);
    if (ImGui::Begin("Object-Manager"))
    {
        if (CamTicked)
        {
            CamMode::controlTick();
            lockcontrols();
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
    }
    ImGui::PopStyleColor();
    ImGui::End();
}