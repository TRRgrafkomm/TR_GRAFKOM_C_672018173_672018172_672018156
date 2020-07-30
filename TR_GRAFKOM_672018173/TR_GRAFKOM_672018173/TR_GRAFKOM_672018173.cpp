#include <gl\glut.h>
#include <windows.h>
#include <math.h>
#include <stdlib.h>

//naga sari inti sari purwosari
int is_depth;
float xrot = 0;
float yrot = 0;
float xdiff = 0;
float ydiff = 0;

bool mouseDown =false;	
float w(int x){
	float hasil = x;
	if(x>=255){
		hasil = 255;
	}else if(x<=0){
		hasil = 0;
	};
	return (float) hasil/255;
};
float c[100][4] = {{w(0),w(127),w(255),1.0f},
					{w(255),w(127),w(0),1.0f}
					};

void tabung(float radatas,float radbawah,float tinggi, float x, float y,float z, int mulai ,int stop){
	float theta,theti;
	int i,j;


	glPushMatrix();//bawah
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	for(i=mulai;i<stop;i++){
		theta = i*3.14/180;
		glVertex3f(x+radbawah*cos(theta),y,z+radbawah*sin(theta));
	};
	glEnd();
	//selimut
	glBegin(GL_POLYGON);
	glColor4f(0.0f, 0.0f, 0.0f, 0.0f);
	for(i=mulai;i<stop;i++){
		theta = i*3.14/180;
		if(i==359){
			j=0;
		}else{
			j=i+1;
		};
		theti = j*3.14/180;
		glVertex3f(x+radatas*cos(theta),y+tinggi,z+radatas*sin(theta));
		glVertex3f(x+radatas*cos(theti),y+tinggi,z+radatas*sin(theti));
		glVertex3f(x+radbawah*cos(theti),y,z+radbawah*sin(theti));
		glVertex3f(x+radbawah*cos(theta),y,z+radbawah*sin(theta));
	};
	glEnd();
	//atas
	glBegin(GL_POLYGON);
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	for(i=mulai;i<stop;i++){
		theta = i*3.14/180;
		glVertex3f(x+radatas*cos(theta),y+tinggi,z+radatas*sin(theta));
	};
	glEnd();
	glPopMatrix();
	glPopMatrix();
}

void idle(){
	if(!mouseDown){
	    xrot += 0.3f;
		yrot += 0.4f;
	}
	glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
	if(button == GLUT_LEFT_BUTTON&& state == GLUT_DOWN){
	mouseDown=true;
	xdiff=x-yrot;
	ydiff=-y+xrot;
	}
	else{
	mouseDown = false;
	}
	glutPostRedisplay();
}
void mousemotion(int x, int y){
		if (mouseDown){
		yrot=x-xdiff;
		xrot=y+ydiff;

		glutPostRedisplay();
		}
	}



