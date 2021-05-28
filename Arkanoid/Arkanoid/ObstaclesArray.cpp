#include "ObstaclesArray.h"

ObstaclesArray::ObstaclesArray(int com) {
	this->count = 0;
	this->max_obstacles = 130;
	this->com = com;

	this->obstacles = new Obstacle * [max_obstacles];
	this->invalid = new int[max_obstacles];

	x = y = lengh = 0;
}

ObstaclesArray::~ObstaclesArray(void) {
	for (int i = 0; i < max_obstacles; i++) {
		if(invalid[i] != 0)
			delete this->obstacles[i];
	}
	delete[] this->obstacles;
	delete[] this->invalid;
}

void ObstaclesArray::Add(char* lvl) {
	Obstacle* obs;
	int str = 0;//строка
	int stl = 0;//столбец
	
	for (int i = 0; i < max_obstacles; i++) {
		if (stl == 10) {
			stl = 0;
			str++;
		}
		float x1 = x + (lengh * stl);
		float y1 = y + (lengh * str);
		float x2 = x + (lengh * (stl + 1));
		float y2 = y  + (lengh * (str + 1));

		switch (lvl[i]) {
		case(' '):
			invalid[i] = 0;
			break;
		case('1'):
			obs = new Obstacle(x1, y1, x2, y2, 1, com);
			count++;
			obstacles[i] = obs;
			invalid[i] = 1;
			break;
		case('2'):
			obs = new Obstacle(x1, y1, x2, y2, 2, com);
			count++;
			obstacles[i] = obs;
			invalid[i] = 1;
			break;
		case('3'):
			obs = new Obstacle(x1, y1, x2, y2, 3, com);
			count++;
			obstacles[i] = obs;
			invalid[i] = 1;
			break;
		}	
		stl++;
	}
}

void ObstaclesArray::Draw(RenderWindow* window) {
	for (int j = 0; j < max_obstacles; j++)
		if(invalid[j] != 0)
			obstacles[j]->Draw(window);	
}

void ObstaclesArray::SetField(PlayingField* field) {
	this->x = field->GetXL();
	this->y = field->GetYL();
	this->lengh = (field->GetXR() - field->GetXL()) / 10;
}

void ObstaclesArray::Move(float time) {
	for (int i = 0; i < max_obstacles; i++) {
		if(invalid[i] != 0)
			if (obstacles[i]->Get_Live() < 1) {
				delete obstacles[i];
				invalid[i] = 0;
				count--;
			}
		if (invalid[i] != 0) 
			obstacles[i]->Move(time);
	}
}