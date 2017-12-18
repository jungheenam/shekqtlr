#include "stdafx.h"
#include "TextureManager.h"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
	this->Release();
}

HRESULT TextureManager::Init()
{
	return S_OK;
}

void TextureManager::Release()
{
	map<tstring, Texture*>::iterator iKey = _mTexture.begin();

	for (; iKey != _mTexture.end();)
	{
		if (iKey->second != NULL)
		{
			iKey->second->Release();
			SAFE_DELETE(iKey->second);
			iKey = _mTexture.erase(iKey);
		}
		else
		{
			++iKey;
		}
	}
}

void TextureManager::Update()
{
}

void TextureManager::Render()
{
}

BOOL TextureManager::ReleaseTexture(tstring key)
{
	map<tstring, Texture*>::iterator iKey = _mTexture.find(key);

	if (iKey != _mTexture.end())
	{
		iKey->second->Release();
		SAFE_DELETE(iKey->second);
		_mTexture.erase(iKey);
		
		return TRUE;
	}

	return FALSE;
}

Texture * TextureManager::Add(tstring key, TCHAR * sFilename, DWORD dFilter, DWORD dColor)
{
	Texture* pTex = this->Find(key);
	if (pTex) return pTex;

	pTex = new Texture;

	if (FAILED(pTex->Init(sFilename, dFilter, dColor)))
	{
		SAFE_DELETE(pTex);
		return NULL;
	}

	_mTexture.insert(make_pair(key, pTex));

	return pTex;
}

Texture * TextureManager::Find(tstring key)
{
	map<tstring, Texture*>::iterator iKey = _mTexture.find(key);

	if (iKey != _mTexture.end())
	{
		return iKey->second;
	}

	return NULL;
}
