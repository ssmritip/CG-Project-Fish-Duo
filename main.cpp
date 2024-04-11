#include<windows.h>
#include<GL/glu.h>
#include<GL/glut.h>     
#include "Display.h"  
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);               
    glutInitWindowPosition(100, 100);     
    glutCreateWindow("Fish Tank");     
    glutDisplayFunc(display);
   	//glutTimerFunc(10 ,timer, 0);                         
   glutIdleFunc(display);
    glutMainLoop();                
    return 0; 
}  
