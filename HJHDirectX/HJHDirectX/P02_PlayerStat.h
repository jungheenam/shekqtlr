#pragma once
#include "SingletonBase.h"
class P02_PlayerStat : public SingletonBase<P02_PlayerStat>
{
private:
	struct tagSTAT
	{
		int _dex;
		int _con;
		int _HP;
		int _MP;
		int _Atk;
	};
	tagSTAT stat;

public:
	P02_PlayerStat();
	~P02_PlayerStat();

	void Update();

	tagSTAT getStat() { return stat; }

	void setDEX(int _dex) { stat._dex = _dex; }
	void setCON(int _con) { stat._con = _con; }
	void setHP(int _HP) { stat._HP = _HP; }
	void setMP(int _MP) { stat._MP = _MP; }
	void setATK(int _Atk) { stat._Atk = _Atk; }

};

