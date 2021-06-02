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
namespace CamScript
{
	void setCamStat();
	Cam getCam();
	void setCamScript();
	void renderCamScript(bool render);
	void stopCamScript();
	Vector3 Cameracoord();
	Vector3 Mycoord();

	namespace Control
	{
		void setCamCoord();
		void forward();
		void backward();
		void Tick();
	}

	namespace misc
	{
		void setPlayerAtCam();
		void setFrameHide();
	}
}
namespace CamMode
{
	void Tick();
	void stopTick();
	void controlTick();

}