void reshape(int,int);
void wave();
void timer(int);

float wave_ordinate(float,float,float,float,float);

struct sin_wave
{
    float k,w,A,phi;
};
sin_wave w1 = {1, 0.1, 0.2, 0};
sin_wave w2 = {1.5,0.2, 0.1, 45};
float time=0.0;


void wave()
{
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0,0.0,1.0);

    for(float x = -4.5 ; x < 5 ; x+=0.5)
    {
        float y = wave_ordinate(w1.k,w1.w,w1.A,w1.phi,x);
        glVertex2f(x,y+7.8);
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    for(float x = -5.25 ; x < 5.3 ; x+=0.5)
    {
        float y = wave_ordinate(w2.k,w2.w,w2.A,w2.phi,x);
        glVertex2f(x,y+7.6);
    }

    glEnd();
}

void timer(int)
{
	time+=0.5;
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
			glColor3f (0.0, 0.0, 1.0);
//			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glBegin(GL_LINE_STRIP);
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
				posy +=0.001;
			}
		}
};
Bubble b1=Bubble(-3,0.5,0.1),b2=Bubble(2.5,0.5,0.2),b3=Bubble(-2.5,0.7,0.05);

void bubble() {

	    glColor3f(1.0, 1.0, 1.0);
		b1.render(); b2.render();b3.render();
		b1.changepos();b2.changepos();b3.changepos(); 
}
