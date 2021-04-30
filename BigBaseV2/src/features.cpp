#include "common.hpp"
#include "features.hpp"
#include "logger.hpp"
#include "natives.hpp"
#include "script.hpp"
#include "gui.hpp"
#include <imgui.h>
#include <imgui_internal.h>
#include <d3d11.h>
#include <renderer.hpp>
namespace big
{
	void features::run_tick()
	{
	}

	void features::script_func()
	{
		while (true)
		{
			run_tick();
			script::get_current()->yield();
		}
	}
}
char* StringToChar(std::string string)
{
	return _strdup(string.c_str());
}
#define IM_PRINTFARGS(FMT)
ImGuiTextBuffer     Buf;
bool                ScrollToBottom;
void Clear() { Buf.clear(); }
std::string line = "\n";
void AddLog(const char* fmt, ...) IM_PRINTFARGS(2)
{
	va_list args;
	va_start(args, fmt);
	Buf.appendfv(StringToChar(fmt + line), args);
	va_end(args);
	ScrollToBottom = true;
}
bool SETDEBUGWINDOWPOS = true;
void DrawLogBox(const char* title)
{
	if (SETDEBUGWINDOWPOS)
	{
		ImGui::SetNextWindowSize(ImVec2(382, 156), ImGuiCond_FirstUseEver);
		ImGui::SetNextWindowPos(ImVec2(1512, 13), ImGuiCond_FirstUseEver);
		SETDEBUGWINDOWPOS = false;
	}
	ImGui::PushStyleColor(ImGuiCol_WindowBg, ImVec4(ImColor(0, 0, 0, 150)));
	ImGui::Begin(title, NULL, 0);
	ImGui::PopStyleColor();
	ImGui::TextUnformatted(Buf.begin());
	if (ScrollToBottom)
		ImGui::SetScrollHere(1.0f);
	ScrollToBottom = false;
	ImGui::End();
}
