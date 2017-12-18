#pragma once

class P02_UIButtonScene : public GameNode
{
private:
	P02_UIButton* button;
	P02_UIButton* button2;
	P02_Progressbar* bar;

	P02_Inven* inven;

	int test;

public:
	P02_UIButtonScene();
	~P02_UIButtonScene();

	HRESULT Init();
	void Release();
	void Update();
	void Render();
	static void SetSence();

};
