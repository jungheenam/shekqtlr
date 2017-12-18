//
// Shader Example.
// Copyleft (c) 2007 Heesung Oh(Galic Studio). All rights Not reserved.
////////////////////////////////////////////////////////////////////////////

// c0  : world * view * Projection Matrix

vs_1_1

// ��� ����
def	c10, 1.5, 1.5, 1.5, 1


// ������ ��ġ, Diffuse ����
dcl_position	v0		// ���� ��ġ
dcl_normal		v1		// ���� ����
dcl_color		v2		// ���� Diffuse
dcl_texcoord0	v3		// ���� �ؽ�ó ��ǥ0
dcl_texcoord3	v4		// ���� �ؽ�ó ��ǥ1


// �Է� �������� v0�� �ӽ� �������� r0�� ����
mov  r0, v0

// c0~c3���� �ӽ� �������Ϳ� ����
mov  r1, c0	
mov  r2, c1
mov  r3, c2
mov  r4, c3

// ���� ��ġ ó��
m4x4 r5, r0, r1		// ���� * ��� ����
mov oPos, r5		// ���� ����� ��� �������Ϳ� ����

mov  oT7, r5		// �ȼ� ���̴����� ����� �� �ֵ��� ���� ��ȯ ��ġ�� 0T7�� ����
mov  oT6, v1		// �ȼ� ���̴����� ����� �� �ֵ��� ���� ���� ���͸� 0T6�� ����

mul  r0, v2, c10	// r0 = ������ ���� * c10
mul  r1, r0, c11	// r1 = r0 * c11
mov  oD0, r1

mov  oT0, v3		// �ؽ�ó ��ǥ 0 ����
mov  oT1, v4		// �ؽ�ó ��ǥ 1 ����
