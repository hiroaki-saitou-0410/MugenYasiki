#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include"../Definition.h"
#include"../Singleton.h"
#include"../Scene/InGameScene.h"
#include"../Scene/TitleScene.h"
#include"../Scene/ResultScene.h"
#include"../Scene/SceneBase.h"

class SceneManager:public Singleton<SceneManager>
{
public:
	SceneManager();
	~SceneManager();

	void Exec();
	void Draw();

	void SetNextScene(SceneID next_);
private:
	class SceneBase* create_NextScene();

	class SceneBase* m_pScene;
	static SceneID m_NextSceneID;


};

#endif // !SCENE_MANAGER_H

