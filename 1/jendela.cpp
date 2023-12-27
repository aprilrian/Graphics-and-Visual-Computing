/* Nama file	: jendela.cpp */
/* Deskripsi	: Memunculkan 1 layar warna biru kosong */
/* Nama 		: Aprilyanto Setiyawan Siburian */
/* NIM  		: 24060121120022 */
	
#include <GL/glut.h>
#include <stdlib.h>

void Jendela(void)
{
	//membersihkan layar dan men-set dalam format warna
	glClear(GL_COLOR_BUFFER_BIT);
	//memastikan seluruh perintah eksekusi
	glFlush();
}

//int main(int argc, char *argv[])
//{
//    //Inisialisasi program glut
//	glutInit(&argc, argv);
//	//Mengatur ukuran jendela
//    glutInitWindowSize(640,480);
//    //Inisialisasi mode display
//    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
//    //Membuat jendela baru dengan judul sesuai parameter
//    glutCreateWindow("Biru");
//    glutDisplayFunc(Jendela);
//    //Warna background
//    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
//    glutMainLoop();
//    
//    return 0;
//}

