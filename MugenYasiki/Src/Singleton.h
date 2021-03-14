#ifndef SINGLETON_H
#define SINGLETON_H

template<class T>
class Singleton
{
protected:
	Singleton() {};
	virtual ~Singleton() {};

private:
	static T* instanse;

public:
	static void CreateInstanse()
	{
		if (instanse == nullptr)
		{
			instanse = new T();
		}
	}

	static void DeleteInstanse()
	{
		delete instanse;
		instanse = nullptr;
	}

	static T* GetInstanse() { return instanse; };
};

template <class T>
T* Singleton<T>::instanse = nullptr;

#endif // !SINGLETON_H

