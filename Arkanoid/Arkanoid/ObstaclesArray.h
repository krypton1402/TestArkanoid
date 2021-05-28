#pragma once
#include "Obstacle.h"
#include "PlayingField.h"

class ObstaclesArray {
private:
	int count;//Счетчик
	int max_obstacles;//Количество препятствий
	float lengh;//Длина препятствия
	int com;//Сложность
	float x, y;

public:
	int* invalid;//БОЛЬШОЙ КОСТЫЛЬ
	Obstacle** obstacles;

	ObstaclesArray(int com);
	virtual ~ObstaclesArray(void);
	void Add(char* lvl);//добавление препятствия в массив
	void Draw(RenderWindow* window);//отрисовка
	void SetField(PlayingField* field);//Получение границ поля
	void Move(float time);//Движение преград

	int Getmax() { return max_obstacles; }
	int GetCount() { return count; }//отдача счетчика
};

