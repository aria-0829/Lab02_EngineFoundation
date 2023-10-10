#include "AssetManager.h"
#include <iostream>

AssetManager::AssetManager()
{
	std::cout << "AssetManager Created" << std::endl;
}

AssetManager::~AssetManager()
{
	std::cout << "AssetManager Destroyed" << std::endl;
}

void AssetManager::Initialize()
{
	std::cout << "AssetManager Initialized" << std::endl;
}

void AssetManager::Destroy()
{
	std::cout << "Destroyed" << std::endl;
}

void AssetManager::Update()
{
}

void AssetManager::Load()
{
	std::cout << "Loaded" << std::endl;
}
