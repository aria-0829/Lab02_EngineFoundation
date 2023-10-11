#include "Engine.h"
#include <iostream>
#include "json.hpp"
#include <fstream>

Engine::Engine()
{
	std::cout << "Engine Created \n" << std::endl;
}

Engine::~Engine()
{
	std::cout << "Engine Destroyed \n" << std::endl;
}

void Engine::Initialize()
{
	//Load GameSettings.json
	std::ifstream inputStream("GameSettings.json");
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON document = json::JSON::Load(str);

	if (document.hasKey("Engine"))
	{
		std::cout << "HasKey Engine..." << std::endl;
		json::JSON engineSettings = document["Engine"];

		if (engineSettings.hasKey("DefaultFile"))
		{
			std::string DefaultFile = engineSettings["DefaultFile"].ToString();
			std::cout << "DefaultFile: " << DefaultFile << std::endl << std::endl;

			//Load DefaultFile
			std::ifstream levelStream(DefaultFile);
			std::string levelStr((std::istreambuf_iterator<char>(levelStream)), std::istreambuf_iterator<char>());
			json::JSON levelFile = json::JSON::Load(levelStr);

			if (levelFile.hasKey("SceneManager"))
			{
				std::cout << "HasKey SceneManager..." << std::endl;
				json::JSON sceneManagerData = levelFile["SceneManager"];
				
				sceneManager->Load(sceneManagerData);
			}
		}
	}

	if (document.hasKey("RenderSystem"))
	{
		std::cout << "HasKey RenderSystem: " << std::endl;
		json::JSON renderSystemSettings = document["RenderSystem"];

		renderSystem->Initialize(renderSystemSettings);
	}

	std::cout << "Engine Initialized \n" << std::endl ;
}

void Engine::Destroy()
{
	std::cout << "Engine Destroy()" << std::endl;
}

void Engine::GameLoop()
{
	std::cout << "GameLoop Begin" << std::endl;

	for (int i = 0; i < 5; ++i) {
		renderSystem->Update();
	}
}

void Engine::Load()
{
	std::cout << "Loaded" << std::endl;
}
