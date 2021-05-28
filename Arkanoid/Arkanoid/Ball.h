#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Platform.h"
#include "PlayingField.h"
#include "ObstaclesArray.h"
using namespace sf;

class Ball {
	Image bal_image;//������ ����������� ��� ����
	Texture bal;//�������� ����
	Sprite s_bal;//������ ������ ��� ����

	float x, y;//����������
	double vx, vy, V_X, V_Y;//��������
	float r;//������
	Platform* OnePlatform;//��������� 1
	Platform* TwoPlatform;//��������� 2
	PlayingField* field;//������� ����
	ObstaclesArray* obsarr;//�����������

	int live;//����� ����
	
public:
	Ball(int com);
	virtual ~Ball();
	void Draw(RenderWindow* window);//���������
	void Move(float time);//�����������
	void SetFild(PlayingField* field);//��������� ������ ����
	void SetOnePlatform(Platform* pl);//��������� ��������� 1
	void SetTwoPlatform(Platform* pl);//��������� ��������� 1
	void SetObstaclArry(ObstaclesArray* obs);//��������� �����������
	int Getlive() { return live; }//������ �����
	void StartPozition();//������� ����
};

