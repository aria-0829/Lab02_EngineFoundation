#include "Entity.h"
#include <iostream>

Entity::Entity()
{
	std::cout << "Entity Created" << std::endl;
}

Entity::~Entity()
{
	std::cout << "Entity Destroyed" << std::endl;
}

void Entity::Initialize()
{
	std::cout << "Entity Initialized" << std::endl;
}

void Entity::Destroy()
{
	std::cout << "Destroyed" << std::endl;
}

void Entity::AddComponent(Component* _component)
{
	components.push_back(_component);
	std::cout << "Component Added to Entity" << std::endl << std::endl;
}

void Entity::RemoveComponent(Component* _component)
{
	components.remove(_component);
	std::cout << "Component Removed from Entity" << std::endl;
}

void Entity::Update()
{
}

std::string& Entity::GetName()
{
	return name;
}

void Entity::Load(json::JSON& _entityData)
{
	if (_entityData.hasKey("Name"))
	{
		std::string entityName = _entityData["Name"].ToString();
		std::cout << "Entity Name: " << entityName << std::endl << std::endl;

	}
	if (_entityData.hasKey("Components"))
	{
		std::cout << "HasKey Components..." << std::endl;
		json::JSON components = _entityData["Components"];

		for (auto& componentData : components.ArrayRange())
		{
			Component* component = new Component();
			component->Load(componentData);
			AddComponent(component);
		}
	}
	std::cout << "Entity Data Load Complete." << std::endl;
}
