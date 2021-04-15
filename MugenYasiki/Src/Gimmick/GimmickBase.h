#ifndef GIMMICK_BASE_H
#define GIMMICK_BASE_H

class GimmickBase
{
public:
	GimmickBase();
	virtual ~GimmickBase();

	virtual void Exec();
	virtual bool Collision(int x_, int y_);

private:

};

#endif // !GIMMICK_BASE_H

