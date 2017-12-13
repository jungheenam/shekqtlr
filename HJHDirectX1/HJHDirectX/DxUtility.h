#pragma once
#include "stdafx.h"

struct tagVertexPC
{
	D3DXVECTOR3 p;
	D3DCOLOR c;

	tagVertexPC() {};
	tagVertexPC( float x , float y , float z , D3DCOLOR c ) { this->p.x = x; this->p.y = y; this->p.z = z; this->c = c; }

	tagVertexPC( D3DXVECTOR3 p , D3DCOLOR c ) { this->p = p; this->c = c; }

	enum { FVF = ( D3DFVF_XYZ | D3DFVF_DIFFUSE ) , };
};

struct tagVertexPD
{
	D3DXVECTOR3 p;
	DWORD d;

	tagVertexPD() {};
	tagVertexPD( float x , float y , float z , DWORD d ) { this->p.x = x; this->p.y = y; this->p.z = z; this->d = d; }

	tagVertexPD( D3DXVECTOR3 p , DWORD d ) { this->p = p; this->d = d; }

	enum { FVF = ( D3DFVF_XYZ | D3DFVF_DIFFUSE ) , };
};

struct tagVertexPT
{
	D3DXVECTOR3 p;
	D3DXVECTOR2 t;

	tagVertexPT() {};
	tagVertexPT( float x , float y , float z , float u , float v ) { this->p.x = x; this->p.y = y; this->p.z = z; this->t.x = u; this->t.y = v; }

	tagVertexPT( D3DXVECTOR3 p , D3DXVECTOR2 t ) { this->p = p; this->t = t; }

	enum { FVF = ( D3DFVF_XYZ | D3DFVF_TEX1 ) , };
};

struct tagVertexPN
{
	tagVertexPN( D3DXVECTOR3 p , D3DXVECTOR3 n )
	{
		this->p = p;
		this->n = n;
	}
	tagVertexPN()
	{
	}
	D3DXVECTOR3 p;
	D3DXVECTOR3 n;
	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL , };
};

struct tagVertexPCT
{
	D3DXVECTOR3 p;
	D3DCOLOR c;
	D3DXVECTOR2 t;

	tagVertexPCT() {};
	tagVertexPCT( float x , float y , float z , D3DCOLOR c , float u , float v ) { this->p.x = x; this->p.y = y; this->p.z = z; this->c = c; this->t.x = u; this->t.y = v; }

	tagVertexPCT( D3DXVECTOR3 p , D3DCOLOR c , D3DXVECTOR2 t ) { this->p = p; this->c = c; this->t = t; }

	enum { FVF = ( D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1 ) , };
};

struct tagVertexPDT
{
	D3DXVECTOR3 p;
	DWORD d;
	D3DXVECTOR2 t;

	tagVertexPDT() {};
	tagVertexPDT( float x , float y , float z , DWORD d , float u , float v ) { this->p.x = x; this->p.y = y; this->p.z = z; this->d = d; this->t.x = u; this->t.y = v; }

	tagVertexPDT( D3DXVECTOR3 p , DWORD d , D3DXVECTOR2 t ) { this->p = p; this->d = d; this->t = t; }

	enum { FVF = ( D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1 ) , };
};

struct tagVertexPDT2
{
	D3DXVECTOR3 p;
	DWORD d;
	D3DXVECTOR2 t1;
	D3DXVECTOR2 t2;

	tagVertexPDT2() {};
	tagVertexPDT2( float x , float y , float z , DWORD d , float u1 , float v1 , float u2 , float v2 ) { this->p.x = x; this->p.y = y; this->p.z = z; this->d = d; this->t1.x = u1; this->t1.y = v1; this->t2.x = u2; this->t2.y = v2; }

	tagVertexPDT2( D3DXVECTOR3 p , DWORD d , D3DXVECTOR2 t1 , D3DXVECTOR2 t2 ) { this->p = p; this->d = d; this->t1 = t1; this->t2 = t2; }

