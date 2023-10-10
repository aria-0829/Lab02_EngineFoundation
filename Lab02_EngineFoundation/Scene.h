#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

#include "Entity.h"
#include <list>

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
	void Load();
};

#endif // !_SCENE_H_


