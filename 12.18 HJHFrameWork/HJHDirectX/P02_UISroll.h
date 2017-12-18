#pragma once
class P02_UISroll
{
public:
	P02_UISroll();
	~P02_UISroll();

	HRESULT Init( VEC3 _position , VEC2 _size , float min , float max );
	void Release();
	void Update();
	void Render();

	void ScrollCtrl();
	void ScrollDraw();

	float ReturnResult( float _result );

private:
	struct tagScroll
	{
		RECT scrollRC;
		RECT barRC;


		float width;
		float currentBar;
		VEC3 position;


		Texture* textureSC;
		Texture* textureBAR;

		float result;
		float min , max;
	};

	tagScroll scroll;
	P02_Progressbar* progressbar;

};

