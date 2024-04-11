#include<windows.h>
#include<GL/glu.h>
#include<GL/glut.h>     
#include "Display.h"  
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(800, 600);               
    glutInitWindowPosition(100, 100);     
    glutCreateWindow("Fish Tank");  
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable( GL_BLEND );   
    glutDisplayFunc(display);                      
    glutIdleFunc(display);
    glutMainLoop();                
    return 0; 
}  
