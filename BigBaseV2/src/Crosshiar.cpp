#include "common.hpp"
#include "natives.hpp"
#include "gui.hpp"
#include <imgui.h>
#include <imgui_internal.h>
#include <d3d11.h>
#include <renderer.hpp>
#include "./Math/Math.hpp"

using namespace GRAPHICS;

namespace crosshiar
{
	void Normal()//while
	{
		DRAW_RECT(0.5f, 0.5f, 0.02f, 0.002f, 255, 255, 255, 255);
		DRAW_RECT(0.5f, 0.5f, 0.001f, 0.03f, 255, 255, 255, 255);
	}

	void Hit()//blue
	{
		DRAW_RECT(0.5f, 0.5f, 0.02f, 0.002f, 0, 140, 255, 255);
		DRAW_RECT(0.5f, 0.5f, 0.001f, 0.03f, 0, 140, 255, 255);
	}

	void Hold()//red
	{
		DRAW_RECT(0.5f, 0.5f, 0.02f, 0.002f, 255, 0, 0, 255);
		DRAW_RECT(0.5f, 0.5f, 0.001f, 0.03f, 255, 0, 0, 255);
	}
}

namespace Dotbox
{
	void Normal()//while
	{
		DRAW_RECT(0.5f, 0.5f, 0.004f, 0.008f, 255, 255, 255, 255);
		DRAW_RECT(0.5f, 0.5f, 0.004f, 0.008f, 255, 255, 255, 255);
	}

	void Hit()//blue
	{
		DRAW_RECT(0.5f, 0.5f, 0.004f, 0.008f, 0, 140, 255, 255);
		DRAW_RECT(0.5f, 0.5f, 0.004f, 0.008f, 0, 140, 255, 255);
	}
	void Hold()//red
	{
		DRAW_RECT(0.5f, 0.5f, 0.004f, 0.008f, 255, 0, 0, 255);
		DRAW_RECT(0.5f, 0.5f, 0.004f, 0.008f, 255, 0, 0, 255);
	}
}