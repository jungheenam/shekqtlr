#pragma once


class P02_ItemBase;
class P02_UIButtonScene : public GameNode
{
private:
	
	P02_ItemBase* item;

	P02_UIbutton* button1;
	P02_UIbutton* button2;
	P02_UIbutton* button3;

	P02_Inventory* inven;

	P02_UIScroll* scroll;
public:
	P02_UIButtonScene();
	~P02_UIButtonScene();

	HRESULT Init();
	void Release();
	void Update();
	void Render();

};
