#include "RenderSystem.h"
#include <iostream>
//#include "json.hpp"
//#include <fstream>
#include "SDL.h"

RenderSystem::RenderSystem()
{
	std::cout << "RenderSystem Created \n" << std::endl;
}

RenderSystem::~RenderSystem()
{
	std::cout << "RenderSystem Destroyed \n" << std::endl;
}

void RenderSystem::Initialize(json::JSON& _json)
{
	//Load the appropriate data
	if (_json.hasKey("Name"))
	{
		Name = _json["Name"].ToString();
		std::cout << "Name: " << Name << std::endl;
	}

	if (_json.hasKey("width"))
	{
		RenderSystem::width = _json["width"].ToInt();
		std::cout << "width: " << RenderSystem::width << std::endl;
	}

	if (_json.hasKey("height"))
	{
		RenderSystem::height = _json["height"].ToInt();
		std::cout << "height: " << RenderSystem::height << std::endl;
	}

	if (_json.hasKey("fullscreen"))
	{
		RenderSystem::fullscreen = _json["fullscreen"].ToBool();
		std::cout << "fullscreen: " << RenderSystem::fullscreen << std::endl;
	}

	//create a render window to be used based off the size in the settings
	std::cout << "Creating a render window \n" << std::endl;
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	window = SDL_CreateWindow("SDL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_RenderPresent(renderer);

	SDL_DestroyWindow(window);
	SDL_Quit();

	std::cout << "RenderSystem Initialized \n" << std::endl;
}

void RenderSystem::Destroy()
{
	std::cout << "Destroyed" << std::endl;
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

void RenderSystem::Load()
{	
	std::cout << "Loaded" << std::endl;
}
