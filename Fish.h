#include "DrawCurve.h"
void fish(GLfloat upperCurve[3][3], GLfloat lowerCurve[3][3], float x, float y){
	// Draw upper and lower curves
    drawCurve(upperCurve);
    drawCurve(lowerCurve);

    // Draw fish tail
    glBegin(GL_TRIANGLES);
    glVertex2f(upperCurve[0][0], upperCurve[0][1]);          // Tail base
    glVertex2f(upperCurve[0][0] - x, upperCurve[0][1] + x);  // Tail tip
    glVertex2f(upperCurve[0][0] - x, upperCurve[0][1] - x);  // Tail tip
    glEnd();
    
    glPointSize(5.0);
    glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POINTS);
    glVertex2fv(upperCurve[0]);
    glEnd();
    
    // Draw eye
    glPointSize(5.0);
    glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POINTS);
    glVertex2f(upperCurve[0][0] + 2 + y, upperCurve[0][1] + 0.2);
    glEnd();
}	
