/* Nama File	: tugas2 (kubus).cpp */
/* Deskripsi	: Membuat gambar kubus bertingkat dari objek primitif. */
/* Nama			: Aprilyanto Setiyawan Siburian */
/* NIM  		: 24060121120022 */

#include <gl/glut.h>

void kubusbertingkat(void)

{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 1.0f);
	glRectf(-0.15, -0.1, 0.15, 0.5);
	glColor3f(1.0f, 0.0f, 0.0f);
	glRectf(-0.1, 0.5, 0.1, 0.8);
	glColor3f(0.0f, 0.0f, 0.0f);
	glRectf(0.15, 0.11, 0.5, 0.3);
	glRectf(-0.5, 0.11, -0.15, 0.3);
	glRectf(-0.05, -0.1, -0.15, -0.3);
	glRectf(-0.05, -0.3, -0.15, -0.5);
	glRectf(-0.05, -0.5, -0.15, -0.7);
	glRectf(0.05, -0.1, 0.15, -0.3);
	glRectf(0.05, -0.3, 0.15, -0.5);
	glRectf(0.05, -0.5, 0.15, -0.7);
	glFlush();
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitWindowSize(1080, 720);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Kubus Bertingkat");
	glutDisplayFunc(kubusbertingkat);
	glClearColor(0.1f, 0.1f, 0.1f, 0.1f);
	glutMainLoop();
	return 0;
}
