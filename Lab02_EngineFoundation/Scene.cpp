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
		std::cout << "Loading Scene Name: " << sceneName << std::endl << std::endl;
	}

	if (_sceneData.hasKey("Entities"))
	{
		std::cout << "HasKey Entities..." << std::endl;
		json::JSON entities = _sceneData["Entities"];

		for (auto& entityData : entities.ArrayRange())
		{
			Entity* entity = new Entity();
			entity->Load(entityData);
			AddEntity(entity);
		}
	}
	std::cout << "Scene Data Load Complete." << std::endl;
}

