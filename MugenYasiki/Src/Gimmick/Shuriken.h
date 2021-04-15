#ifndef SHURIKEN_H
#define SHURIKEN_H

#include"GimmickBase.h"

class Shuriken:public GimmickBase
{
public:
	Shuriken();
	~Shuriken();

	void Exec();
	bool Collision(int x_, int y_);
private:

};

#endif // !SHURIKEN_H

