//
// Shader Example.
// Copyleft (c) 2007 Heesung Oh(Galic Studio). All rights Not reserved.
////////////////////////////////////////////////////////////////////////////

// c0: world * view * projection matrix

vs_1_1						// ���̴� ����

dcl_position 	v0			// ���� ��ġ�� �Է� �������� v0�� ����
dcl_texcoord	v3			// ���� UV ��ǥ�� �Է� �������� v3�� ����

m4x4 oPos, v0,	c0			// ������ ��ȯ: ��� ��ġ = �Է� ��ġ * c0�� �Էµ� ���

mov oT0, v3					// ��� UV ��ǥ = �Է� UV ��ǥ