	enum { FVF = ( D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX2 ) , };
};

struct tagVertexPDT3
{
	D3DXVECTOR3 p;
	DWORD d;
	D3DXVECTOR2 t1;
	D3DXVECTOR2 t2;
	D3DXVECTOR2 t3;

	tagVertexPDT3() {};
	tagVertexPDT3( float x , float y , float z , DWORD d , float u1 , float v1 , float u2 , float v2 , float u3 , float v3 )
	{
		this->p.x = x; this->p.y = y; this->p.z = z;
		this->d = d;
		this->t1.x = u1; this->t1.y = v1;
		this->t2.x = u2; this->t2.y = v2;
		this->t3.x = u3; this->t3.y = v3;
	}

	tagVertexPDT3( D3DXVECTOR3 p , DWORD d , D3DXVECTOR2 t1 , D3DXVECTOR2 t2 , D3DXVECTOR2 t3 )
	{
		this->p = p; this->d = d; this->t1 = t1; this->t2 = t2; this->t3 = t3;
	}

	enum { FVF = ( D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX3 ) , };
};

struct tagVertexPCT2
{
	D3DXVECTOR3 p;
	D3DCOLOR c;
	D3DXVECTOR2 t1;
	D3DXVECTOR2 t2;

	tagVertexPCT2() {};
	tagVertexPCT2( float x , float y , float z , D3DCOLOR c , float u1 , float v1 , float u2 , float v2 ) { this->p.x = x; this->p.y = y; this->p.z = z; this->c = c; this->t1.x = u1; this->t1.y = v1; this->t2.x = u2; this->t2.y = v2; }

	tagVertexPCT2( D3DXVECTOR3 p , D3DCOLOR c , D3DXVECTOR2 t1 , D3DXVECTOR2 t2 ) { this->p = p; this->c = c; this->t1 = t1; this->t2 = t2; }

	enum { FVF = ( D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX2 ) , };
};

struct tagVertexPNCT2
{
	D3DXVECTOR3 p;
	D3DXVECTOR3 n;
	D3DCOLOR c;
	D3DXVECTOR2 t1;
	D3DXVECTOR2 t2;

	tagVertexPNCT2() {};
	tagVertexPNCT2( float x , float y , float z , float nx , float ny , float nz , D3DCOLOR c , float u1 , float v1 , float u2 , float v2 )
	{
		this->p.x = x; this->p.y = y; this->p.z = z; this->n.x = nx; this->n.y = ny; this->n.z = nz; this->c = c; this->t1.x = u1; this->t1.y = v1; this->t2.x = u2; this->t2.y = v2;
	}

	tagVertexPNCT2( D3DXVECTOR3 p , D3DXVECTOR3 n , D3DCOLOR c , D3DXVECTOR2 t1 , D3DXVECTOR2 t2 )
	{
		this->p = p; this->n = n; this->c = c; this->t1 = t1; this->t2 = t2;
	}

	enum { FVF = ( D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX2 ) , };
};

struct tagVertexPNT
{
	tagVertexPNT( D3DXVECTOR3 p , D3DXVECTOR3 n , D3DXVECTOR2 t )
	{
		this->p = p;
		this->n = n;
		this->t = t;
	}
	tagVertexPNT()
	{
	}
	D3DXVECTOR3 p;
	D3DXVECTOR3 n;
	D3DXVECTOR2 t;
	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 , };
};

struct tagVertexPNC
{
	tagVertexPNC( D3DXVECTOR3 p , D3DXVECTOR3 n , D3DXCOLOR c )
	{
		this->p = p;
		this->n = n;
		this->c = c;
	}
	tagVertexPNC()
	{
	}
	D3DXVECTOR3 p;
	D3DXVECTOR3 n;
	D3DXCOLOR c;
	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE , };
};

