#pragma once


class P02_UIScroll : public P02_UIobject
{
public:
	struct tagScrollbar
	{
		Texture* textureBar;
		Texture* textureRc;

		float min , max;
		float barLength;
		VEC3 currentPos;
		RECT barRc;
		RECT currentBarRC;
		
		float result;
		
		bool isClick;

	};

	
	P02_UIScroll();
	~P02_UIScroll();

	virtual void Update();
	virtual void Render();
	virtual void SetScrollbar(VEC3 _postion, float min, float max);
	virtual void BarMove();
	float RrturnResult( float result );

private:
	
	tagScrollbar scroll;

};


