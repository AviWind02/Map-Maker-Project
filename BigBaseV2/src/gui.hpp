#pragma once
#include "common.hpp"
#include "natives.hpp"
#include "gui.hpp"
#include <imgui.h>
#include <imgui_internal.h>
#include <d3d11.h>
#include <renderer.hpp>
namespace big
{
	class gui
	{
	public:
		void dx_init();
		void dx_on_tick();

		void script_init();
		void script_on_tick();
		static void script_func();
	public:
		bool m_opened{};
	};

	inline gui g_gui;
}

static ImVec4 WatermelonRed = ImColor(251, 5, 56, 255);
static ImVec4 WatermelonPick = ImColor(251, 8, 89, 255);
static ImVec4 MelonWhite = ImColor(242, 194, 169, 255);
static ImVec4 MelonWhiteLowAlpha = ImColor(242, 194, 169, 155);
static ImVec4 MelonSeedBrown = ImColor(73, 49, 9, 255);
static ImVec4 MelonOrange = ImColor(243, 87, 43, 255);
static ImVec4 RedColour = ImColor(245, 2, 2, 255);
static ImVec4 White = ImColor(255, 255, 255, 255);
static ImVec4 WhiteLowAlpha = ImColor(255, 255, 255, 155);
static ImVec4 HotPink = ImColor(255, 105, 180, 255);
static ImVec4 Black = ImColor(0, 0, 0, 255);
static ImVec4 BlackLowAlpha = ImColor(0, 0, 0, 100);
static ImVec4 ClearColour = ImColor(0, 0, 0, 0);
static ImVec4 Orange = ImColor(249, 87, 0, 255);
static ImVec4 BlueColour = ImColor(0, 164, 204, 255);
static ImVec4 LightBlue = ImColor(0, 140, 255, 255);
static ImVec4 OrangeLowAlpha = ImColor(0, 164, 204, 155);
static ImVec4 BrownSugar = ImColor(160, 120, 85, 255);
static ImVec4 Beige = ImColor(212, 185, 150, 155);
static ImVec4 BrownSugarAlpha = ImColor(160, 120, 85, 155);
static ImVec4 CherryTomato = ImColor(233, 75, 60, 255);
static ImVec4 PANTONEBlackC = ImColor(45, 41, 38, 255);
static ImVec4 PANTONEBlackCLowAlpha = ImColor(160, 120, 85, 155);
static ImVec4 SeaFoam = ImColor(112, 235, 204, 255);
static ImVec4 DeepAqua = ImColor(0, 59, 70, 255);
static ImVec4 wave = ImColor(102, 165, 173, 255);
static ImVec4 DeepAqualowAplha = ImColor(0, 59, 70, 155);
static ImVec4 BabyBlue = ImColor(137, 207, 240, 255);
static ImVec4 AcidGreen = ImColor(176, 191, 26, 255);
static ImVec4 AcidGreenlowAlpha = ImColor(176, 191, 26, 155);
static ImVec4 DrakPurple = ImColor(133, 22, 233);
static ImVec4 DrakLimeGreen = ImColor(122, 233, 22);
static ImVec4 DrakPurpleLowAlpha = ImColor(133, 22, 233, 155);
static ImVec4 Grey = ImColor(0, 0, 0, 175);

#define IsKeyDown(key) GetAsyncKeyState(key)
#define VK_NOTHING	0x00				/*NULL*/
#define VK_KEY_0	0x30                //('0')	0
#define VK_KEY_1	0x31                //('1')	1
#define VK_KEY_2	0x32                //('2')	2
#define VK_KEY_3	0x33                //('3')	3
#define VK_KEY_4	0x34                //('4')	4
#define VK_KEY_5	0x35                //('5')	5
#define VK_KEY_6	0x36                //('6')	6
#define VK_KEY_7	0x37                //('7')	7
#define VK_KEY_8	0x38                //('8')	8
#define VK_KEY_9	0x39                //('9')	9
#define VK_KEY_A	0x41                //('A')	A
#define VK_KEY_B	0x42                //('B')	B
#define VK_KEY_C	0x43                //('C')	C
#define VK_KEY_D	0x44                //('D')	D
#define VK_KEY_E	0x45                //('E')	E
#define VK_KEY_F	0x46                //('F')	F
#define VK_KEY_G	0x47                //('G')	G
#define VK_KEY_H	0x48                //('H')	H
#define VK_KEY_I	0x49                //('I')	I
#define VK_KEY_J	0x4A                //('J')	J
#define VK_KEY_K	0x4B                //('K')	K
#define VK_KEY_L	0x4C                //('L')	L
#define VK_KEY_M	0x4D                //('M')	M
#define VK_KEY_N	0x4E                //('N')	N
#define VK_KEY_O	0x4F                //('O')	O
#define VK_KEY_P	0x50                //('P')	P
#define VK_KEY_Q	0x51                //('Q')	Q
#define VK_KEY_R	0x52                //('R')	R
#define VK_KEY_S	0x53                //('S')	S
#define VK_KEY_T	0x54                //('T')	T
#define VK_KEY_U	0x55                //('U')	U
#define VK_KEY_V	0x56                //('V')	V
#define VK_KEY_W	0x57                //('W')	W
#define VK_KEY_X	0x58                //('X')	X
#define VK_KEY_Y	0x59                //('Y')	Y
#define VK_KEY_Z	0x5A                //('Z')	Z