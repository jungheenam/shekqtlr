#pragma once

class P02_UIbutton;

class UIButtonDelegate
{
public:
	virtual void Click( P02_UIbutton* sender ) = 0;
};

class P02_UIbutton : public P02_UIobject
{
public:
	P02_UIbutton();
	virtual ~P02_UIbutton();

	virtual	void SetButton(VEC2 _size,VEC3 _position);
	virtual void Update();
	virtual void Render();
	virtual void SetButtonText( tstring _string );

	enum ButtonStat
	{
		BUTTONSTAT_NORMAL,
		BUTTONSTAT_OVER,
		BUTTONSTAT_SELECT,
		BUTTONSTAT_END	
	};

	ButtonStat buttonstat;
	Texture* textureBT[ BUTTONSTAT_END ];
	RECT rc;
	TCHAR tempStr[ 128 ];
	GETSET( UIButtonDelegate * , buttonDelegate , ButtonDelegate );

};

