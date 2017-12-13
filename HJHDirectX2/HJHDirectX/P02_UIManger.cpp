#include "stdafx.h"
#include "P02_UIManger.h"


P02_UIManger::P02_UIManger()
{
}


P02_UIManger::~P02_UIManger()
{
}

void P02_UIManger::SetButton( P02_UIbutton* _button , VEC3 _position , VEC2 _size , tstring _string )
{
	_button = new P02_UIbutton;
	_button->SetButton( _size , _position );
	_button->SetButtonText( _string );
	_button->SetTag( MENU_BUTTON );
	_button->SetButtonDelegate( this );
	if ( !uiobj ) uiobj = _button;
	else uiobj->AddChild( _button );
}

void P02_UIManger::SetSceneButton( P02_UIbutton * _button , VEC3 _position , VEC2 _size , tstring _string , tstring _scene )
{
	_button = new P02_UIbutton;
	_button->SetButton( _size , _position );
	_button->SetButtonText( _string );
	_button->SetTag( SCENE_BUTTON );
	_button->SetButtonDelegate( this );
	strcpy( str , _scene.c_str() );
	if ( !uiobj ) uiobj = _button;
	else uiobj->AddChild( _button );


}

void P02_UIManger::SetScroll( P02_UIScroll * _scroll , VEC3 _position , float min , float max )
{
	_scroll = new P02_UIScroll;
	_scroll->SetScrollbar( _position , min , max );
	if ( !uiobj ) uiobj = _scroll;
	else uiobj->AddChild( _scroll );
}

void P02_UIManger::Update()
{
	if ( uiobj ) uiobj->Update();
}

void P02_UIManger::Render()
{
	if ( uiobj )uiobj->Render();
}

void P02_UIManger::Click( P02_UIbutton * sender )
{
	if ( sender->GetTag() == MENU_BUTTON ) sender->SetButtonText( _T( "¤»¤»" ) );
	if ( sender->GetTag() == SCENE_BUTTON ) SCENEM->Change( str );

}

