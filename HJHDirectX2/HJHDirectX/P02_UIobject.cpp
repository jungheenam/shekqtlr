#include "stdafx.h"
#include "P02_UIobject.h"


P02_UIobject::P02_UIobject()
	:position( 0 , 0 , 0 ) ,
	size( 0 , 0 ) , parent( nullptr ) ,
	tag( 0 )
{
}


P02_UIobject::~P02_UIobject()
{
}

void P02_UIobject::Update()
{
	this->UpdateChildren();
}

void P02_UIobject::UpdateChildren()
{
	for each( auto c in childList ) c->Update();
}

void P02_UIobject::Render()
{
	for each( auto c in childList ) c->Render();
}

void P02_UIobject::AddChild( P02_UIobject* child )
{
	child->parent = this;
	childList.push_back( child );
}

P02_UIobject * P02_UIobject::GetTag( int _tag )
{
	if ( tag == _tag ) return this;

	for each ( auto c in childList )
	{
		P02_UIobject* child = c->GetTag( _tag );
		if ( child != nullptr ) return child;
	}
	return nullptr;
}
