#include "common.hpp"
#include "fiber_pool.hpp"
#include "gta/player.hpp"
#include "gta_util.hpp"
#include "gui.hpp"
#include "logger.hpp"
#include "memory/module.hpp"
#include "memory/pattern.hpp"
#include "natives.hpp"
#include "pointers.hpp"
#include "renderer.hpp"
#include "script.hpp"
#include "renderer.hpp"
#include <imgui.h>
#include <StackWalker.h>
#include <features.hpp>
void MainMenuBase();
ImVec2 add(ImVec2* vectorA, ImVec2* vectorB) {
	ImVec2 result;
	result.x = vectorA->x;
	result.y = vectorA->y;
	result.x += vectorB->x;
	result.y += vectorB->y;

	return result;
}
namespace big
{
    bool doFunctionTick;


	void gui::dx_init()
	{
		auto& style = ImGui::GetStyle();
		style.WindowPadding = { 10.f, 10.f };
		style.PopupRounding = 0.f;
		style.FramePadding = { 8.f, 4.f };
		style.ItemSpacing = { 10.f, 8.f };
		style.ItemInnerSpacing = { 6.f, 6.f };
		style.TouchExtraPadding = { 0.f, 0.f };
		style.IndentSpacing = 21.f;
		style.ScrollbarSize = 15.f;
		style.GrabMinSize = 8.f;
		style.WindowBorderSize = 1.f;
		style.ChildBorderSize = 0.f;
		style.PopupBorderSize = 1.f;
		style.FrameBorderSize = 0.f;
		style.TabBorderSize = 0.f;
		style.WindowRounding = 0.f;
		style.ChildRounding = 0.f;
		style.FrameRounding = 0.f;
		style.ScrollbarRounding = 0.f;
		style.GrabRounding = 0.f;
		style.TabRounding = 0.f;
		style.WindowTitleAlign = { 0.5f, 0.5f };
		style.ButtonTextAlign = { 0.5f, 0.5f };
		style.DisplaySafeAreaPadding = { 3.f, 3.f };

		auto& colors = style.Colors;
		colors[ImGuiCol_Text] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		colors[ImGuiCol_TextDisabled] = ImVec4(1.00f, 0.90f, 0.19f, 1.00f);
		colors[ImGuiCol_WindowBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);
		colors[ImGuiCol_ChildBg] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_PopupBg] = ImVec4(0.08f, 0.08f, 0.08f, 0.94f);
		colors[ImGuiCol_Border] = ImVec4(0.30f, 0.30f, 0.30f, 0.50f);
		colors[ImGuiCol_BorderShadow] = ImVec4(0.00f, 0.00f, 0.00f, 0.00f);
		colors[ImGuiCol_FrameBg] = ImVec4(0.21f, 0.21f, 0.21f, 0.54f);
		colors[ImGuiCol_FrameBgHovered] = ImVec4(0.21f, 0.21f, 0.21f, 0.78f);
		colors[ImGuiCol_FrameBgActive] = ImVec4(0.28f, 0.27f, 0.27f, 0.54f);
		colors[ImGuiCol_TitleBg] = ImVec4(0.17f, 0.17f, 0.17f, 1.00f);
		colors[ImGuiCol_TitleBgActive] = ImVec4(0.19f, 0.19f, 0.19f, 1.00f);
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4(0.00f, 0.00f, 0.00f, 0.51f);
		colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);
		colors[ImGuiCol_ScrollbarBg] = ImVec4(0.02f, 0.02f, 0.02f, 0.53f);
		colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
		colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.41f, 0.41f, 0.41f, 1.00f);
		colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.51f, 0.51f, 0.51f, 1.00f);
		colors[ImGuiCol_CheckMark] = ImVec4(1.00f, 1.00f, 1.00f, 1.00f);
		colors[ImGuiCol_SliderGrab] = ImVec4(0.34f, 0.34f, 0.34f, 1.00f);
		colors[ImGuiCol_SliderGrabActive] = ImVec4(0.39f, 0.38f, 0.38f, 1.00f);
		colors[ImGuiCol_Button] = ImVec4(0.41f, 0.41f, 0.41f, 0.74f);
		colors[ImGuiCol_ButtonHovered] = ImVec4(0.41f, 0.41f, 0.41f, 0.78f);
		colors[ImGuiCol_ButtonActive] = ImVec4(0.41f, 0.41f, 0.41f, 0.87f);
		colors[ImGuiCol_Header] = ImVec4(0.37f, 0.37f, 0.37f, 0.31f);
		colors[ImGuiCol_HeaderHovered] = ImVec4(0.38f, 0.38f, 0.38f, 0.37f);
		colors[ImGuiCol_HeaderActive] = ImVec4(0.37f, 0.37f, 0.37f, 0.51f);
		colors[ImGuiCol_Separator] = ImVec4(0.38f, 0.38f, 0.38f, 0.50f);
		colors[ImGuiCol_SeparatorHovered] = ImVec4(0.46f, 0.46f, 0.46f, 0.50f);
		colors[ImGuiCol_SeparatorActive] = ImVec4(0.46f, 0.46f, 0.46f, 0.64f);
		colors[ImGuiCol_ResizeGrip] = ImVec4(0.26f, 0.26f, 0.26f, 1.00f);
		colors[ImGuiCol_ResizeGripHovered] = ImVec4(0.31f, 0.31f, 0.31f, 1.00f);
		colors[ImGuiCol_ResizeGripActive] = ImVec4(0.35f, 0.35f, 0.35f, 1.00f);
		colors[ImGuiCol_Tab] = ImVec4(0.21f, 0.21f, 0.21f, 0.86f);
		colors[ImGuiCol_TabHovered] = ImVec4(0.27f, 0.27f, 0.27f, 0.86f);
		colors[ImGuiCol_TabActive] = ImVec4(0.34f, 0.34f, 0.34f, 0.86f);
		colors[ImGuiCol_TabUnfocused] = ImVec4(0.10f, 0.10f, 0.10f, 0.97f);
		colors[ImGuiCol_TabUnfocusedActive] = ImVec4(0.15f, 0.15f, 0.15f, 1.00f);
		colors[ImGuiCol_PlotLines] = ImVec4(0.61f, 0.61f, 0.61f, 1.00f);
		colors[ImGuiCol_PlotLinesHovered] = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
		colors[ImGuiCol_PlotHistogram] = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
		colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
		colors[ImGuiCol_TextSelectedBg] = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);
		colors[ImGuiCol_DragDropTarget] = ImVec4(1.00f, 1.00f, 0.00f, 0.90f);
		colors[ImGuiCol_NavHighlight] = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
		colors[ImGuiCol_NavWindowingHighlight] = ImVec4(1.00f, 1.00f, 1.00f, 0.70f);
		colors[ImGuiCol_NavWindowingDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.20f);
		colors[ImGuiCol_ModalWindowDimBg] = ImVec4(0.80f, 0.80f, 0.80f, 0.35f);
	}
	void gui::dx_on_tick()
	{
		MainMenuBase();

	}
    void gui::script_on_tick()
    {
        
        if (g_gui.m_opened)
        {
			if (GetAsyncKeyState(VK_KEY_X))
				CONTROLS::DISABLE_ALL_CONTROL_ACTIONS(0);
		}
        
    }


	void gui::script_func()
	{

		while (true)
		{
            g_gui.script_on_tick();
			script::get_current()->yield();
		}
	}
}

