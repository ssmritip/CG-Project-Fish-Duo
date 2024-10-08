void reshape(int,int);
void wave();
void timer(int);

float wave_ordinate(float,float,float,float,float);

struct sin_wave{
    float k,w,A,phi;
};

sin_wave w1 = {1.3, 0.3, 0.5, 90};
float time = 0.0;

void wave1(sin_wave w, float yc){
    glBegin(GL_POLYGON);
    for(float x = -5.25 ; x < 5.3 ; x+=0.1){
        float y = wave_ordinate(w.k,w.w,w.A,w.phi,x);
        glVertex2f(x,y + yc);
    }
    glEnd();
}
void wave(){
	glColor4f(0.0f, 0.749f, 1.0f, 0.1f);
	wave1(w1, 7.25);

	glBegin(GL_POLYGON);
        glVertex2f(-5.28, 0.2);
        glVertex2f(-5.28, 7.595);
        glVertex2f(5.28, 7.595);
        glVertex2f(5.28, 0.2);
    glEnd();
	
}
void timer(int)
{
	time+=0.9;
	glutPostRedisplay();
    glutTimerFunc(1000.0/60.0,timer,0);
}

float wave_ordinate(float k,float w,float A,float phi,float x)
{
    return A * sin( (k*x) - (w*time) + phi);
}
//bubble 
class Bubble {
	private:
		float posx, posy, r;
		void circleFunc(float d,float x1,float y1)
		{
			float pi=3.1415, x, y,angle;
		    for(angle=0; angle<360.0; angle+=1)
			{
		        y =(sin(angle*pi/180)*d);
		        x =(cos(angle*pi/180)*d);
		        glVertex2f(x+x1,y+y1);
			}
		}
	public:
		Bubble(float x,float y, float r)
		{
			this->posx=x;
			this->posy=y;
			this->r=r;
		}
		void render ()
		{
			glColor4f(0, 0, 0, 0.1);
			glBegin(GL_TRIANGLE_FAN);
			circleFunc(2*r,posx,posy);
			glEnd();
		}
		void changepos ()
		{
			if (posy>5)
			{
				posy=0.65;
			}
			else
			{
				posy +=0.0045;
			}
		}
};
Bubble b1=Bubble(-3,0.5,0.1),b2=Bubble(2.5,0.5,0.2),b3=Bubble(-2.5,0.7,0.05);

void bubble() {
		b1.render(); b2.render();b3.render();
		b1.changepos();b2.changepos();b3.changepos(); 
}
