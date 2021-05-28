#pragma once
#include "Obstacle.h"
#include "PlayingField.h"

class ObstaclesArray {
private:
	int count;//�������
	int max_obstacles;//���������� �����������
	float lengh;//����� �����������
	int com;//���������
	float x, y;

public:
	int* invalid;//������� �������
	Obstacle** obstacles;

	ObstaclesArray(int com);
	virtual ~ObstaclesArray(void);
	void Add(char* lvl);//���������� ����������� � ������
	void Draw(RenderWindow* window);//���������
	void SetField(PlayingField* field);//��������� ������ ����
	void Move(float time);//�������� �������

	int Getmax() { return max_obstacles; }
	int GetCount() { return count; }//������ ��������
};

