#ifndef MYCONTACTLISTENER_H_
#define MYCONTACTLISTENER_H_

#include <Box2D/Box2D.h>

class MyContactListener: public b2ContactListener {
private:
	int* points;
public:
	MyContactListener(int* points);
	virtual ~MyContactListener();
	void BeginContact(b2Contact* contact);
	void EndContact(b2Contact* contact);
	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
	void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
};

#endif /* MYCONTACTLISTENER_H_ */
