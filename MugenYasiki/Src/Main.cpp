#include "DxLib.h"
#include"Definition.h"


int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode(WindowHeight, WindowWidth,32);
	SetBackgroundColor(0, 0, 120);
	SetMainWindowText("無限屋敷");
	if (DxLib_Init() == -1) { return -1; }

	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		ClearDrawScreen();
		clsDx();

		//===========
		//処理関数呼び出し
		//===========


		ScreenFlip();
	}
	DxLib_End();
	return 0;
}