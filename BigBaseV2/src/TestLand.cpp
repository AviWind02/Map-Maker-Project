#include "common.hpp"
#include "natives.hpp"
#include "gui.hpp"
#include <imgui.h>
#include <imgui_internal.h>
#include <d3d11.h>
#include <renderer.hpp>
#include <features.hpp>
#include <Raycast.h>
#include <Crosshiar.hpp>

using namespace big;

void getEntityAimAt()
{

	if (Cast::isEntityHitVehicle())
		crosshiar::Hit();
	else
		crosshiar::Normal();
}