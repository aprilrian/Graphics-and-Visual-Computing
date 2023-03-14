// Nama			: Aprilyanto Setiyawan Siburian
// NIM			: 24060121120022
// Lab			: GKV B2
// Nama	File	: truk_gandeng.cpp
// Deskripsi	: Membuat sebuah truk gandeng dengan memanfaatkan depth dan lighting

// Template untuk mainan objek 3D 
// Kamera bisa maju mundur kiri kanan 
// Sudah dilengkapi pencahayaan 
// Sekarang pake texture 
#include <math.h> 
#include <GL/glut.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 
#include <unistd.h>

float rotangle=0.0;
float rotangle1=0.0;
float angle=0.0, deltaAngle = 0.0, ratio;
float x=0.0f,y=3.0f,z=25.0f; // posisi awal kamera
float lx=0.0f,ly=0.0f,lz=-1.0f;
int deltaMove = 0,h,w;
int bitmapHeight=12;
int i,j,radius,jumlah_titik,x_tengah,y_tengah;
const double PI = 3.141592653589793;

void Reshape(int w1, int h1) 
{ 
 	// Fungsi reshape 
 	if(h1 == 0) h1 = 1; 
 	w = w1; 
 	h = h1; 
 	ratio = 1.0f * w / h; 
 	glMatrixMode(GL_PROJECTION); 
 	glLoadIdentity(); 
 	glViewport(0, 0, w, h); 
 	gluPerspective(45,ratio,0.1,1000); 
 	glMatrixMode(GL_MODELVIEW); 
 	glLoadIdentity(); 
 	gluLookAt(
 		x, y, z, 
 		x + lx,y + ly,z + lz, 
 		0.0f,1.0f,0.0f); 
} 

void orientMe(float ang) 
{ 
 	// Fungsi ini untuk memutar arah kamera (tengok kiri/kanan) 
 	lx = sin(ang); 
 	lz = -cos(ang); 
 	glLoadIdentity(); 
 	gluLookAt(x, y, z, 
 		x + lx,y + ly,z + lz, 
 		0.0f,1.0f,0.0f); 
} 

void moveMeFlat(int i) 
{ 
 	// Fungsi ini untuk maju mundur kamera 
 	x = x + i*(lx)*0.1; 
 	z = z + i*(lz)*0.1; 
 	glLoadIdentity(); 
 	gluLookAt(x, y, z, 
 		x + lx,y + ly,z + lz, 
 		0.0f,1.0f,0.0f); 
} 

void Grid() { 
 // Fungsi untuk membuat grid di "lantai" 
 	double i; 
 	const float Z_MIN = -100, Z_MAX = 100; 
 	const float X_MIN = -100, X_MAX = 100; 
 	const float gap = 1.5; 
 	glColor3f(0.5, 0.5, 0.5); 
 	glBegin(GL_LINES); 
 	for(i=Z_MIN;i<Z_MAX;i+=gap) 
 	{ 
 		glVertex3f(i, 0, Z_MIN); 
 		glVertex3f(i, 0, Z_MAX); 
 	} 
 	for(i=X_MIN;i<X_MAX;i+=gap) 
 	{ 
 	glVertex3f(X_MIN, 0, i); 
 	glVertex3f(X_MAX, 0, i); 
 	} 
 	glEnd(); 
}


