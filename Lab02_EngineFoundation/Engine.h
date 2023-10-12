#pragma once
#ifndef _ENGINE_H_
#define _ENGINE_H_

#include "RenderSystem.h"
#include "InputManager.h"
#include "AssetManager.h"
#include "SceneManager.h"
#include "json.hpp"
#include <fstream>

class Engine
{
private:
	RenderSystem* renderSystem = nullptr;
	InputManager* inputManager = nullptr;
	AssetManager* assetManager = nullptr;
	SceneManager* sceneManager = nullptr;

public:
	Engine();
	~Engine();

	void Initialize();
	void Destroy();
	void GameLoop();
	void Load(json::JSON& _documentData);
};

#endif // !_ENGINE_H_



