#include "DataSource.h"
#include "Translate.h"
#include "wave.h"
#include<iostream>
void display() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	
	glLoadIdentity();
	tankTable();
	drawSurface(tankCoord,tableTop);

    wave();

    glLoadIdentity();
	drawTank(tankCoord,tankCoord1);
	
	grass();
	
    bubble();
   time+=0.01;

//    translate(upperCurve1, lowerCurve1, u1, l1, 2, -0.49);
//    translate(upperCurve2, lowerCurve2, u2, l2, 15, -0.21);
   translate(upperCurve1, lowerCurve1, u1, l1, -50, -0.49);
	translate(upperCurve2, lowerCurve2, u2, l2, 0, -0.21);
    glFlush();
}

