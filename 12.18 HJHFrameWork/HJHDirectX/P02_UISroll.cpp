#include "stdafx.h"
#include "P02_UISroll.h"


P02_UISroll::P02_UISroll()
{
}


P02_UISroll::~P02_UISroll()
{
}

HRESULT P02_UISroll::Init( VEC3 _position , VEC2 _size , float min , float max )
{
	progressbar = new P02_Progressbar;
	progressbar->Init(_position , _size);
	progressbar->SetGauge( 0 , 0 );
	scroll.min = min;
	scroll.max = max;




	return S_OK;
}

void P02_UISroll::Release()
{
	SAFE_DELETE( progressbar );
}

void P02_UISroll::Update()
{
	progressbar->Update();
	progressbar->SetGauge( scroll.currentBar , scroll.max );
}

void P02_UISroll::Render()
{
	progressbar->Render();

}

void P02_UISroll::ScrollCtrl()
{
	POINT ptMouse;
	ptMouse.x = INPUTM->GetMousePos().x;
	ptMouse.y = INPUTM->GetMousePos().y;


}

void P02_UISroll::ScrollDraw()
{

}

float P02_UISroll::ReturnResult( float _result )
{
	float result;
	result =  _result;

	return  result;
}
