#include "stdafx.h"
#include "P02_UIButtonScene.h"


P02_UIButtonScene::P02_UIButtonScene()
{
}


P02_UIButtonScene::~P02_UIButtonScene()
{
	this->Release();
}

HRESULT P02_UIButtonScene::Init()
{
	//�ݹ��ư - ����� ����� �������Ұ�
	//��ֹ�ư - ����� ����� ������밡��
	
	button = new P02_UIButton;
	//		�ݹ��Լ� �����					������					�̹���������			������		 ��ư�������� �۵����Լ�
	button->Init( TRUE , VEC3( WINSIZEX / 2 , WINSIZEY / 2 , 0 ) , VEC2( 242 , 50 ) , VEC2( 1.0f , 1.0f ) , SetSence );

	button2 = new P02_UIButton;
	//		�ݹ��Լ� ������					������								�̹���������				������		 
	button2->Init( false , VEC3( WINSIZEX / 2 , WINSIZEY / 2 + 100 , 0 ) , VEC2( 242 , 50 ) , VEC2( 1.0f , 1.0f ) );


	return S_OK;
}

void P02_UIButtonScene::Release()
{
}

void P02_UIButtonScene::Update()
{
	//������Ʈ
	button->Update();
	button2->Update();
	//�ݹ��Լ��� �ƴϸ� GetIsClick ���θ� Ȯ���ϰ� �Լ�ȣ��
	if ( button2->GetIsClick() == true ) SetSence();

	ITEM->Update();
}

void P02_UIButtonScene::Render()
{

	//����
	button->Render();
	button2->Render();
	INVEN->Render();
	//ITEM->Render();


	TCHAR str[ 32 ];
	_stprintf( str , _T( "���� : " ) , PLAYERSTAT->getStat()._Atk );
	FONTM->DxDrawText( str , 6 , WINSIZEX / 2 , 50 , D3DXCOLOR( 1 , 1 , 0 , 1 ) );

}

// ��ư �׽�Ʈ�� �Լ�
void P02_UIButtonScene::SetSence()
{
	SCENEM->Change( _T( "P00_MultiAnimationScene" ) );

}
