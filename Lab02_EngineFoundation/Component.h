#pragma once
#ifndef _COMPONENT_H_
#define	_COMPONENT_H_
#include "json.hpp"
#include <fstream>

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
	void Load(json::JSON& _componentData);
};

#endif // !_COMPONENT_H_



