#pragma once
#ifndef _COMPONENT_H_
#define	_COMPONENT_H_

class Component
{
private:
	int id = 0;

public:
	Component();
	~Component();

	void Initialize();
	void Destroy();
	int GetComponetId();
	void Update();
	void Load();
};

#endif // !_COMPONENT_H_



