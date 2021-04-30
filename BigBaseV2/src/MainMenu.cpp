#include "common.hpp"
#include "natives.hpp"
#include "gui.hpp"
#include <imgui.h>
#include <imgui_internal.h>
#include <d3d11.h>
#include <renderer.hpp>
#include <features.hpp>
using namespace big;

void getEntityAimAt();
bool FirstLoad;

void Test()
{
    if (!FirstLoad)
        AddLog("Loaded!");
    FirstLoad = true;
}
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
        if (ImGui::Button("Un-Inject"))
            g_running = false;
    }
    ImGui::PopStyleColor();
    ImGui::End();
}