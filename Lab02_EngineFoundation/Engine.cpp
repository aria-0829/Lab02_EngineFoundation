#include "Engine.h"
#include <iostream>
#include "json.hpp"
#include <fstream>

Engine::Engine()
{
	std::cout << "Engine Created" << std::endl;
}

Engine::~Engine()
{
	std::cout << "Engine Destroyed" << std::endl;
}

void Engine::Initialize()
{
	//Load GameSettings.json
	std::ifstream inputStream("GameSettings.json");
	std::string str((std::istreambuf_iterator<char>(inputStream)), std::istreambuf_iterator<char>());
	json::JSON document = json::JSON::Load(str);

	if (document.hasKey("Engine"))
	{
		std::cout << "Engine: " << document["Engine"].ToString() << "\n";
		json::JSON engineSettings = document["Engine"];

		if (engineSettings.hasKey("DefaultFile"))
		{
			std::string DefaultFile = engineSettings["DefaultFile"].ToString();
			std::cout << "DefaultFile: " << DefaultFile << "\n";

			//sceneManager->AddScene();
		}
	}

	if (document.hasKey("RenderSystem"))
	{
		std::cout << "RenderSystem: " << document["RenderSystem"].ToString() << "\n";
		json::JSON renderSystemSettings = document["RenderSystem"];

		renderSystem->Initialize(renderSystemSettings);
	}

	std::cout << "Engine Initialized" << std::endl;
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