struct tagVertexPNDT
{
	tagVertexPNDT( D3DXVECTOR3 p , D3DXVECTOR3 n , DWORD d , D3DXVECTOR2 t )
	{
		this->p = p;
		this->n = n;
		this->d = d;
		this->t = t;
	}
	tagVertexPNDT()
	{
	}
	D3DXVECTOR3 p;
	D3DXVECTOR3 n;
	DWORD d;
	D3DXVECTOR2 t;
	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1 , };
};

struct tagVertexRHWD
{
	D3DXVECTOR4 p;
	DWORD		d;

	tagVertexRHWD() { p.x = p.y = p.z = 0.0f; p.w = 1.0f; d = 0xFFFFFFFF; }
	tagVertexRHWD( float x , float y , DWORD d = 0xFFFFFFFF ) { p.x = x; p.y = y; p.z = 0.0f; p.w = 1.0f; this->d = d; }

	enum { FVF = D3DFVF_XYZRHW | D3DFVF_DIFFUSE , };
};
struct tagVertexRHWDT
{
	D3DXVECTOR4 p;
	DWORD		d;
	float		u , v;

	tagVertexRHWDT() { p.x = p.y = p.z = 0.0f; p.w = 1.0f; d = 0xFFFFFFFF; u = v = 0.0f; }
	tagVertexRHWDT( float x , float y , float z , DWORD d , float u , float v )
	{
		this->p.x = x; this->p.y = y; this->p.z = z; this->p.w = 1.0f;
		this->u = u; this->v = v; this->d = d;
	}
	tagVertexRHWDT( float x , float y , float z , float w , DWORD d , float u , float v )
	{
		this->p.x = x; this->p.y = y; this->p.z = z; this->p.w = w;
		this->u = u; this->v = v; this->d = d;
	}

	enum { FVF = D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1 , };
};

struct tagVertexPBT
{
	D3DXVECTOR3 p;
	float		g[ 3 ];
	BYTE		m[ 4 ];
	D3DXVECTOR2 t;

	tagVertexPBT()
	{
		p = D3DXVECTOR3( 0 , 0 , 0 );
		t = D3DXVECTOR2( 0 , 0 );
		g[ 0 ] = g[ 1 ] = g[ 2 ] = 0;
		m[ 0 ] = m[ 1 ] = m[ 2 ] = m[ 3 ] = 0;
	}

	enum { FVF = D3DFVF_XYZB4 | D3DFVF_LASTBETA_UBYTE4 | D3DFVF_TEX1 , };
};

struct tagIndex
{
	union { struct { WORD a; WORD b; WORD c; }; WORD m[ 3 ]; };

	tagIndex() { a = 0;       b = 1;	   c = 2; }
	tagIndex( WORD a , WORD b , WORD c ) { this->a = a; this->b = b; this->c = c; }
	tagIndex( WORD* pArr ) { this->a = pArr[ 0 ]; this->b = pArr[ 1 ]; this->c = pArr[ 2 ]; }

	operator WORD*( ) { return ( WORD* )&a; }
	operator CONST WORD*( ) const { return ( CONST WORD* )&a; }
};

struct tagAlphaTexture
{
	LPDIRECT3DTEXTURE9 pTextureBase;
	LPDIRECT3DTEXTURE9 pTextureAlpha;
	LPDIRECT3DTEXTURE9 pTextureNormal;

	tagAlphaTexture() : pTextureBase( 0 ) , pTextureAlpha( 0 ) , pTextureNormal( 0 ) {}
	~tagAlphaTexture()
	{
		SAFE_RELEASE( pTextureBase );
		SAFE_RELEASE( pTextureAlpha );
		SAFE_RELEASE( pTextureNormal );
	}
};

struct tagWeightTexture
{
	LPDIRECT3DTEXTURE9	pTextureBase;
	LPDIRECT3DTEXTURE9	pTextureNormal;
	DWORD*				pWeight;

