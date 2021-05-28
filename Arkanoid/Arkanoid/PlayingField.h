#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

//����� �� y = 900, x = 600
//���� ���� 30 �� 30
class PlayingField {
private:
	Image map_image;//������ ����������� ��� ����
	Texture map;//�������� ����
	Sprite s_map;//������ ������ ��� ����

	Image map_image_bg;//������ ����������� ��� ����
	Texture map_bg;//�������� ����
	Sprite s_bg;//������ ������ ��� ����

	const int HEIGHT_MAP = 20;//������ ����
	const int WIDTH_MAP = 30;//������ ����
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
	void Draw(RenderWindow* window);//���������
	float GetXL() { return 30; }//��������� ������ X
	float GetYL() { return 30; }//��������� ������ Y
	float GetXR() { return 570; }//��������� ������� X
	float GetYR() { return 870; }//��������� ������� Y
};

