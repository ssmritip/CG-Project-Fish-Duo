#include "Draw.h"
float t = 0; // translation vector
bool s = true; // flag for direction
void translate(GLfloat upperCurve[3][3], GLfloat lowerCurve[3][3], float tCurve1[3][3], float tCurve2[3][3], float color){
	float uCurve[3][3], lCurve[3][3], u[3][3], l[3][3]; 
	int i, j, k, y;
	
	float tp[3][3] ={{1, 0, t},
					 {0, 1, 0},
					 {0, 0, 1}};
	float reflection[3][3] ={{-1, 0, 0},
					 {0, 1, 0},
					 {0, 0, 1}};
					 
		
	if(t < TANK_RIGHT && s == true){
		t = t + 0.001;
		y = 0;
		for (i = 0; i < 3; ++i){ //transpose original curve
			for (j = 0; j < 3; ++j) {
	    		u[j][i] = upperCurve[i][j];
	    		l[j][i] = lowerCurve[i][j];
	   		}
		}
	
		
		for(i = 0; i < 3;i++){
			for(j = 0; j < 3;j++){
				uCurve[i][j] = 0;
				lCurve[i][j] = 0;
				for(k = 0; k < 3;k++){
					uCurve[i][j] += tp[i][k]*u[k][j];
					lCurve[i][j] += tp[i][k]*l[k][j];
				}
			}
		}
		for (i = 0; i < 3; ++i){ //transpose back to original curve
			for (j = 0; j < 3; ++j) {
	    		tCurve1[j][i] = uCurve[i][j];
	    		tCurve2[j][i] = lCurve[i][j];
	   		}
		}
		if(t == TANK_RIGHT)
		s = false;
		fish(tCurve1, tCurve2, 1.0, y, color);
	}
	
	else if(t > TANK_LEFT){
		s = false;
		t = t - 0.001;
		y = -4;
		for (i = 0; i < 3; ++i){ //transpose original curve
			for (j = 0; j < 3; ++j) {
	    		u[j][i] = tCurve1[i][j];
	    		l[j][i] = tCurve2[i][j];
	   		}
		}
		for(i = 0; i < 3;i++){
			for(j = 0; j < 3;j++){
				uCurve[i][j] = 0;
				lCurve[i][j] = 0;
				for(k = 0; k < 3;k++){
					uCurve[i][j] += reflection[i][k]*u[k][j];
					lCurve[i][j] += reflection[i][k]*l[k][j];
				}
			}
		}
		for(i = 0; i < 3;i++){
			for(j = 0; j < 3;j++){
				u[i][j] = 0;
				l[i][j] = 0;
				for(k = 0; k < 3;k++){
					u[i][j] += tp[i][k]*uCurve[k][j];
					l[i][j] += tp[i][k]*lCurve[k][j];
				}
			}
		}
		if(t <TANK_LEFT)
		s = true;
		for (i = 0; i < 3; ++i){ //transpose back to original curve
			for (j = 0; j < 3; ++j) {
	    		uCurve[j][i] = u[i][j];
	    		lCurve[j][i] = l[i][j];
	   		}
		}
		fish(uCurve, lCurve, -1.0, y, color);
	}	
}
