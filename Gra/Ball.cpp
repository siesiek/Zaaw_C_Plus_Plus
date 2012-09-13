#include "Ball.h"
#include "CollisionActor.h"
#include <math.h>

Ball::Ball(b2World* world, b2Vec2 position) {
	this->world = world;
	b2BodyDef def;
	def.type = b2_dynamicBody;
	def.position.Set(position.x, (position.y + 0.01f));
	this->body = world->CreateBody(&def);
	b2CircleShape shape;
	shape.m_radius = 0.02f;
	b2FixtureDef fixture;
	fixture.density = 10.0f;
	fixture.shape = &shape;
	fixture.friction = 0.1f;
	fixture.restitution = 0.0f;
	fixture.userData = new CollisionActor(CollisionActor::BALL);
	this->body->CreateFixture(&fixture);
}

Ball::~Ball() {
	this->world->DestroyBody(this->body);
}

b2Body* Ball::getbody(){
	return this->body;
}

void Ball::shoot(float32 angle, float32 power){
	b2Vec2 force;
	force.x = power*cos(angle);
	force.y = power*sin(angle);
	this->body->ApplyForce(force,this->body->GetWorldCenter());
}

void Ball::setPosition(b2Vec2 pos){
	b2Vec2 tmp;
	tmp.Set(pos.x, pos.y + 0.01f);
	this->body->SetTransform(tmp,0.0f);
}

b2Vec2 Ball::getPosition(){
	return body->GetPosition();
}
