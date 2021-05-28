#include <SFML/Graphics.hpp>
#include "PlayingField.h"
#include "Platform.h"
#include "Ball.h"
#include "LVL.h"
#include "ObstaclesArray.h"
#include "GameStatus.h"

class OneManager{
private:
	Ball* bal;//��
	PlayingField* field;//����
	Platform* platform;//���������
	ObstaclesArray* obss;//�����
	GameStatus* status;//������
	LVL lvl;//�������
	
	int lvl_number;
	bool pause;
	bool win;
	bool looz;

public:
	OneManager(int com);
	virtual ~OneManager();
	virtual void Move(float time);
	virtual void Draw(RenderWindow* window);
	virtual void MoveGoLeft(float time);
	virtual void MoveGoRight(float time);
	void Pause();
};

