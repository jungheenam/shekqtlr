#pragma once
class P00_TestMesh;
class P00_TestMeshData;
class P00_TestXFile;
class P00_TestXFileScene;
class P00_TestSkinning;
class P00_TestShaderBase;
class P00_TestShaderText;
class P00_TestShaderMapping;

class P00_TestSplatting;
class P00_TestAlphaTexture;

class P00_TestSprite;

#define P00_TEST_CLASS P00_TestSplatting

class P00_TestScene : public GameNode
{
private:
	P00_TEST_CLASS* _pTest;
public:
	P00_TestScene();
	~P00_TestScene();
	HRESULT Init();
	void Release();
	void Update();
	void Render();
};

