#pragma once


class P00_SkinnedMeshPure;
class P00_MultiAnimationScene : public GameNode
{
private:
	TCHAR _sMeshFilename[MAX_PATH];

	P00_SkinnedMeshPure* _pMultiAniOrig;
	P00_SkinnedMeshPure* _pMultiAniCopy;

	vector<P00_SkinnedMeshPure*> _vZealot;

	P00_SkinnedMeshPure* _pMenu;

	MAT _mWorld;
public:
	P00_MultiAnimationScene();
	~P00_MultiAnimationScene();
	HRESULT Init();
	void Release();
	void Update();
	void Render();
};

