#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

#include "Entity.h"
#include <list>
#include "json.hpp"
#include <fstream>

class Scene
{
private:
	std::list<Entity*> entities;

public:
	Scene();
	~Scene();

	void Initialize();
	void Destroy();
	void Update();
	void AddEntity(Entity* _entity);
	void RemoveEntity(Entity* _entity);
	void Load(json::JSON& _sceneData);
};

#endif // !_SCENE_H_


