#include "Component.h"
#include <iostream>

Component::Component()
{
	std::cout << "Component Created" << std::endl;
}

Component::~Component()
{
	std::cout << "Component Destroyed" << std::endl;
}

void Component::Initialize()
{
	std::cout << "Component Initialized" << std::endl;
}

void Component::Destroy()
{
	std::cout << "Destroyed" << std::endl;
}

int Component::GetComponetId()
{
	return 0;
}

void Component::Update()
{
}

void Component::Load()
{
	std::cout << "Loaded" << std::endl;
}
