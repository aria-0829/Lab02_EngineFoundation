#pragma once
#ifndef _OBJECT_H_
#define _OBJECT_H_

class Object
{
private:
	bool initialized = false;

public:
	Object();
	~Object();

	virtual void Initialize();
	virtual void Destroy();
	bool IsInitialized();
	virtual void Load();
};

#endif // !_OBJECT_H_


