#include "Engine.h"
#include <iostream>

Engine::Engine()
{
	std::cout << "Engine Created" << std::endl;
}

Engine::~Engine()
{
	std::cout << "Engine Deleted" << std::endl << std::endl;
}

void Engine::Initialize()
{
	//Load GameSettings.json
	std::ifstream inputStream("GameSettings.json");
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON documentData = json::JSON::Load(str);

	Load(documentData);

	sceneManager->Initialize();
	assetManager->Initialize();
	renderSystem->Initialize();
	inputManager->Initialize();

	std::cout << "Engine Initialized" << std::endl << std::endl;
}

void Engine::Destroy()
{
	inputManager->Destroy();
	delete inputManager;
	renderSystem->Destroy();
	delete renderSystem;
	assetManager->Destroy();
	delete assetManager;
	sceneManager->Destroy();
	delete sceneManager;
	std::cout << "Engine Destroyed" << std::endl;
}

void Engine::GameLoop()
{
	std::cout << "GameLoop Begin" << std::endl << std::endl;

	for (int i = 0; i < 5; ++i) {
		sceneManager->Update();
		assetManager->Update();
		renderSystem->Update();
		inputManager->Update();
	}
}

void Engine::Load(json::JSON& _documentData)
{
	if (_documentData.hasKey("Engine"))
	{
		json::JSON engineSettings = _documentData["Engine"];

		if (engineSettings.hasKey("DefaultFile"))
		{
			std::string DefaultFile = engineSettings["DefaultFile"].ToString();
			std::cout << "DefaultFile: " << DefaultFile << std::endl << std::endl;

			//Load DefaultFile
			std::ifstream levelStream(DefaultFile);
			std::string levelStr((std::istreambuf_iterator<char>(levelStream)), std::istreambuf_iterator<char>());
			json::JSON levelData = json::JSON::Load(levelStr);

			sceneManager = new SceneManager();
			sceneManager->Load(levelData);
		}
	}

	assetManager = new AssetManager();
	assetManager->Load();
	renderSystem = new RenderSystem();
	renderSystem->Load(_documentData);
	inputManager = new InputManager();
	inputManager->Load();
	
	std::cout << "Engine Load Complete." << std::endl << std::endl;
}
