#pragma once
#ifndef _ASSETMANAGER_H_
#define _ASSETMANAGER_H_

class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	void Initialize();
	void Destroy();
	void Update();
	void Load();
};

#endif // !_ASSETMANAGER_H_


