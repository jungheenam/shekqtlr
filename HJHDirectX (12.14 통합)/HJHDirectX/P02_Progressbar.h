#pragma once
class P02_Progressbar : public GameNode
{
private:
	RECT rc;
	VEC3 pos;
	VEC2 scale;
	float width;

	Texture* textureTop;
	Texture* textureBottom;

public:
	P02_Progressbar();
	~P02_Progressbar();


	HRESULT Init(VEC3 _position , VEC2 _size);
	HRESULT Init( TCHAR* _toptexture , TCHAR* _bottom , VEC3 _position , VEC2 _size );
	void Release();
	void Update();
	void Render();

	void SetGauge( float currentGauge , float maxGauge );

	void SetX( int x ) { pos.x = x; }
	void SetY( int y ) { pos.y = y; }
};

