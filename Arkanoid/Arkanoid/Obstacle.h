#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

class Obstacle
{
private:
	Image obs_image;//объект изображения для поля
	Texture obs;//текстура поля
	Sprite s_obs;//создаём спрайт для поля

	float xLeft;//координата х левой стороны
	float xRight;//координата х правой стороны
	float yTop;//координата у вершины
	float yBottom;//координата у основания
	float V_Y;//Скорость
	int live;//Жизни

	float Ytikstur;//координата текстурв по y
	float CurientTime;//текущий кадр

public:
	Obstacle(float xLeft, float yTop, float xRight, float yBottom, int live, int com);
	virtual ~Obstacle();
	void Draw(RenderWindow* window);//отрисовка
	void Move(float time);//Движение преграды
	void LiveDown();//Уменьшение жизни

	float Get_xLeft() { return this->xLeft; }
	float Get_xRight() { return this->xRight; }
	float Get_yTop() { return this->yTop; }
	float Get_yBottom() { return this->yBottom; }
	int Get_Live() { return this->live; }
};

