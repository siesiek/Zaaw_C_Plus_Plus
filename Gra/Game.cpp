#include "Game.h"
#include "CollisionActor.h"
#include <stdio.h>

Game::Game() {
	cannonAngle = 0.02f;
	cannonPower = 20.0f;
	shooting = false;
	viewPoint.Set(0.0f, 0.0f);
	shootCount = 20;
	successCount = 0;
	oldSuccesCount = successCount;

	b2Vec2 gravity;
	gravity.Set(0.0f, -10.0f);
	this->world = new b2World(gravity);
	listener = new MyContactListener(&successCount);
	this->world->SetContactListener(listener);
	createCannon();
	createTarget();
	target->ApplyForce(b2Vec2(1000.0f,0.0f),target->GetWorldCenter());
	this->ball = new Ball(this->world, cannon->GetWorldCenter());
	this->drawer = new DebugDraw();

	b2BodyDef groundDef;
	groundDef.position.Set(0.0f, -1.0f);
	b2Body* ground = this->world->CreateBody(&groundDef);
	b2PolygonShape groundShape;
	groundShape.SetAsBox(10.0f, 0.1f);
	b2FixtureDef groundFix;
	groundFix.density = 0.0f;
	groundFix.shape = &groundShape;
	groundFix.userData = new CollisionActor(CollisionActor::OTHER);
	ground->CreateFixture(&groundFix);


	uint32 flags = 0;
	flags += 1			* b2Draw::e_shapeBit;
	flags += 1			* b2Draw::e_jointBit;
	flags += 0			* b2Draw::e_aabbBit;
	flags += 0			* b2Draw::e_pairBit;
	flags += 0			* b2Draw::e_centerOfMassBit;
	this->drawer->SetFlags(flags);
	this->world->SetDebugDraw(this->drawer);
}

Game::~Game() {
	delete this->ball;
	delete this->world;
}

b2World* Game::getWorld(){
	return this->world;
}

Ball* Game::getBall(){
	return this->ball;
}

void Game::renderNext(){
	if(shootCount > 0){
		drawer->DrawString(20.0f, 20.0f,"Sila dziala: %f", cannonPower);
		drawer->DrawString(20.0f, 35.0f,"Twoj wynik: %i", successCount);
		drawer->DrawString(20.0f, 50.0f,"Pozostala liczba strzalow: %i", shootCount);
	}
	else{
		drawer->DrawString(20.0f, 20.0f,"KONIEC GRY!!!");
		drawer->DrawString(20.0f, 35.0f,"Twoj wynik: %i", successCount);
		drawer->DrawString(20.0f, 50.0f,"Aby rozpocząć gre od nowa nacisnij N");
	}
	this->world->Step(1.0f/180.0f, 6.0f, 2.0f);
	this->world->DrawDebugData();
	this->world->ClearForces();
	if(isShooting()){
//		viewPoint.x = ball->getPosition().x;
	}
	if(ball->getPosition().x > 10 || ball->getPosition().x < -10){
		reset();
	}
}

void Game::createCannon(){
	b2BodyDef def;
	def.position.Set(-0.9f, -0.9f);
	def.angle = cannonAngle * b2_pi;
	cannon = world->CreateBody(&def);

	b2Vec2 vs[4];
	vs[0].Set(0.0f, 0.0f);
	vs[1].Set(0.3f, 0.0f);
	vs[2].Set(0.0f, 0.05f);
	vs[3].Set(0.3f, 0.05f);

	b2EdgeShape shape;
	b2EdgeShape shape2;
	b2EdgeShape shape3;
	shape.Set(vs[0],vs[1]);
	shape2.Set(vs[0],vs[2]);
	shape3.Set(vs[2], vs[3]);
	b2FixtureDef fixture;
	b2FixtureDef fixture2;
	b2FixtureDef fixture3;
	fixture.shape = &shape;
	fixture.density = 0.0f;
	fixture.userData = new CollisionActor(CollisionActor::OTHER);
	fixture.friction = 0.0f;
	cannon->CreateFixture(&fixture);
	fixture2.density = 0.0f;
	fixture2.shape = &shape2;
	fixture2.userData = new CollisionActor(CollisionActor::OTHER);
	fixture2.friction = 0.0f;
	cannon->CreateFixture(&fixture2);
	fixture3.density = 0.0f;
	fixture3.shape = &shape3;
	fixture3.userData = new CollisionActor(CollisionActor::OTHER);
	fixture3.friction = 0.0f;
	cannon->CreateFixture(&fixture3);
}

