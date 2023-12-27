/* Nama file	: segiempat.cpp */
/* Deskripsi	: Membuat segiempat */
/* Nama 		: Aprilyanto Setiyawan Siburian */
/* NIM  		: 24060121120022 */

#include <GL/glut.h>
#include <stdlib.h>

void Segiempat(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(-0.18, 0.18, 0.18, -0.18);
	glFlush();
}

//int main(int argc, char *argv[])
//{
//	glutInit(&argc, argv);
//    glutInitWindowSize(640,480);
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//    glutCreateWindow("Segiempat");
//    glutDisplayFunc(Segiempat);
//    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
//    glutMainLoop();
//    
//    return 0;
//}
