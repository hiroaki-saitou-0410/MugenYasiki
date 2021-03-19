#include "InGameScene.h"

Player player;

InGameScene::InGameScene()
{
	//各インスタンス
	gamenManager = GameManager::GetInstance();
	inputManager = InputManager::GetInstance();
	textureManager = TextureManager::GetInstance();

	SceneManager::GetInstance()->SetNextScene(InGame);
	textureManager->LoadSceneTexture(InGame);

	m_RightMotionMax = right_Animation7;
	m_ActSpeed=9;
	m_ActStop= m_ActSpeed;
	m_WaitIndex= right_Animation0;
}

InGameScene::~InGameScene()
{
	textureManager->DeleteSceneTexture();
}

void InGameScene::Exec()
{
	player.Exec();
}

void InGameScene::Draw()
{
	//BackGround
	DrawGraph(0, 0, textureManager->GetTextureDate(texture1), TRUE);

	//Player
	DrawGraph(player.SetPosX(), WindowWidth - 700, textureManager->GetTextureDate(m_WaitIndex), TRUE);
	
	if (--m_ActStop <= 0)
	{
		m_WaitIndex++;
		m_ActStop = m_ActSpeed;
		m_WaitIndex %= m_RightMotionMax;
		if (m_WaitIndex == 0)
		{
			m_WaitIndex = right_Animation0;
		}
	}
	
	

	//Orc
	DrawGraph(1400, WindowWidth-750, textureManager->GetTextureDate(texture0), TRUE);

	//Text_Bar
	DrawGraph(0, WindowWidth - 283, textureManager->GetTextureDate(texture2), TRUE);
	//Bar_
	DrawGraph(0, WindowWidth-283, textureManager->GetTextureDate(texture3), TRUE);

	//DrawGraph(0, 0, textureManager->GetTextureDate(texture5), TRUE);
}

bool InGameScene::IsEnd() const
{
	return (FinishedScene);
}
