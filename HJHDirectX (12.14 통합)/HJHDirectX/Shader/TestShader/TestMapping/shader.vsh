//
// Shader Example.
// Copyleft (c) 2007 Heesung Oh(Galic Studio). All rights Not reserved.
////////////////////////////////////////////////////////////////////////////

// c0: World * View * Projection Matrix
// c4: View Matrix


#define	Nor	r0
#define	Tex	r1

vs_1_1


def	c32, 0.4, 0.5, 0.0, 1.0

dcl_position 	v0
dcl_normal		v1

m4x4 oPos, v0,	c0			// ������ ��ȯ

m3x3 Nor, v1,	c4			// ���� ������ ī�޶� ���� ��ȯ

mov Tex.xyz, Nor.xyz
mov Tex.w, c32.w
mov Tex.y, -Tex.y			// y ��ǥ�� ������Ŵ

mad Tex, Tex, c32.x, c32.y	// Tex = (1+Tex)/2. �ؽ�ó ��ǥ�� (0.5, 0.5) �߽����� �� ����

mov oT0, Tex

