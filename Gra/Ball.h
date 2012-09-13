#ifndef BALL_H_
#define BALL_H_

#include <Box2D/Box2D.h>

class Ball {
private:
	b2Body* body;
	b2World* world;
public:
	Ball(b2World* world, b2Vec2 position);
	virtual ~Ball();
	b2Body* getbody();
	void shoot(float32 angle, float32 power);
	void setPosition(b2Vec2 pos);
	b2Vec2 getPosition();
};

#endif /* BALL_H_ */
