#include "Box2D/Box2D.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include "Game.h"

using namespace std;

Game* game;
//b2Vec2 actPosition;

void move(b2Vec2 center){
	int32 width = 600;
	int32 height = 600;
	float32 viewZoom = 0.05f;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	b2Vec2 extents(25.0f, 25.0f);
	extents *= viewZoom;

	b2Vec2 lower = center - extents;
	b2Vec2 upper = center + extents;

	gluOrtho2D(lower.x, upper.x, lower.y, upper.y);
}

void createGame(){
	game = new Game();
}

void Timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(16, Timer, 0);
}

void gameLoop(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	game->renderNext();
	move(game->getViewPoint());

	glutSwapBuffers();
	glFlush();
}

void keyUp(unsigned char key, int x, int y){
	switch (key) {
		case ' ':
			game->shoot();
			break;
		case 'r':
			game->reset();
			move(game->getViewPoint());
			break;
		case 'a':
			game->cannonUp();
			break;
		case 'z':
			game->cannonDown();
			break;
		case '+':
			game->powerUp();
			break;
		case '-':
			game->powerDown();
			break;
		case 'n':
			game->newGame();
			break;
		case 'q':
			delete game;
			exit(0);
			break;
		default:
			break;
	}
}

void specialKey(int key, int x, int y){
	switch (key) {
		case GLUT_KEY_RIGHT:
			if(!game->isShooting()){
				game->moveRight();
			}
			break;
		case GLUT_KEY_LEFT:
			if(!game->isShooting()){
				game->moveLeft();
			}
			break;
		case GLUT_KEY_UP:
			game->cannonUp();
			break;
		case GLUT_KEY_DOWN:
			game->cannonDown();
			break;
		default:
			break;
	}
}

int main(int argc, char** argv){
	srand(time(NULL));
	createGame();
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(600,600);
	glutCreateWindow("Gra a'la Angry Birds ;)");
	glutDisplayFunc(gameLoop);
	glutKeyboardUpFunc(keyUp);
	glutSpecialUpFunc(specialKey);
	glutTimerFunc(16, Timer, 0);
	glutMainLoop();
	return 0;
}
