#ifndef GIMMICK_BASE_H
#define GIMMICK_BASE_H

class GimmickBase
{
public:
	GimmickBase();
	virtual ~GimmickBase();

	virtual void Exec();
	virtual void Draw(int texture);
	virtual bool Collision(int x_, int y_);

protected:
	int m_PosX;
	int m_PosY;
	int m_TextureX;
	int m_TextureY;
};

#endif // !GIMMICK_BASE_H

