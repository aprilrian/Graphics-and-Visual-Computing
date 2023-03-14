/* Nama file	: garis.cpp */
/* Deskripsi	: Membuat garis */
/* Nama 		: Aprilyanto Setiyawan Siburian */
/* NIM  		: 24060121120022 */

#include <GL/glut.h>
#include <stdlib.h>

void Garis(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLineWidth(10.0f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(0.00, 0.20, 0.0);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.00, -0.20, 0.0);
	glEnd();
	glFlush();
}

//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);
//    glutInitWindowSize(640,480);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//    glutCreateWindow("Garis");
//    glutDisplayFunc(Garis);
//    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
//    glutMainLoop();
//    
//    return 0;
//}
