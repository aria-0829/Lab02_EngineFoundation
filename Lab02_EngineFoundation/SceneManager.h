#pragma once
#ifndef _SCENEMANAGER_H_
#define _SCENEMANAGER_H_

#include "Scene.h"
#include <list>
#include "json.hpp"
#include <fstream>

class SceneManager
{
private:
	std::list<Scene*> scenes;

public:
	SceneManager();
	~SceneManager();

	void Initialize();
	void Destroy();
	void Update();
	void AddScene(Scene* _scene);
	void RemoveScene(Scene* _scene);
	void Load(json::JSON& _sceneManagerData);
};

#endif // !_SCENEMANAGER_H_


