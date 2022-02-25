#include <iostream>
#include <GL/glut.h>
#include <GLM/glm.hpp>
#include <time.h>


//CONSTANTES
#define FPS 60 // Constante de FPS

//DECLARACIONES
void display();



//VARIABLES GLOBALES
int initialTime = time(NULL), finalTime, frameCount = 0; // tiempo iniciañ, tiempo final, contador de frames

using namespace::std;

//FUNCIONES
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(600, 600);
	glutCreateWindow("PROYECTO VIDEOJUEGOS");
	glutDisplayFunc(display);
	glutPostRedisplay();
	glutMainLoop();
	return 0;
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glBegin(GL_TRIANGLES);
	{
		glColor3f(1.0, 0.0, 0.0); glVertex2f(0.0f, 0.5f);
		glColor3f(0.0, 1.0, 0.0); glVertex2f(-0.5f, -0.5f);
		glColor3f(0.0, 0.0, 1.0); glVertex2f(0.5f, -0.5f);

	}

	glEnd();
	glutSwapBuffers();// se finaliza la representacion de un frame
	frameCount++; // Se aumenta el contador de frames
	finalTime = time(NULL); // registra el tiempo final en segundos
	if (finalTime - initialTime > 0) //Valora si ha pasado un segundo
	{
		
		cout << "FPS:" << frameCount / (finalTime - initialTime) << endl; // Frames dibujados / tiempo en segundos = FPS
		frameCount = 0; //reinicia el contador de frames
		initialTime = finalTime; // El tiempo inicial ahora es igual al tiempo final de el calculo de la velocidad de los fotogramas

	}
}