void Text(std::string Text, ImVec4 Colour, ImVec2 Pos, ImFont* font = NULL, bool Right = false)
{
	if (font == NULL)
		font = ImGui::GetDefaultFont();

	ImGui::PushFont(font);
	if (Right)
		Pos.x = (ImGui::GetColumnWidth() - ImGui::CalcTextSize(StringToChar(Text)).x
			- ImGui::GetScrollX() - 2 * ImGui::GetStyle().ItemSpacing.x + Pos.x);

	ImGui::GetCurrentWindow()->DrawList->AddText({ Pos.x , Pos.y }, ImGui::GetColorU32(Colour), Text.c_str());
	ImGui::PopFont();
}

void RectFilled(ImVec4 Colour, ImVec2 Pos, ImVec2 Size, bool Filled = true)
{
	ImVec2 size = ImGui::CalcItemSize(ImVec2(Size.x, Size.y), 0.0f, 0.0f);
	const ImRect bb(ImVec2(Pos.x, Pos.y), add(&ImVec2(Pos.x, Pos.y), &size));


	if (!Filled)
		ImGui::GetCurrentWindow()->DrawList->AddRect(bb.Max, bb.Min, ImGui::GetColorU32(Colour));
	else
		ImGui::GetCurrentWindow()->DrawList->AddRectFilledMultiColor(bb.Max, bb.Min, ImGui::GetColorU32(Colour),
			ImGui::GetColorU32(Colour), ImGui::GetColorU32(Colour), ImGui::GetColorU32(Colour));
}
void Line(ImVec4 Colour, ImVec2 Pos, ImVec2 rotation, float Thinkness = 1.f, bool Filled = false)
{
	ImVec2 size = ImGui::CalcItemSize(ImVec2(rotation.x, rotation.y), 0.0f, 0.0f);
	const ImRect bb(ImVec2(Pos.x, Pos.y), add(&ImVec2(Pos.x, Pos.y), &size));

	ImGui::GetCurrentWindow()->DrawList->AddLine(bb.Max, bb.Min, ImGui::GetColorU32(Colour), Thinkness);
}
bool SetDescriptionPos = true;
void Infobox(std::string text, std::string textRight, short line)
{
	if (SetDescriptionPos)
	{
		ImGui::SetNextWindowPos(ImVec2(1433, 200));
		SetDescriptionPos = false;
	}
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(BlackLowAlpha));
	ImGui::SetNextWindowSize(ImVec2(433, 600));
	if (ImGui::Begin("Debug", 0, ImGuiWindowFlags_NoTitleBar))
	{
		float YPostion = 20.f * line;
		ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, ImGui::GetCursorScreenPos().y + YPostion };
		Text(text, White, { TextPos.x + 10.f, TextPos.y } );
		Text(textRight, White, { TextPos.x, TextPos.y }, NULL, true);
		Line(WhiteLowAlpha, { TextPos.x, TextPos.y }, ImVec2(400, 0));

	}
	ImGui::PopStyleColor();
	ImGui::End();
}
void SmallWindow(const char* windowName, std::string text, short line)
{
	if (SetDescriptionPos)
	{
		ImGui::SetNextWindowPos(ImVec2(1433, 200));
		SetDescriptionPos = false;
	}
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(BlackLowAlpha));
	ImGui::SetNextWindowSize(ImVec2(433, 600));
	if (ImGui::Begin(windowName))
	{
		float YPostion = 20.f * line;
		ImVec2 TextPos{ ImGui::GetCursorScreenPos().x - 4.f, ImGui::GetCursorScreenPos().y + YPostion };
		Text(text, White, { TextPos.x + 10.f, TextPos.y });

	}
	ImGui::PopStyleColor();
	ImGui::End();
}
std::string RemoveDPoint(float Float, char* text)
{
	char NameBuffer[50];
	sprintf(NameBuffer, "%.4g", Float);
	std::string nam = NameBuffer;
	return nam + text;
}