#ifndef RESULT_SCENE_H
#define RESULT_SCENE_H

#include"SceneBase.h"
#include"../Manager/GameManager.h"
#include"../Manager/InputManager.h"
#include"../Manager/SceneManager.h"
#include"../Manager/TextureManager.h"

class ResultScene:public SceneBase
{
public:
	ResultScene();
	~ResultScene();

	virtual bool IsEnd()const;

	void Exec();
	void Draw();

	void Step_InTexture();
	void Step_Input();
private:
	GameManager* gamenManager = nullptr;
	InputManager* inputManager = nullptr;
	TextureManager* textureManager = nullptr;
};

#endif // !RESULT_SCENE_H
