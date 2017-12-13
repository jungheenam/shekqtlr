#pragma once
class P02_UIobject
{
public:
	P02_UIobject();
	~P02_UIobject();
	virtual void Update();
	virtual void UpdateChildren();
	virtual void Render();
	virtual void AddChild(P02_UIobject* child);
	virtual P02_UIobject* GetTag( int _tag );

protected:

	GETSET( VEC3 , position , Position );
	GETSET( P02_UIobject* , parent , Parent );
	GETSET( VEC2 , size , Size );
	GETSET( VEC2 , scale , Scale );
	GETSET( int , tag , Tag );

	vector<P02_UIobject*> childList;
};

