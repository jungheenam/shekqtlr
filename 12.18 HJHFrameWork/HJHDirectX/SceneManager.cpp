#include "stdafx.h"
#include "SceneManager.h"


SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{
}

GameNode* SceneManager::_pScene = nullptr;
HRESULT SceneManager::Init()
{
	_pScene = nullptr;

	return S_OK;
}

void SceneManager::Release()
{
	for each(auto i in _mScene)
	{
		i.second->Release();
	}
	_mScene.clear();
}

void SceneManager::Update()
{
	if (_pScene) _pScene->Update();
}

void SceneManager::Render()
{
	if (_pScene) _pScene->Render();
}

GameNode * SceneManager::Add(tstring key, GameNode * node)
{
	if (!node) return NULL;
	_mScene.insert(make_pair(key, node));
	return node;
}

HRESULT SceneManager::Change(tstring key)
{
	map<tstring, GameNode*>::iterator i = _mScene.find(key);
	if (i == _mScene.end()) return E_FAIL;
	if (i->second == _pScene) return S_OK;
	if (FAILED(i->second->Init())) return E_FAIL;
	SAFE_RELEASE(_pScene);
	_pScene = i->second;
	return S_OK;
}