void Game::reset(){
	this->world->ClearForces();
	delete this->ball;
	this->ball = new Ball(this->world, cannon->GetWorldCenter());
	shooting = false;
//	viewPoint.Set(-0.9f, 0.0f);
	if(oldSuccesCount != successCount){
		float32 x = ((float32) rand() / RAND_MAX);
		float32 y = ((float32) rand() / RAND_MAX);
		anchor->SetTransform(b2Vec2(x,y),0.0f);
		oldSuccesCount = successCount;
		printf("%f %f\n", x, y);
	}
}

void Game::cannonUp(){
	if(cannonAngle < 0.48){
		cannonAngle += 0.01;
	}
	delete this->ball;
	cannon->SetTransform(cannon->GetWorldCenter(),cannonAngle*b2_pi);
	this->ball = new Ball(this->world, cannon->GetWorldCenter());
}

void Game::cannonDown(){
	if(cannonAngle > 0.01){
		cannonAngle -= 0.01;
	}
	delete this->ball;
	cannon->SetTransform(cannon->GetWorldCenter(),cannonAngle*b2_pi);
	this->ball = new Ball(this->world, cannon->GetWorldCenter());
}

void Game::shoot(){
	if(!shooting && shootCount > 0){
		ball->shoot(cannon->GetAngle(), cannonPower);
		shooting = true;
		shootCount--;
	}
}

void Game::powerUp(){
	if(cannonPower < 98.0f){
		cannonPower += 2.0f;
	}
}

void Game::powerDown(){
	if(cannonPower > 5.0){
		cannonPower -= 2.0f;
	}
}

void Game::createTarget(){
	b2BodyDef staticDef;
	staticDef.position.Set(0.8f,0.5f);
	anchor = world->CreateBody(&staticDef);
	b2CircleShape anchorShape;
	anchorShape.m_radius = 0.01;
	b2FixtureDef anchorFix;
	anchorFix.density = 1.0f;
	anchorFix.shape = &anchorShape;
	anchorFix.userData = new CollisionActor(CollisionActor::OTHER);
	anchor->CreateFixture(&anchorFix);

	b2BodyDef targetDef;
	targetDef.type = b2_dynamicBody;
	targetDef.position.Set(0.8f, 0.3f);
	targetDef.linearDamping = 0.0f;
	targetDef.angularDamping = 0.0f;
	target = world->CreateBody(&targetDef);
	b2PolygonShape shape;
	shape.SetAsBox(0.1f, 0.1f);
	b2FixtureDef fix;
	fix.density = 1.0f;
	fix.shape = &shape;
	fix.restitution = 0.5f;
	fix.userData = new CollisionActor(CollisionActor::TARGET);
	target->CreateFixture(&fix);

	b2DistanceJointDef jointDef;
	jointDef.Initialize(anchor,target,anchor->GetWorldCenter(), target->GetWorldCenter());
	jointDef.length = 0.3f;
	b2DistanceJoint* joint = (b2DistanceJoint*)world->CreateJoint(&jointDef);
}

bool Game::isShooting(){
	return shooting;
}

b2Vec2 Game::getViewPoint(){
	return viewPoint;
}

void Game::moveLeft(){
	viewPoint.x -= 0.1f;
}

void Game::moveRight(){
	viewPoint.x += 0.1f;
}

void Game::newGame(){
	cannonAngle = 0.02f;
	cannonPower = 20.0f;
	shooting = false;
	viewPoint.Set(0.0f, 0.0f);
	shootCount = 20;
	successCount = 0;
	oldSuccesCount = successCount;
}
