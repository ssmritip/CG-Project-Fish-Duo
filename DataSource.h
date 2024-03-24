#define TANK_RIGHT 2
#define TANK_LEFT -2
GLfloat upperCurve1[3][3] = { {-1.0, 0.0, 1.0}, {0.0, 2.0, 1.0}, {2.0, 0.0, 1.0} };
GLfloat lowerCurve1[3][3] = { {-1.0, 0.0, 1.0}, {0.0, -2.0, 1.0}, {2.0, 0.0, 1.0} };

GLfloat upperCurve2[3][3] = { {-1.3, 3.0, 1.0}, {0.0, 5.0, 1.0}, {1.3, 3.0, 1.0} };
GLfloat lowerCurve2[3][3] = { {-1.3, 3.0, 1.0}, {0.0, 1.0, 1.0}, {1.3, 3.0, 1.0} };
float u1[3][3], l1[3][3], u2[3][3], l2[3][3]; // temporary empty matrices
