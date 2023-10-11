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
		std::cout << "Found Engine:" << std::endl;
		json::JSON engineSettings = document["Engine"];

		if (engineSettings.hasKey("DefaultFile"))
		{
			std::string DefaultFile = engineSettings["DefaultFile"].ToString();
			std::cout << "Found DefaultFile: " << DefaultFile << std::endl << std::endl;

			//Load DefaultFile
			std::ifstream levelStream(DefaultFile);
			std::string levelStr((std::istreambuf_iterator<char>(levelStream)), std::istreambuf_iterator<char>());
			json::JSON levelFile = json::JSON::Load(levelStr);

			if (levelFile.hasKey("SceneManager"))
			{
				std::cout << "Found SceneManager:" << std::endl;
				json::JSON scenes = levelFile["SceneManager"];
				
				//sceneManager->Load(scenes);

				for (auto& scene : scenes.ArrayRange())
				{
					if (scene.hasKey("name"))
					{
						std::string sceneName = scene["name"].ToString();
						std::cout << "Scene Name: " << sceneName << std::endl << std::endl;
					}
					if (scene.hasKey("Entities"))
					{
						std::cout << "Found Entities:" << std::endl;
						json::JSON entities = scene["Entities"];

						for (auto& entity : entities.ArrayRange())
						{
							if (entity.hasKey("Name"))
							{
								std::string entityName = entity["Name"].ToString();
								std::cout << "Entity Name: " << entityName << std::endl << std::endl;
							}
							if (entity.hasKey("Components"))
							{
								std::cout << "Found Components:" << std::endl;
								json::JSON components = entity["Components"];

								for (auto& component : components.ArrayRange())
								{
									if (component.hasKey("className"))
									{
										std::string componentName = component["className"].ToString();
										std::cout << "Component Name: " << componentName << std::endl;
									}

									if (component.hasKey("id"))
									{
										int componentID = component["id"].ToInt();
										std::cout << "Component ID: " << componentID << std::endl << std::endl;
									}
								}
							}
						}
					}
				}
			}
		}
	}

	if (document.hasKey("RenderSystem"))
	{
		std::cout << "Found RenderSystem: " << document["RenderSystem"].ToString() << std::endl;
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
