#include "ResultScene.h"

enum
{
	STEP_INTEXTURE,
	STEP_RESULT,
	STEP_END
};

ResultScene::ResultScene()
{
	gamenManager = GameManager::GetInstance();
	inputManager = InputManager::GetInstance();
	textureManager = TextureManager::GetInstance();
	soundManager = SoundManager::GetInstance();

	SceneManager::GetInstance()->SetNextScene(Result);
	textureManager->LoadSceneTexture(Result);
	soundManager->LoadSceneSound(Result);

	m_Step = STEP_RESULT;
}

ResultScene::~ResultScene()
{
}

bool ResultScene::IsEnd() const
{
	return (m_Step == STEP_END);
}

void ResultScene::Exec()
{
	switch (m_Step)
	{
	case STEP_INTEXTURE:Step_InTexture(); break;
	case STEP_RESULT:Step_Input(); break;
	default:break;
	}
}

void ResultScene::Draw()
{
	DrawString(200, 900, "リザルト", GetColor(255, 255, 255));
}

void ResultScene::Step_InTexture()
{
	m_Step = STEP_RESULT;
}

void ResultScene::Step_Input()
{
	if (inputManager->IsKeyPushed(KEY_INPUT_RETURN))
	{
		m_Step = STEP_END;
		SceneManager::GetInstance()->SetNextScene(Title);
	}
}
