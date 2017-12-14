#pragma once
class P00_TestXFileInstance;
class P00_TestXFileScene
{
private:
	P00_TestXFilePure* _pOrig;

	P00_TestXFilePure* _pClone;
public:
	P00_TestXFileScene();
	~P00_TestXFileScene();
	HRESULT Init();
	void Release();
	void Update();
	void Render();
};

