#pragma once
#ifndef _RENDERSYSTEM_H_
#define _RENDERSYSTEM_H_
#include <string>
#include "json.hpp"
#include <fstream>

class RenderSystem
{
private:
	std::string Name = "";
	float width = 0;
	float height = 0;
	bool fullscreen = false;

public:
	RenderSystem();
	~RenderSystem();

	void Initialize(json::JSON& _json);
	void Destroy();
	void Update();
	void Load();
};

#endif // !_RENDERSYSTEM_H_

