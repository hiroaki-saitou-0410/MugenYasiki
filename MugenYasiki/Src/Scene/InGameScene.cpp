#include "InGameScene.h"

InGameScene::InGameScene()
{
	//�e�C���X�^���X
	gamenManager = GameManager::GetInstanse();
	inputManager = InputManager::GetInstanse();

	SceneManager::GetInstanse()->SetNextScene(InGame);
	textureMnager->LoadSceneTexture(InGame);
}

InGameScene::~InGameScene()
{
	textureMnager->DeleteSceneTexture();
}

void InGameScene::Exec()
{
}

void InGameScene::Draw()
{
}

bool InGameScene::IsEnd() const
{
	return (FinishedScene);
}
