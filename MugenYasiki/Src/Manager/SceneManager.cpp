#include"SceneManager.h"

SceneID SceneManager::m_NextSceneID = Scene_Invalid;

SceneManager::SceneManager()
	:m_pScene(nullptr)
{
	SetNextScene(Title);//Éøî≈à»ç~titleÇ…ñﬂÇ∑
	m_pScene = create_NextScene();
}

SceneManager::~SceneManager()
{
	delete m_pScene;
	m_pScene = nullptr;
}

void SceneManager::Exec()
{
	if (m_pScene == nullptr) { return ; }

	m_pScene->Exec();
	if (m_pScene->IsEnd())
	{
		delete m_pScene;
		m_pScene = create_NextScene();
	}
}

void SceneManager::Draw()
{
	if (m_pScene == nullptr) { return; }

	m_pScene->Draw();
}

void SceneManager::SetNextScene(SceneID next_)
{
	m_NextSceneID = next_;
}

SceneBase* SceneManager::create_NextScene()
{
	SceneBase* next = nullptr;
	switch (m_NextSceneID)		//Éøî≈à»ç~titleÇ…ñﬂÇ∑
	{
	case Title:
		next = new TitleScene();
		break;

	case InGame:
		next = new InGameScene();
		break;

	//case Result:
	//	break;

	default:
		break;
	}

	return next;
}