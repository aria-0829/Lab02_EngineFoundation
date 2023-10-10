#include "Object.h"
#include <iostream>

Object::Object()
{
	std::cout << "Object Created" << std::endl;
}

Object::~Object()
{
	std::cout << "Object Destroyed" << std::endl;
}

void Object::Initialize()
{
	std::cout << "Object Initialized" << std::endl;
}

void Object::Destroy()
{
	std::cout << "Destroyed" << std::endl;
}

bool Object::IsInitialized()
{
	return false;
}

void Object::Load()
{
	std::cout << "Loaded" << std::endl;
}
