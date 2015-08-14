#include<Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926535898


using namespace std; //para dizer que não precisa colocar namespace na frente do objeto criado por ela

unsigned char var;
	void display()
	{
		/*  clear all pixels  */
		glClear(GL_COLOR_BUFFER_BIT);

		/*  draw white polygon (rectangle) with corners at
		*  (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
		*/
		glColor3f(1.0, 1.0, 1.0);
		if (var == 'a') {
			glBegin(GL_POLYGON);
			glVertex2f(0.00, 0.0);
			glVertex2f(0.0, 0.5);
			glVertex2f(0.95, 0.5);
			glVertex2f(0.95, 0.25);
			glVertex2f(0.8, 0.0);
			glEnd();
			glutPostRedisplay();
		} else if (var == 'b') {
			GLfloat circle_points = 0.99f;
			GLfloat angle, raioX = 0.055f, raioY = 0.055f;
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < circle_points; i++) {
				angle = 2 * PI*i / circle_points;
				glVertex2f(cos(angle)*raioX,
					sin(angle)*raioY);
			}
			glEnd();
			glutPostRedisplay();
		}
		else if (var == 'c') {

		}
		else if (var == 'd') {

		}
		else if (var == 'e') {

		}
		else if (var == 'f') {

		}
		else if (var == 'g') {

		}
		/*  don't wait!
		*  start processing buffered OpenGL routines
		*/
		glFlush();
	}

	void keyboard(unsigned char key, int x, int y) {
		if (key == 'q') {
			exit(0);
		}
		var = key;
	}

	void init(void){
		/*  select clearing (background) color       */
		glClearColor(0.0, 0.0, 0.0, 0.0);

		/*  initialize viewing values  */
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
	}

	/*
	*  Declare initial window size, position, and display mode
	*  (single buffer and RGBA).  Open window with "hello"
	*  in its title bar.  Call initialization routines.
	*  Register callback function to display graphics.
	*  Enter main loop and process events.
	*/
	int main(int argc, char** argv)
	{
		glutInit(&argc, argv);
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
		glutInitWindowSize(250, 250);
		glutInitWindowPosition(100, 100);
		glutCreateWindow("hello");
		init();
		glutDisplayFunc(display);
		glutKeyboardFunc(keyboard);
		glutMainLoop();
		return 0;   /* ISO C requires main to return int. */
}