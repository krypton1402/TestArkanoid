#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Platform.h"
#include "PlayingField.h"
#include "ObstaclesArray.h"
using namespace sf;

class Ball {
	Image bal_image;//объект изображения для поля
	Texture bal;//текстура поля
	Sprite s_bal;//создаём спрайт для поля

	float x, y;//координаты
	double vx, vy, V_X, V_Y;//скорость
	float r;//радиус
	Platform* OnePlatform;//платформа 1
	Platform* TwoPlatform;//платформа 2
	PlayingField* field;//Игровое поле
	ObstaclesArray* obsarr;//препятствия

	int live;//жизни шара
	
public:
	Ball(int com);
	virtual ~Ball();
	void Draw(RenderWindow* window);//отрисовка
	void Move(float time);//Перемещение
	void SetFild(PlayingField* field);//Получение границ окна
	void SetOnePlatform(Platform* pl);//Получение платформы 1
	void SetTwoPlatform(Platform* pl);//Получение платформы 1
	void SetObstaclArry(ObstaclesArray* obs);//получение препятствий
	int Getlive() { return live; }//отдача жизни
	void StartPozition();//позиция шара
};

