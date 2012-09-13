#ifndef COLLISIONACTOR_H_
#define COLLISIONACTOR_H_

class CollisionActor {
public:
	static const int BALL = 1;
	static const int TARGET = 2;
	static const int OTHER = 3;
	int type;
	CollisionActor(int type);
	virtual ~CollisionActor();
};

#endif /* COLLISIONACTOR_H_ */
