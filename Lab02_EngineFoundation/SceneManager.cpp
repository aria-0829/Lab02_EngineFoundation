#include "SceneManager.h"
#include <iostream>


SceneManager::SceneManager()
{
	std::cout << "SceneManager Created" << std::endl;
}

SceneManager::~SceneManager()
{
	std::cout << "SceneManager Destroyed" << std::endl;
}

void SceneManager::Initialize()
{
	
	std::cout << "SceneManager Initialized" << std::endl;
}

void SceneManager::Destroy()
{
	std::cout << "Destroyed" << std::endl;
}

void SceneManager::Update()
{
}

void SceneManager::AddScene(Scene* _scene)
{
}

void SceneManager::RemoveScene(Scene* _scene)
{
}

void SceneManager::Load(json::JSON& _json)
{
	//Load DefaultFile

	std::cout << "Loaded" << std::endl;
}
