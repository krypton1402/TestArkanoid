#pragma once
#include <SFML/Graphics.hpp>
#include "PlayingField.h"
#include <iostream>
using namespace sf;

class Platform {
private:
	Image platform_image;//������ ����������� ��� ����
	Texture platform;//�������� ����
	Sprite s_platform;//������ ������ ��� ����

	float vx;//��������
	float xleft, xright, yleft, yright;//����������
	int platformsise;//����� ���������
	int com;//���������
	float borderL;//������ �������
	float borderR;//����� �������

	int n;//���������� ��������;

public:
	//��������� ���������� ��� ������: 175, 750, 251, 740 ���������� ������������ ��������������
	Platform(int com, int n);
	virtual ~Platform();
	void Draw(RenderWindow* window);//���������
	void MoveXleft(float time);//�������� �����
	void MoveXright(float time);//�������� ������
	void SetFild(PlayingField* fild);//��������� ������ ����

	float GetX_L() { return xleft; }
	float GetY_L() { return yleft; }
	float GetX_R() { return xright; }
	float GetY_R() { return yright; }
	int GetSise() { return platformsise; }
};

