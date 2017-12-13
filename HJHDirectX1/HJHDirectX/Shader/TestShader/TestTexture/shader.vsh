//
// Shader Example.
// Copyleft (c) 2007 Heesung Oh(Galic Studio). All rights Not reserved.
////////////////////////////////////////////////////////////////////////////

// c0: world * view * projection matrix

vs_1_1						// 쉐이더 버전

dcl_position 	v0			// 정점 위치를 입력 레지스터 v0에 선언
dcl_texcoord	v3			// 정점 UV 좌표를 입력 레지스터 v3에 선언

m4x4 oPos, v0,	c0			// 정점의 변환: 출력 위치 = 입력 위치 * c0에 입력된 행렬

mov oT0, v3					// 출력 UV 좌표 = 입력 UV 좌표


