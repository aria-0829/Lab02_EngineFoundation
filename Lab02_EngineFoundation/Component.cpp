#include "Component.h"
#include <iostream>

Component::Component()
{
	std::cout << "Component Created" << std::endl;
}

Component::~Component()
{
	std::cout << "Component Deleted" << std::endl;
}

void Component::Initialize()
{
	std::cout << "Component Initialized" << std::endl << std::endl;
}

void Component::Destroy()
{
	std::cout << "Component Destroyed" << std::endl;
}

int Component::GetComponetId()
{
	return id;
}

void Component::Update()
{
	std::cout << "Component Updated" << std::endl;
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
		id = _componentData["id"].ToInt();
		std::cout << "Component ID: " << id << std::endl;
	}

	std::cout << "Component Load Complete" << std::endl;

	Initialize();
}
