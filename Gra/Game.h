#ifndef GAME_H_
#define GAME_H_

#include <Box2D/Box2D.h>
#include "Ball.h"
#include "DebugDraw.h"
#include "MyContactListener.h"

class Game {
private:
	b2World* world;
	Ball* ball;
	DebugDraw* drawer;
	b2Body* cannon;
	b2Body* anchor;
	b2Body* target;
	float32 cannonAngle;
	float32 cannonPower;
	bool shooting;
	b2Vec2 viewPoint;
	int shootCount;
	int oldSuccesCount;
	int successCount;
	MyContactListener* listener;
public:
	Game();
	virtual ~Game();
	b2World* getWorld();
	Ball* getBall();
	void renderNext();
	void createCannon();
	void reset();
	void cannonUp();
	void cannonDown();
	void shoot();
	void powerUp();
	void powerDown();
	void createTarget();
	bool isShooting();
	b2Vec2 getViewPoint();
	void moveLeft();
	void moveRight();
	void newGame();
};

#endif /* GAME_H_ */
