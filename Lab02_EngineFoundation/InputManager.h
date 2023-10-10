#pragma once
#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

class InputManager
{
public:
	InputManager();
	~InputManager();

	void Initialize();
	void Destroy();
	void Update();
	void Load();
};

#endif // !_INPUTMANAGER_H_