void wheel(){
	//fungsi membuat roda
	glPushMatrix();
		for(int j=0; j<=360; j++) {
			glPushMatrix();
				glTranslatef(1,0,-0.5);
				glRotated(90,1,0,0);
				glRotated(j,0,1,0);
				glTranslatef(0,3,0.8);
				glColor3f(0.1,0.1,0.1);
				glBegin(GL_QUADS);
				glVertex3f(0,0,0);
				glVertex3f(0.1,0,0);
				glVertex3f(0.1,0.6,0);
				glVertex3f(0,0.6,0);
				glEnd();
			glPopMatrix();
		}
	glPopMatrix();

	// lingkaran depan
	glPushMatrix();
		glTranslatef(0,0,3.1);
		glColor3f(0.1,0.1,0.1);
		glBegin(GL_TRIANGLE_FAN);
		radius=80;
		jumlah_titik=100;
		x_tengah=100;
		y_tengah=0;
		for (i=0; i<=360; i++) {
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
		glEnd();
	glPopMatrix();

	// lingkaran belakang
	glPushMatrix();
		glTranslatef(0,0,2.5);
		glRotated(180,1,0,0);
		glColor3f(0.1,0.1,0.1);
		glBegin(GL_TRIANGLE_FAN);
		radius=80;
		jumlah_titik=100;
		x_tengah=100;
		y_tengah=0;
		for (i=0; i<=360; i++) {
			float sudut=i*(2*PI/jumlah_titik);
			float x=x_tengah+radius*cos(sudut);
			float y=y_tengah+radius*sin(sudut);
			glVertex2f(x/100,y/100);
		}
		glEnd();
	glPopMatrix();
}

void Head() 
{ 
	//sisi depan
	 glPushMatrix(); 
		 glTranslatef(0,0,3); 
		 glBegin(GL_QUADS); 
		 glColor3f(0.1,0.1,0.1);
		 glVertex3f(-5.0f,1.0f,0.0f); 
		 glVertex3f(5.0f,1.0f,0.0f); 
		 glVertex3f(5.0f,6.0f,0.0f); 
		 glVertex3f(-5.0f,6.0f,0.0f); 
		 glEnd(); 
	 glPopMatrix(); 

	 glPushMatrix(); 
		 glTranslatef(0,0,3); 
		 glBegin(GL_QUADS); 
		 glColor3f(0.0,0.5,0.5);
		 glVertex3f(-5.0f,6.0f,0.0f); 
		 glVertex3f(5.0f,6.0f,0.0f); 
		 glVertex3f(5.0f,11.0f,-2.0f);
		 glVertex3f(-5.0f,11.0f,-2.0f);
		 glEnd(); 
	 glPopMatrix(); 
 
 	//sisi samping
	 glPushMatrix(); 
		 glTranslatef(0,0,3); 
		 glBegin(GL_QUADS); 
		 glColor3f(1.0,0.0,0.0);
		 glVertex3f(5.0f,1.0f,0.0f); 
		 glVertex3f(5.0f,6.0f,0.0f); 
		 glVertex3f(5.0f,6.0f,-7.0f);
		 glVertex3f(5.0f,1.0f,-7.0f);
		 glEnd(); 
	 glPopMatrix();
 
	 glPushMatrix(); 
		 glTranslatef(0,0,3); 
		 glBegin(GL_QUADS); 
		 glColor3f(1.0,0.0,0.0);
		 glVertex3f(5.0f,6.0f,0.0f); 
		 glVertex3f(5.0f,6.0f,-7.0f);
		 glVertex3f(5.0f,11.0f,-7.0f);
		 glVertex3f(5.0f,11.0f,-2.0f);
		 glEnd(); 
	 glPopMatrix();  
 
	glPushMatrix(); 
 		glTranslatef(-10,0,3); 
 		glBegin(GL_QUADS); 
 		glColor3f(1.0,0.0,0.0);
 		glVertex3f(5.0f,1.0f,0.0f); 
 		glVertex3f(5.0f,6.0f,0.0f); 
 		glVertex3f(5.0f,6.0f,-7.0f);
 		glVertex3f(5.0f,1.0f,-7.0f);
 		glEnd(); 
	glPopMatrix();
 
	 glPushMatrix(); 
		 glTranslatef(-10,0,3); 
		 glBegin(GL_QUADS); 
		 glColor3f(1.0,0.0,0.0);
		 glVertex3f(5.0f,6.0f,0.0f); 
		 glVertex3f(5.0f,6.0f,-7.0f);
		 glVertex3f(5.0f,11.0f,-7.0f);
		 glVertex3f(5.0f,11.0f,-2.0f);
		 glEnd(); 
	 glPopMatrix();
 
 	//sisi bawah
	 glPushMatrix(); 
		 glTranslatef(0,0,3); 
		 glBegin(GL_QUADS);
		 glVertex3f(5.0f,1.0f,0.0f); 
		 glVertex3f(5.0f,1.0f,-7.0f);
		 glVertex3f(-5.0f,1.0f,-7.0f);
		 glVertex3f(-5.0f,1.0f,0.0f);
		 glEnd(); 
	 glPopMatrix();
 
 	//sisi belakang 
	 glPushMatrix(); 
		 glTranslatef(0,0,3); 
		 glBegin(GL_QUADS); 
		 glVertex3f(5.0f,11.0f,-2.0f); 
		 glVertex3f(5.0f,11.0f,-7.0f);
		 glVertex3f(-5.0f,11.0f,-7.0f);
		 glVertex3f(-5.0f,11.0f,-2.0f);
		 glEnd(); 
	 glPopMatrix();
	 
 	//sisi atas
	 glPushMatrix(); 
		 glTranslatef(0,0,3); 
		 glBegin(GL_QUADS); 
		 glVertex3f(5.0f,1.0f,-7.0f); 
		 glVertex3f(5.0f,11.0f,-7.0f);
		 glVertex3f(-5.0f,11.0f,-7.0f);
		 glVertex3f(-5.0f,1.0f,-7.0f);
		 glEnd(); 
	 glPopMatrix();
	 
	 //roda
	 glPushMatrix();
		glTranslatef(0.3, 1.3, 1);
		glRotatef(90, 0.0, 1.0, 0.0);
		glScalef(1.7,1.7,1.7);
		wheel();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-9.7, 1.3, 1);
		glRotatef(90, 0.0, 1.0, 0.0);
		glScalef(1.7,1.7,1.7);
		wheel();
	glPopMatrix();
} 

