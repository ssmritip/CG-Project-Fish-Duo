#include "DataSource.h"
#include "Translate.h"
#include<iostream>
void display() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

	//glColor3f(0.0, 0.0, 1.0);

    translate(upperCurve1, lowerCurve1, u1, l1, -30, -0.49);
	
    //glColor3f(0.0, 1.0, 0.0);
    translate(upperCurve2, lowerCurve2, u2, l2, 30, -0.21);
    grass();
    glLoadIdentity();
    tankTable();
	glutSwapBuffers();
    glFlush();
}
