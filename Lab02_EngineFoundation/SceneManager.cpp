#include "SceneManager.h"
#include <iostream>


SceneManager::SceneManager()
{
	std::cout << "SceneManager Created" << std::endl;
}

SceneManager::~SceneManager()
{
	std::cout << "SceneManager Deleted" << std::endl << std::endl;
}

void SceneManager::Initialize()
{
	
	std::cout << "SceneManager Initialized" << std::endl << std::endl;
}

void SceneManager::Destroy()
{
	for (auto& scene : scenes)
	{
		//RemoveScene(scene);
		//scene->Destroy();
		//delete scene;
	}
	std::cout << "SceneManager Destroyed" << std::endl;
}

void SceneManager::Update()
{
	for (auto& scene : scenes)
	{
		scene->Update();
	}
	std::cout << "SceneManager Updated" << std::endl;
}

void SceneManager::AddScene(Scene* _scene)
{
	scenes.push_back(_scene);
	std::cout << "Scene Added to SceneManager" << std::endl << std::endl;
}

void SceneManager::RemoveScene(Scene* _scene)
{
	scenes.remove(_scene);
	std::cout << "Scene Removed from SceneManager" << std::endl;
}

void SceneManager::Load(json::JSON& _levelData)
{
	if (_levelData.hasKey("SceneManager"))
	{
		std::cout << "HasKey SceneManager..." << std::endl;
		json::JSON sceneManagerData = _levelData["SceneManager"];

		for (auto& sceneData : sceneManagerData.ArrayRange())
		{
			Scene* scene = new Scene();
			AddScene(scene);
			scene->Load(sceneData);
		}
	}

	std::cout << "Scene Manager Data Load Complete." << std::endl << std::endl;
}
