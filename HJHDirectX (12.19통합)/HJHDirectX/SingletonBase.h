#pragma once
template <typename T> class SingletonBase
{
protected:
	SingletonBase() {};
	~SingletonBase() {};
	static T* singleton;
public:
	static T* GetSingleton()
	{
		if (!singleton)
		{
			singleton = new T;
		}
		return singleton;
	}
	static void ReleaseSingleton()
	{
		if (singleton)
		{
			delete singleton;
			singleton = 0;
		}
	}
};
template <typename T> T* SingletonBase<T>::singleton = 0;