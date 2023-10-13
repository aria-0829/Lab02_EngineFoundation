#include "Entity.h"
#include <iostream>

Entity::Entity()
{
	std::cout << "Entity Created" << std::endl;
}

Entity::~Entity()
{
	std::cout << "Entity Deleted" << std::endl;
}

void Entity::Initialize()
{
	std::cout << "Entity Initialized" << std::endl << std::endl;
}

void Entity::Destroy()
{
	for (auto& component : components)
	{
		component->Destroy();
		delete component;
	}
	components.clear();

	std::cout << "Entity Destroyed" << std::endl;
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
	for (auto& component : components)
	{
		component->Update();
	}
	std::cout << "Entity Updated" << std::endl;
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
		json::JSON components = _entityData["Components"];

		for (auto& componentData : components.ArrayRange())
		{
			Component* component = new Component();
			AddComponent(component);
			component->Load(componentData);
		}
	}

	std::cout << "Entity Data Load Complete" << std::endl;

	Initialize();
}
