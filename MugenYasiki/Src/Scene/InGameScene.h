#ifndef INGAMESCENE_H
#define INGAMESCENE_H

#include"DxLib.h"
#include"SceneBase.h"
#include"../Manager/GameManager.h"
#include"../Manager/InputManager.h"
#include"../Manager/SceneManager.h"
#include"../Manager/TextureManager.h"
#include"../Player/Player.h"

class InGameScene :public SceneBase
{
public:
	InGameScene();
	~InGameScene();

public:
	void Exec();
	void Draw();
	virtual bool IsEnd()const;

private:
	GameManager* gamenManager = nullptr;
	InputManager* inputManager = nullptr;
	TextureManager* textureManager = nullptr;
	//Player* player = new Player;

	bool FinishedScene =false;

	int m_ActStop;
	int m_WaitIndex;
	int m_ActSpeed;
	int m_RightMotionMax;
};

#endif // !INGAMESCENE_H
