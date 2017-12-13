#pragma once
class MainGame : public GameNode
{
public:
	MainGame();
	~MainGame();
	HRESULT Init();
	void Release();
	void Update();
	void Render();
};

