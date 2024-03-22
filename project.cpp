#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>

GLfloat cx = -3, cy = 2, cz = 3, T=0;
void MyInit(){
	glEnable(GL_DEPTH_TEST);
	
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 2, 10);// to convert prog into prospective mode 
	glMatrixMode(GL_MODELVIEW);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}
void Spin(){
	T = T + 0.1;
	if(T>360)	T=0;
	glutPostRedisplay();
}
void press(unsigned char c, int x, int y){
	switch(c){
		case 'x': cx = cx - 0.5; break;
		case 'X': cx = cx + 0.5; break;
		case 'y': cy = cy - 0.5; break;
		case 'Y': cy = cy + 0.5; break;
		case 'z': cz = cz - 0.5; break;
		case 'Z': cz = cz + 0.5; break;	
	}
	glutPostRedisplay();
}
void draw(){
	GLfloat Pos[] = {0, 1, 0, 1};	//position of light
	GLfloat Col[] = {1, 0, 0, 1};	//color of light
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	glLightfv(GL_LIGHT0, GL_POSITION, Pos);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Col);
	
	glLoadIdentity();
	gluLookAt(cx, cy, cz, 0, 0, 0, 0, 1, 0);
	
//	glRotatef(T, 0, 1, 0); //parameters: angle, x, y, z
	
	glPushMatrix();
		glTranslatef(0.25, 0.9, 0.25);
		glScalef(1, 0.05, 1);
		glutSolidCube(1.75);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-0.5, 0.025, -0.5);
		glScalef(0.05, 1, 0.05);
		glutSolidCube(1.75);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(1, 0.025, -0.5);
		glScalef(0.05, 1, 0.05);
		glutSolidCube(1.75);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.5, 0.025, 0.5);
		glScalef(0.05, 1, 0.05);
		glutSolidCube(1.75);
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(-0.5, 0.025, 0.5);
		glScalef(0.05, 1, 0.05);
		glutSolidCube(1.75);
	glPopMatrix();	
	glutSwapBuffers();
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(200, 200);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Table");
	MyInit();
	
	glutDisplayFunc(draw);
	glutKeyboardFunc(press);
	glutIdleFunc(Spin);
	
	glutMainLoop();
}
