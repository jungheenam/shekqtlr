#pragma once

class P02_UIButtonScene : public GameNode
{
private:
	P02_UIButton* button;
	P02_UIButton* button2;

public:
	P02_UIButtonScene();
	~P02_UIButtonScene();

	HRESULT Init();
	void Release();
	void Update();
	void Render();
	static void SetSence();

};
