#pragma once
class Texture
{
public:
	struct tagImageInfo
	{
		LPTXUR			pTexture;
		D3DXIMAGE_INFO	pInfo;
		RECT			pDrawRect;
		VEC3			vPosition;
		DWORD			dColor;

		float fW;
		float fH;
		float fAngle;

		tagImageInfo()
		{
			pTexture = nullptr;
			vPosition = VEC3(0, 0, 0);
			dColor = 0;

			fW = 0;
			fH = 0;
			fAngle = 0;
		}
	};
private:
	tagImageInfo* _pImageInfo;
	LPDIRECT3DSTATEBLOCK9 _pStateCurrent;
	LPDIRECT3DSTATEBLOCK9 _pStateSprite;
public:
	Texture();
	~Texture();
	HRESULT Init(TCHAR* sFilename, DWORD dFilter = -1, DWORD dColor = 0x00FFFFFF);
	void Release();
	void Update();
	void Render(const RECT* pDrawRect, const VEC3* vPosition,
		const VEC2* vAxis = NULL, float fAngle = 0.0f,
		const VEC2* vScaling = NULL,
		DWORD dColor = 0xFFFFFFFF);
	void SpriteState();

	tagImageInfo* getImageInfo() { return _pImageInfo; }
	
	
};

