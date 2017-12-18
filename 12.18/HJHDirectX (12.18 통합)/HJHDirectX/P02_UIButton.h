#pragma once

typedef void( *CALLBACK_FUNTION )( void );

enum BUTTONSTAT
{
	BUTTONSTAT_NORMAL ,
	BUTTONSTAT_OVER ,
	BUTTONSTAT_DOWN ,
	BUTTONSTAT_END
};

class P02_UIButton
{
private:
	BUTTONSTAT buttonstat;
	Texture* textureBT[ BUTTONSTAT_END ];
	RECT rc;
	TCHAR* str;
	bool cb;

public:
	P02_UIButton();
	~P02_UIButton();

	HRESULT Init( BOOL _callback , VEC3 _postion , VEC2 _size , VEC2 _scale , TCHAR* _string , CALLBACK_FUNTION _void = NULL  );
	void Release();
	void Update();
	void Render();
	void ButtonStat();


	GETSET( VEC3 , position , Position );
	GETSET( VEC2 , size , Size );
	GETSET( VEC2 , scale , Scale );
	GETSET( BOOL , isclick , IsClick );
	GETSET( CALLBACK_FUNTION , callback , Callback );
};

