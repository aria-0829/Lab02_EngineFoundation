#include "InputManager.h"
#include <iostream>

InputManager::InputManager()
{
	std::cout << "InputManager Created \n" << std::endl;
}

InputManager::~InputManager()
{
	std::cout << "InputManager Destroyed \n" << std::endl;
}

void InputManager::Initialize()
{
	std::cout << "InputManager Initialized \n" << std::endl;
}

void InputManager::Destroy()
{
	std::cout << "Destroyed" << std::endl;
}

void InputManager::Update()
{
}

void InputManager::Load()
{
	std::cout << "Loaded" << std::endl;
}
