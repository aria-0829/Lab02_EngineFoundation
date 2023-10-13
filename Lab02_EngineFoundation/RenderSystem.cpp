#include "RenderSystem.h"
#include <iostream>
#include "SDL.h"

RenderSystem::RenderSystem()
{
	std::cout << "RenderSystem Created" << std::endl;
}

RenderSystem::~RenderSystem()
{
	std::cout << "RenderSystem Deleted" << std::endl << std::endl;
}

void RenderSystem::Initialize()
{
	//Create a render window to be used based off the size in the settings
	std::cout << "Creating a render window" << std::endl << std::endl;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	window = SDL_CreateWindow("SDL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);

	SDL_DestroyWindow(window);
	SDL_Quit();

	std::cout << "RenderSystem Initialized" << std::endl << std::endl;
}

void RenderSystem::Destroy()
{
	std::cout << "RenderSystem Destroyed" << std::endl;
}

void RenderSystem::Update()
{
	//process the SDL_PollEvents (you don’t have to handle them)
	bool quit = false;

	SDL_Event event;
	while (SDL_PollEvent(&event))
	{

	}
	
	std::cout << "Render System Updated" << std::endl;
}

void RenderSystem::Load(json::JSON& _documentData)
{	
	if (_documentData.hasKey("RenderSystem"))
	{
		json::JSON renderSystemSettings = _documentData["RenderSystem"];

		if (renderSystemSettings.hasKey("Name"))
		{
			Name = renderSystemSettings["Name"].ToString();
			std::cout << "Name: " << Name << std::endl;
		}

		if (renderSystemSettings.hasKey("width"))
		{
			RenderSystem::width = renderSystemSettings["width"].ToInt();
			std::cout << "width: " << RenderSystem::width << std::endl;
		}

		if (renderSystemSettings.hasKey("height"))
		{
			RenderSystem::height = renderSystemSettings["height"].ToInt();
			std::cout << "height: " << RenderSystem::height << std::endl;
		}

		if (renderSystemSettings.hasKey("fullscreen"))
		{
			RenderSystem::fullscreen = renderSystemSettings["fullscreen"].ToBool();
			std::cout << "fullscreen: " << RenderSystem::fullscreen << std::endl;
		}
	}

	std::cout << "RenderSystem Load Complete." << std::endl << std::endl;
}
