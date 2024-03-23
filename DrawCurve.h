void drawCurve(GLfloat curve[3][3]) { 
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= 100; i++) {
        float u = i / 100.0;
        float x = (1 - u) * (1 - u) * curve[0][0] + 2 * (1 - u) * u * curve[1][0] + u * u * curve[2][0];
        float y = (1 - u) * (1 - u) * curve[0][1] + 2 * (1 - u) * u * curve[1][1] + u * u * curve[2][1];
        glVertex2f(x, y);
    }
    glEnd(); 
}
