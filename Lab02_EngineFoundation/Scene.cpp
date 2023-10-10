#include "Scene.h"
#include <iostream>

Scene::Scene()
{
	std::cout << "Scene Created" << std::endl;
}

Scene::~Scene()
{
	std::cout << "Scene Destroyed" << std::endl;
}

void Scene::Initialize()
{
	std::cout << "Scene Initialized" << std::endl;
}

void Scene::Destroy()
{
	std::cout << "Destroyed" << std::endl;
}

void Scene::Update()
{
	
}

void Scene::AddEntity(Entity* _entity)
{
}

void Scene::RemoveEntity(Entity* _entity)
{
}

void Scene::Load()
{
	std::cout << "Loaded" << std::endl;
}