void Container() {
	//sisi kanan kiri
	glPushMatrix(); 
	 	glTranslatef(0,0,3); 
	 	glBegin(GL_QUADS); 
	 	glColor3f(0.1,0.0,0.1);
	 	glVertex3f(5.0f,2.0f,-7.0f); 
		glVertex3f(5.0f,2.0f,-27.0f);
	 	glVertex3f(5.0f,13.0f,-27.0f);
	 	glVertex3f(5.0f,13.0f,-7.0f);
	 	glEnd(); 
 	glPopMatrix();
 	
 	glPushMatrix(); 
	 	glTranslatef(-10,0,3); 
	 	glBegin(GL_QUADS); 
	 	glColor3f(0.1,0.0,0.1);
	 	glVertex3f(5.0f,2.0f,-7.0f); 
		glVertex3f(5.0f,2.0f,-27.0f);
	 	glVertex3f(5.0f,13.0f,-27.0f);
	 	glVertex3f(5.0f,13.0f,-7.0f);
	 	glEnd(); 
 	glPopMatrix();
 	
 	//sisi depan belakang
 	glPushMatrix(); 
	 	glTranslatef(0,0,3); 
	 	glBegin(GL_QUADS); 
	 	glColor3f(0.1,0.1,0.1);
	 	glVertex3f(5.0f,2.0f,-7.0f); 
		glVertex3f(5.0f,13.0f,-7.0f);
	 	glVertex3f(-5.0f,13.0f,-7.0f);
	 	glVertex3f(-5.0f,2.0f,-7.0f);
	 	glEnd(); 
 	glPopMatrix();
 	
 	glPushMatrix(); 
	 	glTranslatef(0,0,-17); 
	 	glBegin(GL_QUADS); 
	 	glColor3f(0.1,0.1,0.1);
	 	glVertex3f(5.0f,2.0f,-7.0f); 
		glVertex3f(5.0f,13.0f,-7.0f);
	 	glVertex3f(-5.0f,13.0f,-7.0f);
	 	glVertex3f(-5.0f,2.0f,-7.0f);
	 	glEnd(); 
 	glPopMatrix();
 	
 	//sisi atas bawah
 	glPushMatrix(); 
	 	glTranslatef(0,0,3); 
	 	glBegin(GL_QUADS); 
	 	glColor3f(0.0,0.0,0.8);
	 	glVertex3f(5.0f,2.0f,-7.0f); 
	 	glVertex3f(-5.0f,2.0f,-7.0f);
	 	glVertex3f(-5.0f,2.0f,-27.0f);
	 	glVertex3f(5.0f,2.0f,-27.0f); 
	 	glEnd(); 
 	glPopMatrix();
 	
 	glPushMatrix(); 
	 	glTranslatef(0,10,3); 
	 	glBegin(GL_QUADS); 
	 	glColor3f(0.0,0.0,0.8);
	 	glVertex3f(5.0f,2.0f,-7.0f); 
	 	glVertex3f(-5.0f,2.0f,-7.0f);
	 	glVertex3f(-5.0f,2.0f,-27.0f);
	 	glVertex3f(5.0f,2.0f,-27.0f); 
	 	glEnd(); 
 	glPopMatrix();
 	
 	//bagian bawah container
 	//sisi depan belakang
	glPushMatrix(); 
	 	glTranslatef(0,0,3); 
	 	glBegin(GL_QUADS); 
	 	glColor3f(0.1,0.1,0.1);
	 	glVertex3f(5.0f,1.0f,-7.0f); 
		glVertex3f(5.0f,2.0f,-7.0f);
	 	glVertex3f(-5.0f,2.0f,-7.0f);
	 	glVertex3f(-5.0f,1.0f,-7.0f);
	 	glEnd(); 
 	glPopMatrix();
 	
 	glPushMatrix(); 
	 	glTranslatef(0,0,-17); 
	 	glBegin(GL_QUADS); 
	 	glColor3f(0.1,0.1,0.1);
	 	glVertex3f(5.0f,1.0f,-7.0f); 
		glVertex3f(5.0f,2.0f,-7.0f);
	 	glVertex3f(-5.0f,2.0f,-7.0f);
	 	glVertex3f(-5.0f,1.0f,-7.0f);
	 	glEnd(); 
 	glPopMatrix();
 	
 	//sisi kanan kiri
 	glPushMatrix(); 
	 	glTranslatef(0,0,3); 
	 	glBegin(GL_QUADS); 
	 	glColor3f(0.2,0.2,0.2);
	 	glVertex3f(5.0f,1.0f,-7.0f); 
		glVertex3f(5.0f,2.0f,-7.0f);
	 	glVertex3f(5.0f,2.0f,-27.0f);
	 	glVertex3f(5.0f,1.0f,-27.0f);
	 	glEnd(); 
 	glPopMatrix();
 	
 	glPushMatrix(); 
	 	glTranslatef(-10,0,3); 
	 	glBegin(GL_QUADS); 
	 	glColor3f(0.2,0.2,0.2);
	 	glVertex3f(5.0f,1.0f,-7.0f); 
		glVertex3f(5.0f,2.0f,-7.0f);
	 	glVertex3f(5.0f,2.0f,-27.0f);
	 	glVertex3f(5.0f,1.0f,-27.0f);
	 	glEnd(); 
 	glPopMatrix();
 	
 	//sisi atas bawah
 	glPushMatrix(); 
	 	glTranslatef(0,0,3); 
	 	glBegin(GL_QUADS); 
	 	glColor3f(0.2,0.2,0.2);
	 	glVertex3f(5.0f,1.0f,-7.0f); 
		glVertex3f(-5.0f,1.0f,-7.0f);
	 	glVertex3f(-5.0f,1.0f,-27.0f);
	 	glVertex3f(5.0f,1.0f,-27.0f);
	 	glEnd(); 
 	glPopMatrix();
 	
 	glPushMatrix(); 
	 	glTranslatef(0,1,3); 
	 	glBegin(GL_QUADS); 
	 	glColor3f(0.1,0.1,0.1);
	 	glVertex3f(5.0f,1.0f,-7.0f); 
		glVertex3f(-5.0f,1.0f,-7.0f);
	 	glVertex3f(-5.0f,1.0f,-27.0f);
	 	glVertex3f(5.0f,1.0f,-27.0f);
	 	glEnd(); 
 	glPopMatrix();
 	
 	//roda
 	glPushMatrix();
		glTranslatef(0.3, 1.3, -7);
		glRotatef(90, 0.0, 1.0, 0.0);
		glScalef(1.7,1.7,1.7);
		wheel();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-9.7, 1.3, -7);
		glRotatef(90, 0.0, 1.0, 0.0);
		glScalef(1.7,1.7,1.7);
		wheel();
	glPopMatrix();
	
	glPushMatrix();
		glTranslatef(0.3, 1.3, -18);
		glRotatef(90, 0.0, 1.0, 0.0);
		glScalef(1.7,1.7,1.7);
		wheel();
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-9.7, 1.3, -18);
		glRotatef(90, 0.0, 1.0, 0.0);
		glScalef(1.7,1.7,1.7);
		wheel();
	glPopMatrix();
}

