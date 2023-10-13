#include "Scene.h"
#include <iostream>

Scene::Scene()
{
	std::cout << "Scene Created" << std::endl;
}

Scene::~Scene()
{
	std::cout << "Scene Deleted" << std::endl;
}

void Scene::Initialize()
{
	std::cout << "Scene Initialized" << std::endl << std::endl;
}

void Scene::Destroy()
{
	for (auto& entity : entities)
	{
		entity->Destroy();
		delete entity;
	}
	entities.clear();

	std::cout << "Scene Destroyed" << std::endl;
}

void Scene::Update()
{
	for (auto& entity : entities)
	{
		entity->Update();
	}
	std::cout << "Scene Updated" << std::endl;
}

void Scene::AddEntity(Entity* _entity)
{
	entities.push_back(_entity);
	std::cout << "Entity Added to Scene" << std::endl << std::endl;
}

void Scene::RemoveEntity(Entity* _entity)
{
	entities.remove(_entity);
	std::cout << "Entity Removed from Scene" << std::endl;
}

void Scene::Load(json::JSON& _sceneData)
{
	if (_sceneData.hasKey("name"))
	{
		std::string sceneName = _sceneData["name"].ToString();
		std::cout << "Scene Name:" << sceneName << std::endl << std::endl;
	}

	if (_sceneData.hasKey("Entities"))
	{
		json::JSON entities = _sceneData["Entities"];

		for (auto& entityData : entities.ArrayRange())
		{
			Entity* entity = new Entity();
			AddEntity(entity);
			entity->Load(entityData);
		}
	}

	std::cout << "Scene Data Load Complete" << std::endl;

	Initialize();
}

