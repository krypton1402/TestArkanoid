#include <SFML/Graphics.hpp>
#include "PlayingField.h"
#include "Platform.h"
#include "Ball.h"
#include "LVL.h"
#include "ObstaclesArray.h"
#include "GameStatus.h"

class OneManager{
private:
	Ball* bal;//Ша
	PlayingField* field;//Поле
	Platform* platform;//Платформа
	ObstaclesArray* obss;//враги
	GameStatus* status;//Статус
	LVL lvl;//Уровень
	
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

