#define TANK_RIGHT 3.5
#define TANK_LEFT 0

// coordinates of fish 1
GLfloat upperCurve1[3][3] = { {-2.5, 5, 1.0}, {-1.5, 6.2, 1.0}, {-0.5, 5, 1.0} };
GLfloat lowerCurve1[3][3] = { {-2.5, 5, 1.0}, {-1.5, 3.8, 1.0}, {-0.5, 5, 1.0} };

// coordinates of fish 2
GLfloat upperCurve2[3][3] = { {-1.3, 3.0, 1.0}, {0.0, 4.15, 1.0}, {1.3, 3.0, 1.0} };
GLfloat lowerCurve2[3][3] = { {-1.3, 3.0, 1.0}, {0.0, 1.75, 1.0}, {1.3, 3.0, 1.0} };
float u1[3][3], l1[3][3], u2[3][3], l2[3][3]; // temporary empty matrices

GLfloat tankCoord[4][2] = {{-5.25, 0.18},	//front glass
						   {-5.25, 6.8},
						   {5.25, 6.8},
						   {5.25, 0.18}},
		tankCoord1[4][2] = {{-4.5, 0.7},	//back glass
						   {-4.5, 7.5},
						   {4.5, 7.5},
						   {4.5, 0.7}},
		tableTop[4][2] = {{-6.2,-0.5},
						  {-6.2,0},
						  {6.2, 0},
						  {6.2,-0.5}},
		tableLeg[4][2] = {{-5.7,-5},
						  {-5.7,-0.5},
						  {-5.25,-0.5},
						  {-5.25,-5}},
		shift[3] = {10.75, 0.75, 10}, sy = 0.75;
		
class Grass{
	public:
	float vertexTipx, vertexTipy;
	float vertexBase1x = 0, vertexBase1y = 0.6;
	float vertexBase2x = 0.2, vertexBase2y = 0.6;
	float vertexL1x, vertexL2x, vertexR1x, vertexR2x,
		vertexL1y, vertexL2y, vertexR1y, vertexR2y;
	
		Grass(){}
		Grass(
			float ax, float ay, 
			float bx, float by,
			float cx, float cy
			){
			vertexTipx = ax;
			vertexTipy = ay;
			vertexL1x = bx;
			vertexL1y = by;
			vertexL2x = cx;
			vertexL2y = cy;
			
	        vertexR1x = vertexL1x + 0.2;
			vertexR1y = vertexL1y;
			vertexR2x = vertexL2x + 0.2;
			vertexR2y = vertexL2y;
		}
		Grass copy(Grass &other){ 
			vertexTipx = other.vertexTipx;
	        vertexTipy = other.vertexTipy;
	        vertexBase1x = other.vertexBase1x;
	        vertexBase1y = other.vertexBase1y;
	        vertexBase2x = other.vertexBase2x;
	        vertexBase2y = other.vertexBase2y;
	        vertexL1x = other.vertexL1x;
	        vertexL1y = other.vertexL1y;
	        vertexL2x = other.vertexL2x;
	        vertexL2y = other.vertexL2y;
	        vertexR1x = other.vertexR1x;
	        vertexR1y = other.vertexR1y;
	        vertexR2x = other.vertexR2x;
	        vertexR2y = other.vertexR2y;
		}
		void translateX(float t){	// t is translation factor
			vertexTipx += t;
	        vertexBase1x += t;
	        vertexBase2x += t;
	        vertexL1x += t;
	        vertexL2x += t;
	        vertexR1x += t;
	        vertexR2x += t;
		}
		Grass changeBase(float a, float b){
			vertexBase1x = a;
			vertexBase2x = b;
		}
		
		Grass changeTip(float y){
			vertexTipy = y;
		}
};
