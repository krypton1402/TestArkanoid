#include "PlayingField.h"

PlayingField::PlayingField() {
	map_image.loadFromFile("images/map.png");//��������� ���� ��� ����
	map.loadFromImage(map_image);//�������� �������� ���������
	s_map.setTexture(map);//�������� �������� ��������

	map_image_bg.loadFromFile("images/map_bg.png");
	map_bg.loadFromImage(map_image_bg);
	s_bg.setTexture(map_bg);
	s_bg.setPosition(30, 30);
}

void PlayingField::Draw(RenderWindow* window) {
	for (int i = 0; i < HEIGHT_MAP; i++)
		for (int j = 0; j < WIDTH_MAP; j++)
		{
			if (Map[i][j] == '0') s_map.setTextureRect(IntRect(0, 0, 30, 30));//�������� 1� ���������
			s_map.setPosition(i * 30, j * 30);//������ ������� �������

			window->draw(s_map);//������ ���������� �� �����
		}
	window->draw(s_bg);
}
