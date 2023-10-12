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
	int width = 0;
	int height = 0;
	bool fullscreen = false;

public:
	RenderSystem();
	~RenderSystem();

	void Initialize();
	void Destroy();
	void Update();
	void Load(json::JSON& _documentData);
};

#endif // !_RENDERSYSTEM_H_

