#include "DataSource.h"
#include "Translate.h"
void display() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	glColor3f(0.0, 0.0, 1.0);

    translate(upperCurve1, lowerCurve1, u1, l1);
	
    glColor3f(1.0, 0.0, 0.0);
    translate(upperCurve2, lowerCurve2, u2, l2);
	glutSwapBuffers();
    glFlush();
}
