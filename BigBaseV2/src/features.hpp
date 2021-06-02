#pragma once
#include "common.hpp"

namespace big::features
{
	void run_tick();
	void script_func();
}
#define IM_PRINTFARGS(FMT)
char* StringToChar(std::string string);
void AddLog(const char* fmt, ...) IM_PRINTFARGS(2);
void DrawLogBox(const char* title);
void lockcontrols();

