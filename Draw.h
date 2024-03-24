void drawCurve(GLfloat curve[3][3], float color) { 
    glBegin(GL_TRIANGLE_FAN);
    float a;
    for (int i = 0; i <= 100; i++) {
        float u = i / 100.0;
        a = color / 80;
        float x = (1 - u) * (1 - u) * curve[0][0] + 2 * (1 - u) * u * curve[1][0] + u * u * curve[2][0];
        float y = (1 - u) * (1 - u) * curve[0][1] + 2 * (1 - u) * u * curve[1][1] + u * u * curve[2][1];
        glColor3f(1.0 - color/20, 0.0 + a, 0.2);
		glVertex2f(x, y);
		color += 1;
    }
    glEnd(); 
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
