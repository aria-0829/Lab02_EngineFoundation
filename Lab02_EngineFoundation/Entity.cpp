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
}

void Entity::RemoveComponent(Component* _component)
{
}

void Entity::Update()
{
}

std::string& Entity::GetName()
{
	return name;
}

void Entity::Load()
{
	std::cout << "Loaded" << std::endl;
}
