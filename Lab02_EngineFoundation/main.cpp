#include "Engine.h"
#include <iostream>
#include "json.hpp"
#include <fstream>

int main()
{
	Engine* engine = new Engine();

	engine->Initialize();
	engine->GameLoop();
	engine->Destroy();
	delete engine;

	return 0;
	
}