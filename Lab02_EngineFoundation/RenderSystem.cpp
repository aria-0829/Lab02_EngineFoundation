#include "RenderSystem.h"
#include <iostream>
//#include "json.hpp"
//#include <fstream>
#include "SDL.h"

RenderSystem::RenderSystem()
{
	std::cout << "RenderSystem Created" << std::endl;
}

RenderSystem::~RenderSystem()
{
	std::cout << "RenderSystem Destroyed" << std::endl;
}

void RenderSystem::Initialize(json::JSON& _json)
{
	//Load the appropriate data
	if (_json.hasKey("Name"))
	{
		Name = _json["Name"].ToString();
		std::cout << "Name: " << Name << "\n";
	}

	if (_json.hasKey("width"))
	{
		RenderSystem::width = _json["width"].ToInt();
		std::cout << "width: " << RenderSystem::width << "\n";
	}

	if (_json.hasKey("height"))
	{
		RenderSystem::height = _json["height"].ToInt();
		std::cout << "height: " << RenderSystem::height << "\n";
	}

	if (_json.hasKey("fullscreen"))
	{
		RenderSystem::fullscreen = _json["fullscreen"].ToBool();
		std::cout << "fullscreen: " << RenderSystem::fullscreen << "\n";
	}

	//create a render window to be used based off the size in the settings
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;

	window = SDL_CreateWindow("SDL Example", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	while (true)
	{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	std::cout << "RenderSystem Initialized" << std::endl;
}

void RenderSystem::Destroy()
{
	std::cout << "Destroyed" << std::endl;
}

void RenderSystem::Update()
{
	//process the SDL_PollEvents (you don’t have to handle them)
	
	std::cout << "Render System Update" << std::endl;
}

void RenderSystem::Load()
{	
	std::cout << "Loaded" << std::endl;
}
