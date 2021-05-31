#include "TitleScene.h"

enum 
{
	STEP_LOGO,
	STEP_INPUT,
	STEP_END
};

TitleScene::TitleScene()
{
	//各インスタンス
	gamenManager = GameManager::GetInstance();
	inputManager = InputManager::GetInstance();
	textureManager = TextureManager::GetInstance();
	soundManager = SoundManager::GetInstance();

	SceneManager::GetInstance()->SetNextScene(Title);
	textureManager->LoadSceneTexture(Title);
	soundManager->LoadSceneSound(Title);
	m_Step = STEP_LOGO;
	number = 0;
}

TitleScene::~TitleScene()
{
	textureManager->DeleteSceneTexture();
	//soundManager->DeleteSceneSound()
	//一時的に変更
	DeleteSoundMem(soundManager->GetSoundDate(titleSound));
}

void TitleScene::Exec()
{
	switch (m_Step)
	{
	case STEP_LOGO:Step_Logo();
		Sound();
		break;
	case STEP_INPUT:Step_Input(); break;
	default:break;
	}	
	
}

void TitleScene::Draw()
{
	switch (number)
	{
	case 0:DrawGraph(0, 0, textureManager->GetTextureDate(titleTexture0), FALSE);
		break;
	case 1:DrawGraph(0, 0, textureManager->GetTextureDate(titleTexture1), FALSE);
		break;
	case 2:DrawGraph(0, 0, textureManager->GetTextureDate(titleTexture2), FALSE);
		break;
	default:
		break;
	}
	

	if (inputManager->IsKeyPushed(KEY_INPUT_1))
	{
		number++;
	}
	if (number==3)
	{
		number = 0;
	}
	//DrawGraph(0, 0, textureManager->GetTextureDate(titleTexture2), FALSE);
}

void TitleScene::Sound()
{
	soundManager->PlaySceneSound(soundManager->GetSoundDate(titleSound), DX_PLAYTYPE_LOOP, TRUE, 255);
}

bool TitleScene::IsEnd() const
{
	return (m_Step == STEP_END);
}

void TitleScene::Step_Logo()
{
	m_Step = STEP_INPUT;
}

void TitleScene::Step_Input()
{
	if (inputManager->IsKeyPushed(KEY_INPUT_RETURN))
	{
		if (CheckSoundMem(soundManager->GetSoundDate(titleSound)) == TRUE)
		{
			StopSoundMem(soundManager->GetSoundDate(titleSound));
		}
		m_Step = STEP_END;
		SceneManager::GetInstance()->SetNextScene(InGame);
	}
}
