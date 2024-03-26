#include<math.h>
void drawCurve(GLfloat curve[3][3], float color) { 
    glBegin(GL_TRIANGLE_FAN);
    float a;
    for (int i = 0; i <= 100; i++) {
        float u = i / 100.0;
        a = color / 80;
        float x = (1 - u) * (1 - u) * curve[0][0] + 2 * (1 - u) * u * curve[1][0] + u * u * curve[2][0];
        float y = (1 - u) * (1 - u) * curve[0][1] + 2 * (1 - u) * u * curve[1][1] + u * u * curve[2][1];
        glColor3f(1 - color*a/300, 0.0 + a*a, 0.4-a);
		glVertex2f(x, y);
		color += 1;
    }
    glEnd(); 
}
void drawGrass(Grass g){
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i <= 100; i++) {
        float u = i / 100.0;
        float x1 = pow((1-u),3)*g.vertexTipx + 3*pow((1-u),2)*u*g.vertexL1x + 3*u*u*(1 - u)*g.vertexL2y + pow(u, 3) * g.vertexBase1x;
        float y1 = pow((1-u),3)*g.vertexTipy + 3*pow((1-u),2)*u*g.vertexL1x + 3*u*u*(1 - u)*g.vertexL2y + pow(u, 3) * g.vertexBase1y;
        
        float x2 = pow((1-u),3)*g.vertexTipx + 3*pow((1-u),2)*u*g.vertexR1x + 3*u*u*(1 - u)*g.vertexR2y + pow(u, 3) * g.vertexBase2x;
        float y2 = pow((1-u),3)*g.vertexTipy + 3*pow((1-u),2)*u*g.vertexR1x + 3*u*u*(1 - u)*g.vertexR2y + pow(u, 3) * g.vertexBase2y;
        glColor3f(0.0, 0.6, 0.0);
		glVertex2f(x1, y1);
		glVertex2f(x2, y2);
    }
    glEnd();
}
void grass(){
	Grass g1(0.15, 2, -0.3, 1.5 , 5.7, 1);
	drawGrass(g1);
	
	Grass g2(g1);
	g2.translateX(1.0);
	drawGrass(g2);
	
	Grass g3(g1);
	g3.translateX(1.2);
	drawGrass(g3);
	
	Grass g4(g1);
	g4.translateX(-1.2);
	drawGrass(g4);
	
	Grass g5(g1);
	g5.translateX(1.4);
	drawGrass(g5);
	
	Grass g6(-1.68, 2.5, -1.3, 1.5 , 5.7, 1);
	//Grass g6(-4.68, 2, -4.3, 1 , -3.7, 1.5);
	g6.changeBase(-3, -3.1);
	drawGrass(g6);
	
	Grass g7(0.68, 2.5, -0.3, 1.5 , 5.7, 1);
	g7.translateX(-2);
	drawGrass(g7);
	
	Grass g8(0.68, 2.5, -0.3, 1.5 , 5.7, 1);
	drawGrass(g8);
	
	Grass g9(-2.68, 2.5, -2.3, 1.5 , 5.7, 1);
	g9.changeBase(-5, -5.1);
	drawGrass(g9);
	
//	Grass g10(-1.68, 1.5, -3.3, 1.5 , 0.7, 1);
//	g10.changeBase(-5, -5.1);
//	drawGrass(g10);
}
void fish(GLfloat upperCurve[3][3], GLfloat lowerCurve[3][3], float x, float y, float color){
	// Draw upper and lower curves
    drawCurve(upperCurve, color);
    drawCurve(lowerCurve, color);

    // Draw fish tail
    glBegin(GL_TRIANGLES);
    glVertex2f(upperCurve[0][0], upperCurve[0][1]);          // Tail base
    glVertex2f(upperCurve[0][0] - x, upperCurve[0][1] + x);  // Tail tip
    glVertex2f(upperCurve[0][0] - x, upperCurve[0][1] - x);  // Tail tip
    glEnd();
    
    glPointSize(5.0);
    glColor3f(0.5, 0.6, 0.8);
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

void drawTank(GLfloat tank[4][2]){
	glLineWidth(2);
	glBegin(GL_LINES);
		glColor3f(0, 0, 0);
		glVertex2fv(tank[0]); glVertex2fv(tank[1]);
		glVertex2fv(tank[1]); glVertex2fv(tank[2]);
		glVertex2fv(tank[2]); glVertex2fv(tank[3]);
		glVertex2fv(tank[0]); glVertex2fv(tank[3]);
	glEnd();
}

void rect(GLfloat V[4][2], GLfloat R, GLfloat G, GLfloat B){
	glBegin(GL_POLYGON);
		glColor3f(R, G, B);
		glVertex2fv(V[0]);
		glVertex2fv(V[1]);
		glVertex2fv(V[2]);
		glVertex2fv(V[3]);
	glEnd();
}
//Table surface part
void drawSurface(GLfloat TC[4][2],GLfloat TT[4][2]){
	glColor3f(0.7, 0.4, 0);
	glBegin(GL_TRIANGLES);
		glVertex2fv(TT[1]);
		glVertex2f(TC[0][0],TC[0][1]+1);
		glVertex2f(TC[0][0],TC[0][1]-0.5);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex2fv(TT[2]);
		glVertex2f(TC[3][0],TC[3][1]+1);
		glVertex2f(TC[3][0],TC[3][1]-0.5);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(TC[0][0],TC[0][1]); 
		glVertex2f(TC[0][0],TC[0][1]-0.5);
		glVertex2f(TC[3][0],TC[3][1]-0.5);
		glVertex2f(TC[3][0],TC[3][1]); 
	glEnd();
}

void tankTable(){
	glLoadIdentity();
	drawTank(tankCoord);
	//table top
	drawSurface(tankCoord,tableTop);
	rect(tableTop, 0, 0, 0);
	//table legs 
	rect(tableLeg, 0, 0, 0);	//Left Front Leg
	
	glTranslatef(shift[0], 0, 1);
	rect(tableLeg, 0, 0, 0);	//Right Front Leg

	glLoadIdentity();
	glTranslatef(shift[1], 0, 1);
	glScalef(1, sy, 1);
	rect(tableLeg, 0, 0, 0);	//Left Back Leg

	glLoadIdentity();
	glTranslatef(shift[2], 0, 1);
	glScalef(1, sy, 1);
	rect(tableLeg, 0, 0, 0);	//Right Back Leg
}
