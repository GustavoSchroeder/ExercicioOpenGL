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
			glBegin(GL_POLYGON); // ou glBegin(GL_POINTS);
			glVertex2f(0.0, 0.0);
			glVertex2f(0.0, 0.30);
			glVertex2f(0.40, 0.30);
			glVertex2f(0.60, 0.15);
			glVertex2f(0.40, 0.0);
			glEnd();
			glutPostRedisplay();
		} else if (var == 'b') {
			GLfloat circle_points = 50.5f;
			GLfloat angle, raioX = 0.55f, raioY = 0.55f;
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
			GLfloat circle_points = 90.0f;
			GLfloat angle, raioX = 0.50f, raioY = 0.50f;
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < circle_points; i++) {
				angle = 2 * PI*i / circle_points;
				glVertex2f(cos(angle)*raioX,
					sin(angle)*raioY);
			}
			glEnd();
			glutPostRedisplay();
		}
		else if (var == 'd') {
			GLfloat circle_points = 90.5f;
			GLfloat angle, raioX = 0.55f, raioY = 0.11f;
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < circle_points; i++) {
				angle = 2 * PI*i / circle_points;
				glVertex2f(cos(angle)*raioX,
					sin(angle)*raioY);
			}
			glEnd();
			glutPostRedisplay();
		}
		else if (var == 'e') {
		}
		else if (var == 'f') {
			//define fatia de pizza
			GLfloat circle_points = 5.0f;
			GLfloat angle, raioX = 0.55f, raioY = 0.55f;
			glBegin(GL_LINE_LOOP);
			for (int i = 0; i < circle_points / 2; i++) {
				angle = 2 * PI*i / circle_points;
				glVertex2f(cos(angle)*raioX,
					sin(angle)*raioY);
			}
			glEnd();
			glutPostRedisplay();

		}
		else if (var == 'g') {

		}
		else if(var == "1"){
			glBegin(GL_TRIANGLES);
		        glColor3f(1.0, 1.0, 1.0);
 			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(1.0, 0.0, 0.0);
			glVertex3f(0.5, 0.5, 0.0);
			glBegin(GL_TRIANGLES);
		        glColor3f(1.0, 1.0, 1.0);
 			glVertex3f(0.0, 0.0, 0.0);
			glVertex3f(-1.0, 0.0, 0.0);
			glVertex3f(-0.5, -0.5, 0.0);
glEnd(); 
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
		glClearColor(0.00, 0.0, 30.0, 0.0);

		/*  initialize viewing values  */
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0.5, 0.5, 0.5, 00.0, 00.0, 20.0);
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
		glutInitWindowSize(800, 400);
		glutInitWindowPosition(100, 100);
		glutCreateWindow("hello");
		init();
		glutDisplayFunc(display);
		glutKeyboardFunc(keyboard);
		glutMainLoop();
		return 0;   /* ISO C requires main to return int. */
}
