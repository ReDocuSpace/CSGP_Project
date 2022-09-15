#pragma once

template<typename T>
class singleton
{
protected:
	static T* instance;

	singleton() {};
	~singleton() {};

public:
	static T* GetSingleton();
	void ReleaseSingleton();
};

template<typename T>
T* singleton<T>::instance = 0;

template<typename T>
inline T* singleton<T>::GetSingleton()
{
	if (!instance)
	{
		instance = new T;
	}

	return instance;
}

template<typename T>
inline void singleton<T>::ReleaseSingleton()
{
	if (instance)
	{
		delete instance;
		instance = 0;
	}
}
