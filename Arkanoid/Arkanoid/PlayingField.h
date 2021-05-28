#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

//Длина по y = 900, x = 600
//Один блок 30 на 30
class PlayingField {
private:
	Image map_image;//объект изображения для поля
	Texture map;//текстура поля
	Sprite s_map;//создаём спрайт для поля

	Image map_image_bg;//объект изображения для поля
	Texture map_bg;//текстура поля
	Sprite s_bg;//создаём спрайт для поля

	const int HEIGHT_MAP = 20;//высота поля
	const int WIDTH_MAP = 30;//ширина поля
	String Map[20] = {
		"000000000000000000000000000000",
		"0                            0",
		"0                            0",
		"0                            0",
		"0                            0",
		"0                            0",
		"0                            0",
		"0                            0",
		"0                            0",
		"0                            0",
		"0                            0",
		"0                            0",
		"0                            0",
		"0                            0",
		"0                            0",
		"0                            0",
		"0                            0",
		"0                            0",
		"0                            0",
		"000000000000000000000000000000"
	};

public:
	PlayingField();
	void Draw(RenderWindow* window);//отрисовка
	float GetXL() { return 30; }//Получение левого X
	float GetYL() { return 30; }//Получение левого Y
	float GetXR() { return 570; }//Получение правого X
	float GetYR() { return 870; }//Получение правого Y
};

