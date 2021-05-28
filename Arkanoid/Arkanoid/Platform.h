#pragma once
#include <SFML/Graphics.hpp>
#include "PlayingField.h"
#include <iostream>
using namespace sf;

class Platform {
private:
	Image platform_image;//объект изображения для поля
	Texture platform;//текстура поля
	Sprite s_platform;//создаём спрайт для поля

	float vx;//скорость
	float xleft, xright, yleft, yright;//координаты
	int platformsise;//длина платформы
	int com;//сложность
	float borderL;//Правая граница
	float borderR;//Левая граница

	int n;//количество платформ;

public:
	//идеальные координаты для центра: 175, 750, 251, 740 координаты расположения прямоугольника
	Platform(int com, int n);
	virtual ~Platform();
	void Draw(RenderWindow* window);//отрисовка
	void MoveXleft(float time);//Движение влево
	void MoveXright(float time);//Движение вправо
	void SetFild(PlayingField* fild);//Получение границ поля

	float GetX_L() { return xleft; }
	float GetY_L() { return yleft; }
	float GetX_R() { return xright; }
	float GetY_R() { return yright; }
	int GetSise() { return platformsise; }
};