void Hook() {
	//penyambung
 	glPushMatrix(); 
	 	glTranslatef(0,0,3); 
	 	glBegin(GL_QUADS); 
	 	glColor3f(0.1,0.1,0.1);
	 	glVertex3f(1.0f,1.0f,-27.0f); 
		glVertex3f(1.0f,2.0f,-27.0f);
	 	glVertex3f(1.0f,2.0f,-29.0f);
	 	glVertex3f(1.0f,1.0f,-29.0f);
	 	glEnd(); 
 	glPopMatrix();
 	
 	glPushMatrix(); 
	 	glTranslatef(-2,0,3); 
	 	glBegin(GL_QUADS); 
	 	glColor3f(0.1,0.1,0.1);
	 	glVertex3f(1.0f,1.0f,-27.0f); 
		glVertex3f(1.0f,2.0f,-27.0f);
	 	glVertex3f(1.0f,2.0f,-29.0f);
	 	glVertex3f(1.0f,1.0f,-29.0f);
	 	glEnd(); 
 	glPopMatrix();
 	
 	glPushMatrix(); 
	 	glTranslatef(0,0,3); 
	 	glBegin(GL_QUADS); 
	 	glColor3f(0.1,0.1,0.1);
	 	glVertex3f(1.0f,1.0f,-27.0f); 
		glVertex3f(-1.0f,1.0f,-27.0f);
	 	glVertex3f(-1.0f,1.0f,-29.0f);
	 	glVertex3f(1.0f,1.0f,-29.0f);
	 	glEnd(); 
 	glPopMatrix();
 	
	glPushMatrix(); 
	 	glTranslatef(0,1,3); 
	 	glBegin(GL_QUADS); 
	 	glColor3f(0.1,0.1,0.1);
	 	glVertex3f(1.0f,1.0f,-27.0f); 
		glVertex3f(-1.0f,1.0f,-27.0f);
	 	glVertex3f(-1.0f,1.0f,-29.0f);
	 	glVertex3f(1.0f,1.0f,-29.0f);
	 	glEnd(); 
 	glPopMatrix();
}



