#include "MyContactListener.h"
#include "CollisionActor.h"

MyContactListener::MyContactListener(int* points) {
	this->points = points;
}

MyContactListener::~MyContactListener() {
	// TODO Auto-generated destructor stub
}

void MyContactListener::BeginContact(b2Contact* contact){
	CollisionActor* actor1 = (CollisionActor*)contact->GetFixtureA()->GetUserData();
	CollisionActor* actor2 = (CollisionActor*)contact->GetFixtureB()->GetUserData();
	if((actor1->type == CollisionActor::BALL || actor1->type == CollisionActor::TARGET) && (actor2->type == CollisionActor::BALL || actor2->type == CollisionActor::TARGET)){
		(*points)++;
	}
}

void MyContactListener::EndContact(b2Contact* contact){

}

void MyContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold){

}

void MyContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse){

}