	tagWeightTexture() : pTextureBase( 0 ) , pTextureNormal( 0 ) , pWeight( 0 ) {}
	~tagWeightTexture()
	{
		SAFE_RELEASE( pTextureBase );
		SAFE_RELEASE( pTextureNormal );
		SAFE_FREE( pWeight );
	}
};

inline void D3DXVec3NormalVector( D3DXVECTOR3* pOut , D3DXVECTOR3* pV0 , D3DXVECTOR3* pV1 , D3DXVECTOR3* pV2 )
{
	VEC3 n;
	VEC3 A = *pV2 - *pV0;
	VEC3 B = *pV1 - *pV0;
	D3DXVec3Cross( &n , &A , &B );
	D3DXVec3Normalize( &n , &n );
	*pOut = n;
}

inline void D3DXMatrixViewport( D3DXMATRIX* pOut , const D3DVIEWPORT9* pV )
{
	float   fW = 0;
	float   fH = 0;
	float   fD = 0;
	float   fY = 0;
	float   fX = 0;
	float   fM = FLOAT( pV->MinZ );

	fW = FLOAT( pV->Width ) * 0.5f;
	fH = FLOAT( pV->Height ) * 0.5f;
	fD = FLOAT( pV->MaxZ ) - FLOAT( pV->MinZ );
	fX = FLOAT( pV->X ) + fW;
	fY = FLOAT( pV->Y ) + fH;

	*pOut = D3DXMATRIX( fW , 0.f , 0 , 0 ,
		0.f , -fH , 0 , 0 ,
		0.f , 0.f , fD , 0 ,
		fX , fY , fM , 1 );
}

inline void MyMatrixReflect( void * pOutMatrix , const void * pPlane , BOOL bNormalize )
{
	PLAN dP( ( float* )pPlane );
	MAT  mS;

	if ( bNormalize == FALSE ) D3DXPlaneNormalize( &dP , &dP );

	mS = MAT(
		1 - 2 * dP.a * dP.a , -2 * dP.a * dP.b , -2 * dP.a * dP.c , -2 * dP.a * dP.d ,
		-2 * dP.b * dP.a , 1 - 2 * dP.b * dP.b , -2 * dP.b * dP.c , -2 * dP.b * dP.d ,
		-2 * dP.c * dP.a , -2 * dP.c * dP.b , 1 - 2 * dP.c * dP.c , -2 * dP.c * dP.d ,
		-2 * dP.d * dP.a , -2 * dP.d * dP.b , -2 * dP.d * dP.c , 1 - 2 * dP.d * dP.d
	);

	mS = *( ( MAT* )pOutMatrix );
}
inline void MYDXMatrixShadow( void* pOut , const void* pLight , void* pPlane , BOOL bNormalized )
{
	PLAN dP( ( float* )pPlane );
	VEC4 vL( ( float* )pLight );

	MAT   mS;
	float fDir = 0.0f;

	if ( bNormalized == FALSE ) D3DXPlaneNormalize( &dP , &dP );

	fDir = D3DXVec4Dot( ( D3DXVECTOR4* )&dP , ( D3DXVECTOR4* )&vL );

	mS = MAT
	(
		fDir - dP.a * vL.x , -dP.a * vL.y , -dP.a * vL.z , -dP.a * vL.w ,
		-dP.b * vL.x , fDir - dP.b * vL.y , -dP.b * vL.z , -dP.b * vL.w ,
		-dP.c * vL.x , -dP.c * vL.y , fDir - dP.c * vL.z , -dP.c * vL.w ,
		-dP.d * vL.x , -dP.d * vL.y , -dP.d * vL.z , fDir - dP.d * vL.w
	);

	*( MAT* )pOut = mS;
}

inline RECT RectMakeCenter( int x , int y , int width , int height )
{
	RECT rc = { x - ( width / 2 ) , y - ( height / 2 ) , x + ( width / 2 ), y + ( height / 2 ) };

	return rc;
}

inline RECT RectMake( int x , int y , int width , int height )
{
	RECT rc = { x, y, x + width , y + height };

	return rc;
}