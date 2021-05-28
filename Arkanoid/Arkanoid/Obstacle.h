#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Obstacle
{
private:
	Image obs_image;//������ ����������� ��� ����
	Texture obs;//�������� ����
	Sprite s_obs;//������ ������ ��� ����

	float xLeft;//���������� � ����� �������
	float xRight;//���������� � ������ �������
	float yTop;//���������� � �������
	float yBottom;//���������� � ���������
	float V_Y;//��������
	int live;//�����

	float Ytikstur;//���������� �������� �� y
	float CurientTime;//������� ����

public:
	Obstacle(float xLeft, float yTop, float xRight, float yBottom, int live, int com);
	virtual ~Obstacle();
	void Draw(RenderWindow* window);//���������
	void Move(float time);//�������� ��������
	void LiveDown();//���������� �����

	float Get_xLeft() { return this->xLeft; }
	float Get_xRight() { return this->xRight; }
	float Get_yTop() { return this->yTop; }
	float Get_yBottom() { return this->yBottom; }
	int Get_Live() { return this->live; }
};