void display() { 
	usleep(1);
 	// Kalau move dan angle tidak nol, gerakkan kamera... 
	if (deltaMove) 
 	moveMeFlat(deltaMove); 
 	if (deltaAngle) { 
 		angle += deltaAngle; 
 		orientMe(angle); 
 	} 
 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 	glClearColor(1.0,1.0,1.0,1.0);
 	// Gambar grid 
 	Grid(); 
 	// Gambar objek di sini... 
 	
 	//kepala
	Head();
	//container pertama
	Container();
	//container kedua
	glPushMatrix();
		glTranslatef(0,0,-22);
		Container();
	glPopMatrix();
	//pengait
	Hook();
	
	
 	glutSwapBuffers(); 
 	glFlush(); 
} 

void pressKey(int key, int x, int y) { 
 	// Fungsi ini akan dijalankan saat tombol keyboard ditekan dan  belum dilepas 
 	// Selama tombol ditekan, variabel angle dan move diubah => kamera bergerak 
 	switch (key) { 
 		case GLUT_KEY_LEFT : deltaAngle = -0.01f;break; 
 		case GLUT_KEY_RIGHT : deltaAngle = 0.01f;break; 
 		case GLUT_KEY_UP : deltaMove = 1;break; 
 		case GLUT_KEY_DOWN : deltaMove = -1;break; 
 	} 
} 
void releaseKey(int key, int x, int y) { 
 // Fungsi ini akan dijalankan saat tekanan tombol keyboard dilepas 
 // Saat tombol dilepas, variabel angle dan move diset nol => kamera berhenti 
 	switch (key) { 
 		case GLUT_KEY_LEFT : 
 			if (deltaAngle < 0.0f) 
 			deltaAngle = 0.0f; 
 		break; 
 		case GLUT_KEY_RIGHT : 
		 	if (deltaAngle > 0.0f) 
 			deltaAngle = 0.0f; 
 		break; 
 		case GLUT_KEY_UP : 
		 	if (deltaMove > 0) 
 			deltaMove = 0; 
 		break; 
 		case GLUT_KEY_DOWN : 
		 	if (deltaMove < 0) 
 		deltaMove = 0; 
 		break; 
 	} 
}	 

// Variable untuk pencahayaan 
const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f }; 
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f }; 
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f }; 
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f }; 
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
const GLfloat high_shininess[] = { 100.0f }; 

void lighting(){ 
 // Fungsi mengaktifkan pencahayaan 
 	glEnable(GL_DEPTH_TEST); 
 	glDepthFunc(GL_LESS); 
 	glEnable(GL_LIGHT0); 
 	glEnable(GL_NORMALIZE); 
 	glEnable(GL_COLOR_MATERIAL); 
 	glEnable(GL_LIGHTING); 
 	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient); 
 	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); 
 	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular); 
 	glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
 	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient); 
 	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse); 
 	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); 
 	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess); 
} 
void init(void) 
{ 
 	glEnable (GL_DEPTH_TEST); 
 	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
} 
int main(int argc, char **argv) 
{ 
 	glutInit(&argc, argv); 
 	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); 
 	glutInitWindowPosition(100,100); 
 	glutInitWindowSize(640,480); 
 	glutCreateWindow("3D Lighting"); 
 	glutIgnoreKeyRepeat(1); // Mengabaikan key repeat (saat tombol  keyboard dipencet terus) 
 	glutSpecialFunc(pressKey);
 	glutSpecialUpFunc(releaseKey); 
 	glutDisplayFunc(display); 
 	glutIdleFunc(display); // Fungsi display-nya dipanggil terusmenerus 
 	glutReshapeFunc(Reshape); 
 	lighting(); 
 	init(); 
 	glutMainLoop(); 
 	return(0); 
}

