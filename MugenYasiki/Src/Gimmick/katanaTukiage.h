#ifndef KATANA_TUKIAGE_H
#define KATANA_TUKIAGE_H

#include"../Definition.h"
#include"GimmickBase.h"
#include"DxLib.h"

class KatanaTukiage: public GimmickBase
{
public:
	KatanaTukiage();
	~KatanaTukiage();

	void Exec(int x_);
	void Draw(int TexMana, float pi);
	bool Collision(int x_,int y_);

private:
	bool Draw_katana = true;
	bool IsMove = false;

	const int m_UpSpeed = 20;
	int m_MaxPosY = TextBar_Y - m_TextureY + 90;
};

#endif // !KATANA_TUKIAGE_H

