/* Nama file	: tugas1.cpp */
/* Deskripsi	: Membuat program yang memanfaatkan fungsi GL_LINE_STRIP, GL_LINE_LOOP, */
/*                GL_TRIANGLE_FAN, GL_TRIANGLE_STRIP, GL_QUADS, dan GL_QUAD_STRIP */
/* Nama 		: Aprilyanto Setiyawan Siburian */
/* NIM  		: 24060121120022 */

#include <GL/glut.h>
#include <stdlib.h>

//GL_LINE_STRIP (membuat sebuah garis dari lebih dari 2 koordinat)
void LINE_STRIP(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-0.5,-0.5,0.0);
	glVertex3f(0.5,-0.5,0.0);
	glVertex3f(0.5,0.5,0.0);
	glEnd();
	glFlush();
}

//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);
//    glutInitWindowSize(640,480);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//    glutCreateWindow("GL_LINE_STRIP");
//    glutDisplayFunc(LINE_STRIP);
//    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//    glutMainLoop();
//    
//    return 0;
//}

//GL_LINE_LOOP (membuat sebuah garis dengan koordinat terakhir otomatis tersambung dengan 
//koordinat awal)
void LINE_LOOP(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.5,-0.5,0.0);
	glVertex3f(0.5,-0.5,0.0);
	glVertex3f(0.5,0.5,0.0);
	glEnd();
	glFlush();
}

//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);
//    glutInitWindowSize(640,480);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//    glutCreateWindow("GL_LINE_LOOP");
//    glutDisplayFunc(LINE_LOOP);
//    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//    glutMainLoop();
//    
//    return 0;
//}

//GL_TRIANGLE_FAN (membuat serangkaian segitiga dari lebih dari 2 koordinat dengan koordinat pertama 
//sebagai titik tumpuan
void TRIANGLE_FAN() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3d(1,0,0);
	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0,0.0);
    glVertex2f(2.0,3.0);
	glVertex2f(3.0,2.0);
    glVertex2f(3.50,.50);
    glVertex2f(3.0,-1.0);
    glVertex2f(2.0,-2.0);
	glEnd();
	glFlush();
}

//void Initialize() {
// glClearColor(0, 255, 243, 0.5);
// glMatrixMode(GL_PROJECTION);
// glLoadIdentity();
// glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
//}

//int main(int argc, char *argv[]) 
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(640, 480);
//	glutInitWindowPosition(250, 250);
//	glutCreateWindow("GL_TRIANGLE_FAN");
//	Initialize();
//	glutDisplayFunc(TRIANGLE_FAN);
//	glutMainLoop();
//	
//	return EXIT_SUCCESS;
//}

//GL_TRIANGLE_STRIP (membuat serangkaian segitiga terhubung sehingga tidak perlu berulang kali
//menentukan semua 3 titik simpul (vertex)
void TRIANGLE_STRIP (void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//Gambar segitiga sama sisi berwarna biru
	glColor3f(0,0,1);
	glBegin(GL_TRIANGLE_STRIP);
	glVertex2f(-0.25, -0.25);
	glVertex2f(0.0, 0.25);
	glVertex2f(0.25, -0.25);
	glVertex2f(0.5, 0.25);
	glVertex2f(0.75, -0.25);
	glVertex2f(1.0, 0.25);
	glEnd();
	glFlush();
	glutSwapBuffers();
}

//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);
//    glutInitWindowSize(640,480);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//    glutCreateWindow("GL_TRIANGLE_STRIP");
//    glutDisplayFunc(TRIANGLE_STRIP);
//    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//    glutMainLoop();
//    
//    return 0;
//}

//GL_QUADS (membuat sebuah objek dari 4 koordinat)
void QUADS()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f( 0, 0, 1 );
    glBegin(GL_QUADS);//start drawing a line loop
      glVertex2f(-0.5,0.5);//left of window
      glVertex2f(0.5,0.5);//bottom of window
      glVertex2f(0.5,-0.5);//right of window
      glVertex2f(-0.5,-0.5);//top of window
    glEnd();//end drawing of line loop
    glutSwapBuffers();
}

//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);
//    glutInitWindowSize(640,480);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//    glutCreateWindow("GL_QUADS");
//    glutDisplayFunc(QUADS);
//    glutMainLoop();
//    
//    return 0;
//}

//GL_QUAD_STRIP (membuat sebuah objek dari 4 koordinat yang saling terhubung)
void QUAD_STRIP() 
{
	glClear(GL_COLOR_BUFFER_BIT);
 	glColor3d(255,0,0);
 	glBegin(GL_QUAD_STRIP);
    	glVertex2f(-4.0,-2.0);
    	glVertex2f(-4.0,2.0);
    	glVertex2f(-2.0,-2.0);
    	glVertex2f(-2.0,2.0);
    	glVertex2f(6.0,-6.0);
    	glVertex2f(6.0,6.0);
 	glEnd();
 	glFlush();
}

void Initialize() 
{
	glClearColor(0, 0, 0, 0.5);
 	glMatrixMode(GL_PROJECTION);
 	glLoadIdentity();
 	glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}

//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
// 	glutInitWindowSize(640, 480);
// 	glutInitWindowPosition(250, 250);
// 	glutCreateWindow("GL_QUAD_STRIP");
// 	Initialize();
// 	glutDisplayFunc(QUAD_STRIP);
// 	glutMainLoop();
// 	return EXIT_SUCCESS;
//}