void Traktor()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glRotatef(xrot, 1.0f, 0.0f, 0.0f);
	glRotatef(yrot, 0.0f, 1.0f, 0.0f);
	glLineWidth(4.0);
	glPointSize(15.0);
	glPushMatrix();
	
	//Ruang Supir
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);//depan
	glVertex3f( 0.0, 0.0, 0.0);
    glVertex3f( 0.0, 5.0, 0.0);
    glVertex3f( 5.0, 5.0, 0.0);
    glVertex3f( 5.0, 0.0, 0.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);//kanan
	glVertex3f( 5.0, 0.0, 0.0);
    glVertex3f( 5.0, 5.0, 0.0);
    glVertex3f( 5.0, 5.0, -3.0);
    glVertex3f( 5.0, 0.0, -3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);//belakang
	glVertex3f( 5.0, 0.0, -3.0);
    glVertex3f( 5.0, 5.0, -3.0);
    glVertex3f( 0.0, 5.0, -3.0);
    glVertex3f( 0.0, 0.0, -3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);//kiri
	glVertex3f( 0.0, 0.0, -3.0);
    glVertex3f( 0.0, 5.0, -3.0);
    glVertex3f( 0.0, 5.0, 0.0);
    glVertex3f( 0.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);//atas
	glVertex3f( 0.0, 5.0, 0.0);
    glVertex3f( 0.0, 5.0, -3.0);
    glVertex3f( 5.0, 5.0, -3.0);
    glVertex3f( 5.0, 5.0, 0.0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);//kaca
	glVertex3f( 5.0, 4.5, -0.5);
    glVertex3f( 5.0, 4.5, -2.5);
    glVertex3f( 5.0, 2.5, -2.5);
    glVertex3f( 5.0, 2.5, -0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,1);//kaca samping
	glVertex3f( 3.0, 1.5, 0.0);
    glVertex3f( 3.0, 4.5, 0.0);
    glVertex3f( 4.5, 4.5, 0.0);
    glVertex3f( 4.5, 1.5, 0.0);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0 , 0, 0);
	glVertex3f (4.2, 3.0, 0.0 );
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(1,1,1);//kaca samping
	glVertex3f( 1.0, 2.5, 0.0);
    glVertex3f( 1.0, 4.0, 0.0);
    glVertex3f( 2.5, 4.0, 0.0);
    glVertex3f( 2.5, 2.5, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,1);//kaca samping
	glVertex3f( 1.0, 0.8, 0.0);
    glVertex3f( 1.0, 2.3, 0.0);
    glVertex3f( 2.5, 2.3, 0.0);
    glVertex3f( 2.5, 0.8, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,1);//kaca bealakang
	glVertex3f( 0.0, 0.5, -2.5);
    glVertex3f( 0.0, 4.5, -2.5);
    glVertex3f( 0.0, 4.5, -0.5);
    glVertex3f( 0.0, 0.5, -0.5);
	glEnd();

	//Bodi
	glBegin(GL_POLYGON);
	glColor3f(1,1,0);//depan
	glVertex3f( -7.0, 0.0, -3.0);
    glVertex3f( -7.0, 3.0, -3.0);
    glVertex3f( 6.0, 3.0, -3.0);
    glVertex3f( 6.0, 0.0, -3.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex3f(-7.0, 2.0, -3.0);
	glVertex3f(6.0, 2.0, -3.0);
	glVertex3f(-7.0, 1.0, -3.0);
	glVertex3f(6.0, 1.0, -3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);//kanan
	glVertex3f( 6.0, 0.0, -3.0);
    glVertex3f( 6.0, 3.0, -3.0);
    glVertex3f( 6.0, 3.0, -7.0);
    glVertex3f( 6.0, 0.0, -7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);//belakang
	glVertex3f( 6.0, 0.0, -7.0);
    glVertex3f( 6.0, 3.0, -7.0);
    glVertex3f( -7.0, 3.0, -7.0);
    glVertex3f( -7.0, 0.0, -7.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0, 0 , 0);
	glVertex3f(6.0, 2.0, -7.0);
	glVertex3f(-7.0, 2.0, -7.0);
	glVertex3f(6.0, 1.0, -7.0);
	glVertex3f(-7.0, 1.0, -7.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( -7.0, 0.0, -7.0);
    glVertex3f( -7.0, 3.0, -7.0);
    glVertex3f( -7.0, 3.0, -3.0);
    glVertex3f( -7.0, 0.0, -3.0);
	glEnd();

	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex3f(-7.0, 2.0, -7.0);
	glVertex3f(-7.0, 2.0, -3.0);
	glVertex3f(-7.0, 1.0, -7.0);
	glVertex3f(-7.0, 1.0, -3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);//atas
	glVertex3f( -7.0, 3.0, -3.0);
    glVertex3f( -7.0, 3.0, -7.0);
    glVertex3f( 6.0, 3.0, -7.0);
    glVertex3f( 6.0, 3.0, -3.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( -7.0, 0.0, -3.0);
    glVertex3f( -7.0, 0.0, -7.0);
    glVertex3f( 6.0, 0.0, -7.0);
    glVertex3f( 6.0, 0.0, -3.0);
	glEnd();

	//Alas bodi
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f( -8.0, -0.5, 0.0);
    glVertex3f( -8.0, 0.0, 0.0);
    glVertex3f( 6.0, 0.0, 0.0);
    glVertex3f( 6.0, -0.5, 0.0);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(-3.0, 0.0, 0.0);
	glVertex3f(-3.0, 2.0, 0.0);
	glVertex3f(-4.0, 0.0, 0.0);
	glVertex3f(-4.0, 2.0, 0.0);
	glVertex3f(-4.0, 1.7, 0.0);
	glVertex3f(-3.0, 1.7, 0.0);
	glVertex3f(-4.0, 1.3, 0.0);
	glVertex3f(-3.0, 1.3, 0.0);
	glVertex3f(-4.0, 0.9, 0.0);
	glVertex3f(-3.0, 0.9, 0.0);
	glVertex3f(-4.0, 0.5, 0.0);
	glVertex3f(-3.0, 0.5, 0.0);
	glVertex3f(-4.0, 2.0, 0.0);
	glVertex3f(-4.0, 2.5, -0.5);
	glVertex3f(-3.0, 2.0, 0.0);
	glVertex3f(-3.0, 2.5, -0.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f( 6.0, -0.5, 0.0);
    glVertex3f( 6.0, 0.0, 0.0);
    glVertex3f( 6.0, 0.0, -8.0);
    glVertex3f( 6.0, -0.5, -8.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f( 6.0, -0.5, -8.0);
    glVertex3f( 6.0, 0.0, -8.0);
    glVertex3f( -8.0, 0.0, -8.0);
    glVertex3f( -8.0, -0.5, -8.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f( -8.0, -0.5, -8.0);
    glVertex3f( -8.0, 0.0, -8.0);
    glVertex3f( -8.0, 0.0, 0.0);
    glVertex3f( -8.0, -0.5, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f( -8.0, 0.0, 0.0);
    glVertex3f( -8.0, 0.0, -8.0);
    glVertex3f( 6.0, 0.0, -8.0);
    glVertex3f( 6.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f( -8.0, -0.5, 0.0);
    glVertex3f( -8.0, -0.5, -8.0);
    glVertex3f( 6.0, -0.5, -8.0);
    glVertex3f( 6.0, -0.5, 0.0);
	glEnd();

	//roda

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( -4.0, -2.0, -2.0);
    glVertex3f( -4.0, -0.5, -2.0);
    glVertex3f( 4.0, -0.5, -2.0);
    glVertex3f( 4.0, -2.0, -2.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( 4.0, -2.0, -2.0);
    glVertex3f( 4.0, -0.5, -2.0);
    glVertex3f( 4.0, -0.5, -6.0);
    glVertex3f( 4.0, -2.0, -6.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( 4.0, -2.0, -6.0);
    glVertex3f( 4.0, -0.5, -6.0);
    glVertex3f( -4.0, -0.5, -6.0);
    glVertex3f( -4.0, -2.0, -6.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( -4.0, -2.0, -6.0);
    glVertex3f( -4.0, -0.5, -6.0);
    glVertex3f( -4.0, -0.5, -2.0);
    glVertex3f( -4.0, -2.0, -2.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( -4.0, -2.0, -2.0);
    glVertex3f( -4.0, -2.0, -6.0);
    glVertex3f( 4.0, -2.0, -6.0);
    glVertex3f( 4.0, -2.0, -2.0);
	glEnd();
	//penahan penggali
	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( 14.5, -2.0, -2.5);
    glVertex3f( 15.5, 0.0, -2.5);
    glVertex3f( 16.0, 0.0, -2.5);
    glVertex3f( 16.5, -2.0, -2.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( 16.5, -2.0, -2.5);
    glVertex3f( 16.0, 0.0, -2.5);
    glVertex3f( 16.0, 0.0, -5.5);
    glVertex3f( 16.5, -2.0, -5.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( 16.5, -2.0, -5.5);
    glVertex3f( 16.0, 0.0, -5.5);
    glVertex3f( 15.5, 0.0, -5.5);
    glVertex3f( 14.5, -2.0, -5.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( 15.5, 0.0, -2.5);
    glVertex3f( 15.5, 0.0, -3.0);
    glVertex3f( 16.0, 0.0, -3.0);
    glVertex3f( 16.0, 0.0, -2.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( 16.0, 0.0, -2.5);
    glVertex3f( 15.5, 0.0, -2.5);
    glVertex3f( 15.5, 0.0, -5.5);
    glVertex3f( 16.0, 0.0, -5.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( 15.5, 0.0, -2.5);
    glVertex3f( 15.0, 3.0, -2.5);
    glVertex3f( 16.0, 3.0, -2.5);
    glVertex3f( 16.0, 0.0, -2.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( 15.5, 0.0, -5.5);
    glVertex3f( 15.0, 3.0, -5.5);
    glVertex3f( 16.0, 3.0, -5.5);
    glVertex3f( 16.0, 0.0, -5.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);//kanan
	glVertex3f( 16.0, 3.0, -2.5);
    glVertex3f( 16.0, 2.5, -2.5);
    glVertex3f( 6.0, 2.7, -2.5);
    glVertex3f( 6.0, 2.3, -2.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);//kiri
	glVertex3f( 16.0, 3.0, -5.5);
    glVertex3f( 16.0, 2.5, -5.5);
    glVertex3f( 5.0, 2.7, -5.5);
    glVertex3f( 5.0, 2.3, -5.5);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1,1,0);
	glVertex3f( 5.5, 0.0, -2.5);
    glVertex3f( 6.0, 4.0, -2.5);
    glVertex3f( 6.5, 4.0, -2.5);
    glVertex3f( 6.0, 0.0, -2.5);
	glEnd();


	//ban kanan
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f( -4.0, -1.0, 0.0);
    glVertex3f( -4.0, -1.0, -2.0);
    glVertex3f( 6.0,  -1.0, -2.0 );
    glVertex3f( 6.0,  -1.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f( -4.0, -3.0, 0.0);
    glVertex3f( -4.0, -3.0, -2.0);
    glVertex3f( 6.0,  -3.0, -2.0 );
    glVertex3f( 6.0,  -3.0, 0.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f( -3.5, -2.5, 0.1);
    glVertex3f( -3.5, -1.5, 0.1);
    glVertex3f( 5.5,  -1.5, 0.1 );
    glVertex3f( 5.5,  -2.5, 0.1);
	glEnd();

	//ban kiri
	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f( -4.0, -1.0, -6.0);
    glVertex3f( -4.0, -1.0, -8.0);
    glVertex3f( 6.0,  -1.0, -8.0 );
    glVertex3f( 6.0,  -1.0, -6.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f( -4.0, -3.0, -6.0);
    glVertex3f( -4.0, -3.0, -8.0);
    glVertex3f( 6.0,  -3.0, -8.0 );
    glVertex3f( 6.0,  -3.0, -6.0);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0,0,0);
	glVertex3f( -3.5, -2.5, -8.1);
    glVertex3f( -3.5, -1.5, -8.1);
    glVertex3f( 5.5,  -1.5, -8.1 );
    glVertex3f( 5.5,  -2.5, -8.1);
	glEnd();

	glRotatef(90, 1.0f, 0.0f, 0.0f);
	tabung(4.0f, 4.0f, 2.0f, 11.0f, -5.0f, -1.0f, 0, 360);
	tabung(1.0f, 1.0f, 2.0f, 6.0f, -2.0f, 2.0f, 0, 360);
	tabung(1.0f, 1.0f, 2.0f, -4.0f, -2.0f, 2.0f, 0, 360);
	tabung(1.0f, 1.0f, 2.0f, 6.0f, -8.0f, 2.0f, 0, 360);
	tabung(1.0f, 1.0f, 2.0f, -4.0f, -8.0f, 2.0f, 0, 360);

	glRotatef(90, 1.0f, 0.0f, 0.0f);
	tabung(1.0f, 1.0f, 4.0f, 8.0f, 2.0f, -6.0f, 0, 360);

	glPopMatrix();
	glutSwapBuffers();
}

void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;
 
   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);
 
   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective pojection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void inisialisasi() {
	glClearColor(0.0 , 1 , 1 , 1);
	glClearDepth(1.0f);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	is_depth = 1;
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}



void FungsiKeyboard(unsigned char key, int x, int y) {
	switch (key) {
		//gerak ke kiri
		case 'A':
		case 'a':
		glTranslatef(-1.0, 0.0, 0.0);
		break;

		//gerak ke kanan
		case 'D':
		case 'd':
		glTranslatef(1.0, 0.0, 0.0);
		break;

		//gerak ke depan
		case 'S':
		case 's':
		glTranslatef(0.0, 0.0, 1.0);
		break;

		//gerak ke belakang
		case 'W':
		case 'w':
		glTranslatef(0.0, 0.0, -1.0);
		break;

		//gerak ke atas
		case 'Q':
		case 'q':
		glTranslatef(0.0, 1.0, 0.0);
		break;

		//gerak ke bawah
		case 'Z':
		case 'z':
		glTranslatef(0.0, -1.0, 0.0);
		break;

		//rotate ke kiri
		case 'Y':
		case 'y':
		glRotatef(1.0, 0.0, -5.0, 0.0);
		break;

		//rotate ke kanan
		case 'I':
		case 'i':
		glRotatef(1.0, 0.0, 5.0, 0.0);
		break;

		//rotate ke samping kanan
		case 'K':
		case 'k':
		glRotatef(1.0, 0.0, 0.0, -5.0);
		break;

		//rotate ke samping kiri
		case 'H':
		case 'h':
		glRotatef(1.0, 0.0, 0.0, 5.0);
		break;

		//rotate ke atas
		case 'U':
		case 'u':
		glRotatef(1.0, -5.0, 0.0, 0.0);
		break;

		//rotate ke bawah
		case 'J':
		case 'j':
		glRotatef(1.0, 5.0, 0.0, 0.0);
		break;

		case '5':
			if (is_depth){
			is_depth = 0;
			glDisable (GL_DEPTH_TEST);
			}else
			{
			is_depth = 1;
			glDisable (GL_DEPTH_TEST);
			}
	Traktor();
		break;

		//exit
		case 27:
		exit(0);
	}
	Traktor();
}

int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(880, 700);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow("3GP");          // Create window with the given title
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   glutDisplayFunc(Traktor);       // Register callback handler for window re-paint event
   glutKeyboardFunc(FungsiKeyboard);
   glutMouseFunc(mouse);
   glutMotionFunc(mousemotion);
   inisialisasi();
	// Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}

