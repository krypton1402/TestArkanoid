#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ObstaclesArray.h"
#include "Ball.h"
#include <sstream>
using namespace sf;

class GameStatus {
private:
	Font front;//�����
	Text* TLvl;//����� ������
	Text* Tcore;//����� ��������

	Image status_image;//������ ����������� ��� ����
	Texture status;//�������� ����
	Sprite s_status;//������ ������ ��� ����

	int core;//����
	int lvl;//�������
	int obs_count;//c������ ������
	ObstaclesArray* obs;
	Ball* bal;

	int com;

public:
	GameStatus(int com);
	~GameStatus();
	void Apdate(int lvl);
	void Drow(RenderWindow* window);
	void GetObs(ObstaclesArray* obs);
	void GetBal(Ball* bal);
	void Win();
	void Dead();
};

