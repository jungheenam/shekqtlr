#pragma once
// Create by 2017 11 29
#define WINNAME _T("Heenam, Junseo, Hyunsik Project!")
#define WINSTARTX ((GetSystemMetrics(SM_CXSCREEN) - (rc.right - rc.left)) / 2)
#define WINSTARTY ((GetSystemMetrics(SM_CYSCREEN) - (rc.bottom - rc.top)) / 2)
#define WINSIZEX 1024
#define WINSIZEY 768
#define WINSTYLE (WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE)

#define SAFE_DELETE(p) {if(p) {delete (p); (p) = NULL;}}
#define SAFE_DELETE_ARRAY(p) {if(p) {delete[] (p); (p) = NULL;}}
#define SAFE_RELEASE(p) {if(p) {(p)->Release(); (p) = NULL;}}
#define SAFE_ADDREF(p) {if(p) {(p)->AddRef();}}
#define SAFE_FREE(p) {if(p) {free(p); (p) = NULL;}}

#define GETSET(type, typeName, funcName)\
protected: type typeName;\
public: inline type Get##funcName(void) {return typeName;}\
public: inline void Set##funcName(type var) {typeName = var;}
#define GETSET_REF(type, typeName, funcName)\
protected: type typeName;\
public: inline type& Get##funcName(void) {return typeName;}\
public: inline void Set##funcName(type& var) {typeName = var;}
#define GETSET_ADD_REF(type, typeName, funcName)\
protected: type typeName;\
public: inline type& Get##funcName(void) {return typeName;}\
public: inline void Set##funcName(type var)\
{\
	if(typeName != var)\
	{\
		SAFE_RELEASE(typeName);\
		SAFE_ADDREF(var);\
		typeName = var;\
	}\
}
























#ifdef _UNICODE
#define tstring wstring
#else
#define tstring string
#endif 