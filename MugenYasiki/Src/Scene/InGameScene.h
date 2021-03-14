#ifndef INGAMESCENE_H
#define INGAMESCENE_H

#include"DxLib.h"
#include"SceneBase.h"
#include"../Manager/GameManager.h"
#include"../Manager/InputManager.h"
#include"../Manager/SceneManager.h"
#include"../Manager/TextureManager.h"

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
	TextureManager* textureMnager = nullptr;

	bool FinishedScene = false;

};

#endif // !INGAMESCENE_H
