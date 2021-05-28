#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "ObstaclesArray.h"
#include "Ball.h"
#include <sstream>
using namespace sf;

class GameStatus {
private:
	Font front;//Шрифт
	Text* TLvl;//Текст уровня
	Text* Tcore;//текст счетчика

	Image status_image;//объект изображения для поля
	Texture status;//текстура поля
	Sprite s_status;//создаём спрайт для поля

	int core;//счет
	int lvl;//уровень
	int obs_count;//cчетчик врагов
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

