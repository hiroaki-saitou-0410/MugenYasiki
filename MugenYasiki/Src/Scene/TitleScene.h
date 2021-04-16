#ifndef TITLE_SCENE_H
#define TITLE_SCENE_H

#include"SceneBase.h"
#include"../Manager/GameManager.h"
#include"../Manager/InputManager.h"
#include"../Manager/SceneManager.h"
#include"../Manager/TextureManager.h"
#include"../Manager/SoundManager.h"


class TitleScene: public SceneBase
{
public:
	TitleScene();
	~TitleScene();

	void Exec();
	void Draw();
	virtual bool IsEnd()const;

	void Step_Logo();
	void Step_Input();
private:
	GameManager* gamenManager = nullptr;
	InputManager* inputManager = nullptr;
	TextureManager* textureManager = nullptr;
	SoundManager* soundManager = nullptr;

	int number;
};

#endif // !TITLE_SCENE_H

