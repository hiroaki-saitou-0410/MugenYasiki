#include "DxLib.h"
#include"Definition.h"
#include"Manager/GameManager.h"
#include"Manager/InputManager.h"
#include"Manager/SceneManager.h"
#include"Manager/TextureManager.h"
#include"Manager/SoundManager.h"
#include"Player/Player.h"

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	SetOutApplicationLogValidFlag(FALSE);
	ChangeWindowMode(TRUE);
	SetGraphMode(WindowWidth, WindowHeight,32);
	SetBackgroundColor(0, 0, 0);
	SetMainWindowText("無限屋敷");
	if (DxLib_Init() == -1) { return -1; }

	SetDrawScreen(DX_SCREEN_BACK);

	//管理クラス
	InputManager::CreateInstance();
	InputManager* inputManager = InputManager::GetInstance();
	GameManager::CreateInstance();
	TextureManager::CreateInstance();
	SoundManager::CreateInstance();
	SceneManager::CreateInstance();
	SceneManager* sceneManager = SceneManager::GetInstance();
	

	while (ProcessMessage() == 0 && inputManager->IsKeyPushed(KEY_INPUT_ESCAPE)==0)
	{
	
		inputManager->UpdateKeyStatus();

		ClearDrawScreen();
		clsDx();

		//===========
		//処理関数呼び出し
		//===========
		sceneManager->Exec();

		sceneManager->Draw();

		ScreenFlip();
	
	}
	GameManager::DeleteInstance();
	InputManager::DeleteInstance();
	TextureManager::DeleteInstance();
	SoundManager::DeleteInstance();
	SceneManager::DeleteInstance();
	inputManager = nullptr;
	sceneManager = nullptr;
	DxLib_End();
	return 0;
}