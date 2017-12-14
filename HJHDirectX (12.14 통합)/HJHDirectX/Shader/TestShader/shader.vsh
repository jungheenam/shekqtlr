//
// Shader Example.
// Copyleft (c) 2007 Heesung Oh(Galic Studio). All rights Not reserved.
////////////////////////////////////////////////////////////////////////////

// m4x4: 벡터 = 벡터 * 행렬
// mov : 복사 명령어

vs_1_1                  // 쉐이더 버전

dcl_position	v0		// 정점 위치를 입력 레지스터 v0에 선언
dcl_color		v1		// 정점 색상을 입력 레지스터 v1에 선언

m4x4 oPos, v0, c0		// 정점의 변환: 출력 위치 = 입력 위치 * c0에 입력된 행렬
mov  oD0, v1			// 정점의 색상 설정: 입력된 정점을 색상을 그대로 복사
