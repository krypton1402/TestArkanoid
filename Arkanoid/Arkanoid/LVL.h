#pragma once
#include <iostream>
//”ровень будет иметь размер 10 на 13 блоков

class LVL {
	char* lvl;//массив уровн€
public:
	LVL();
	virtual ~LVL();
	void StartLVL(int number);//генераци€ уровн€ по номеру
	char* GetLVL() { return lvl; }//ѕередача уровн€
};

