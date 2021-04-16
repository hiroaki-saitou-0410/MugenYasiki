#ifndef BASE_H
#define BASE_H

class Base
{
public:
	Base();
	virtual ~Base();

	virtual void Exec();
	virtual bool Collision();
protected:
	int m_PosX;
	int m_PosY;
	
	bool IsDead;
};

#endif // !BASE_H

