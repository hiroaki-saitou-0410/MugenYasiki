#ifndef JAPANESE_DOLL_H
#define JAPANESE_DOLL_H

#include"DxLib.h"
#include"Item_Definition.h"
#include"../Manager/TextureManager.h"

class JapaneseDoll
{
public:
	JapaneseDoll();
	~JapaneseDoll();

	void Exec(bool itemGet);
	void ActExec(int m_IsDecision);
	void Draw(int texture,int Item,int ItemFrame,int clearBlack, bool haveDoll);
	void ItemBar(int texture,int itemframe,bool haveDoll);
	void Explosion();

	int TextureNumber() { return m_Index; }
	bool IsExplosion() {return m_IsExplosion;}
	int GetPosX() { return m_PosX; }
	int GetPosY() { return m_PosY; }
	void IsExplain(int explain){m_IsGet = explain;}
private:
	TextureManager* textureManager = nullptr;

	bool m_IsGet = false;
	bool m_IsExplosion = false;

	int m_PosX;
	int m_PosY;
	int m_Index;
	int m_ActStop;
	const int m_ActSpeed = 3;
	const int m_MotionMax = explosion11;
	
};

#endif // !JAPANESE_DOLL_H

