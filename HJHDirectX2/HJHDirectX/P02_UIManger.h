#pragma once
#include "SingletonBase.h"
#include "P02_UIobject.h"
#include "P02_UIbutton.h"
#include "P02_UIScroll.h"

class P02_UIManger : public UIButtonDelegate , public SingletonBase<P02_UIManger>
{
private:
	enum UIKIND
	{
		UIKIND_BUTTON ,
	
		UIKIND_END
	};

	enum TAG { EXIT_BUTTON , MENU_BUTTON, SCENE_BUTTON };
	P02_UIobject* uiobj = nullptr;
	UIKIND kind;
	TCHAR str[ 64 ];

	virtual void Click( P02_UIbutton* sender );
public:
	P02_UIManger();
	~P02_UIManger();

	void SetButton( P02_UIbutton* _button , VEC3 _position , VEC2 _size , tstring _string);
	void SetSceneButton( P02_UIbutton* _button , VEC3 _position , VEC2 _size , tstring _string , tstring _scene );
	void SetScroll( P02_UIScroll* _scroll , VEC3 _position , float min ,float max );
	void Update();
	void Render();
	


};

