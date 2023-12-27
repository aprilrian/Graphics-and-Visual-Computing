/* Nama file	: segitiga.cpp */
/* Deskripsi	: Membuat segitiga */
/* Nama 		: Aprilyanto Setiyawan Siburian */
/* NIM  		: 24060121120022 */

#include <GL/glut.h>
#include <stdlib.h>

void Segitiga(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-0.10, -0.10, 0.00);
	glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.10, -0.10, 0.00);
	glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(0.00, 0.10, 0.00);
	glEnd();
	glFlush();
}

//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);
//    glutInitWindowSize(640,480);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//    glutCreateWindow("Segitiga");
//    glutDisplayFunc(Segitiga);
//    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//    glutMainLoop();
//    
//    return 0;
//}
