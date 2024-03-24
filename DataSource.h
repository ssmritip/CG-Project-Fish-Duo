#define TANK_RIGHT 3.5
#define TANK_LEFT 0
GLfloat upperCurve1[3][3] = { {-1.0, 0.0, 1.0}, {0.0, 2.0, 1.0}, {2.0, 0.0, 1.0} };
GLfloat lowerCurve1[3][3] = { {-1.0, 0.0, 1.0}, {0.0, -2.0, 1.0}, {2.0, 0.0, 1.0} };

GLfloat upperCurve2[3][3] = { {-1.3, 3.0, 1.0}, {0.0, 5.0, 1.0}, {1.3, 3.0, 1.0} };
GLfloat lowerCurve2[3][3] = { {-1.3, 3.0, 1.0}, {0.0, 1.0, 1.0}, {1.3, 3.0, 1.0} };
float u1[3][3], l1[3][3], u2[3][3], l2[3][3]; // temporary empty matrices

GLfloat tankCoord[4][2] = {{-5, 0.5},
						   {-5, 7},
						   {5, 7},
						   {5, 0.5}},
		tableTop[4][2] = {{-6.2,-0.5},
						  {-6.2,0},
						  {6.2, 0},
						  {6.2,-0.5}},
		tableLeg[4][2] = {{-5.7,-5},
						  {-5.7,-0.5},
						  {-5.25,-0.5},
						  {-5.25,-5}},
		shift[3] = {10.75, 0.75, 10}, sy = 0.75;
