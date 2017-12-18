#pragma once
#include "SingletonBase.h"
class GameNode;
class SceneManager : public SingletonBase<SceneManager>
{
private:
	static GameNode* _pScene;
	map<tstring, GameNode*> _mScene;
public:
	SceneManager();
	~SceneManager();
	HRESULT Init();
	void Release();
	void Update();
	void Render();
	GameNode* Add(tstring key, GameNode* node);
	HRESULT Change(tstring key);
};