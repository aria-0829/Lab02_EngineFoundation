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

void Component::Load(json::JSON& _componentData)
{
	if (_componentData.hasKey("className"))
	{
		std::string componentName = _componentData["className"].ToString();
		std::cout << "Component Name: " << componentName << std::endl;
	}

	if (_componentData.hasKey("id"))
	{
		int componentID = _componentData["id"].ToInt();
		std::cout << "Component ID: " << componentID << std::endl;
	}

	std::cout << "Component Loaded." << std::endl << std::endl;
}
