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
	//		�ݹ��Լ� �����					������					�̹���������			������				��ư������	��ư�������� �۵����Լ�
	button->Init( TRUE , VEC3( WINSIZEX / 2 , WINSIZEY / 2 , 0 ) , VEC2( 242 , 50 ) , VEC2( 1.0f , 1.0f ) ,_T("����"), SetSence );

	button2 = new P02_UIButton;
	//		�ݹ��Լ� ������					������								�̹���������				������		  ��ư�� ����
	button2->Init( false , VEC3( WINSIZEX / 2 , WINSIZEY / 2 + 100 , 0 ) , VEC2( 242 , 50 ) , VEC2( 1.0f , 1.0f ) , _T( "��2" ) );



	CHARUI->Init();
	ITEM->Init();
	INVEN->Init();

	

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
	//�ݹ��Լ��� �ƴϸ� GetIsClick ���θ� Ȯ���ϰ� Ʈ��� �Լ�ȣ��
	if ( button2->GetIsClick() == true ) SetSence();
	//================================================

	CHARUI->Update();
	ITEM->Update();
	INVEN->Update();


}

void P02_UIButtonScene::Render()
{

	//����
	button->Render();
	button2->Render();	


	ITEM->Render();
	INVEN->Render();
	CHARUI->Render();


}

// ��ư �׽�Ʈ�� �Լ�
void P02_UIButtonScene::SetSence()
{
	SCENEM->Change( _T( "P00_MultiAnimationScene" ) );

}
