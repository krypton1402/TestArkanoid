#pragma once
#include <iostream>
//������� ����� ����� ������ 10 �� 13 ������

class LVL {
	char* lvl;//������ ������
public:
	LVL();
	virtual ~LVL();
	void StartLVL(int number);//��������� ������ �� ������
	char* GetLVL() { return lvl; }//�������� ������
};

