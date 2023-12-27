/* Nama File	: lengan_bergerak.cpp */
/* Deskripsi	: Membuat animasi pada objek representasi lengan dengan modifikasi telapak tangan
				  dan jari-jari. */
/* Nama			: Aprilyanto Setiyawan Siburian */
/* NIM  		: 24060121120022 */

#include <GL/glut.h>   
static int shoulder = 0, elbow = 0, palm = 0, 
thumbf = 0, indexf = 0, middlef = 0, ringf = 0, littlef = 0;   

void init(void) 
{
	glClearColor (0.0, 0.0, 0.0, 0.0);       
	glShadeModel (GL_FLAT);   
}   
   
void display(void) 
{   
	glClear (GL_COLOR_BUFFER_BIT);       
	glPushMatrix(); 
		// Shoulder = Bahu
		glTranslatef (-2.0, 0.0, 0.0);   
		glRotatef ((GLfloat) shoulder, 0.0, 0.0, 1.0);           
		glTranslatef (1.0, 0.0, 0.0);            
		glPushMatrix();   
			glScalef (2.0, 0.4, 1.0);               
			glutWireCube (1.0);            
		glPopMatrix();
		
		// Elbow = Siku
		glTranslatef (1.0, 0.0, 0.0);   
		glRotatef ((GLfloat) elbow, 0.0, 0.0, 1.0);           
		glTranslatef (1.0, 0.0, 0.0);            
		glPushMatrix();   
			glScalef (2.0, 0.4, 1.0);               
			glutWireCube (1.0);           
		glPopMatrix();     
		
		// Palm = Telapak Tangan
		glTranslatef (1.0, 0.0, 0.0);
		glRotatef((GLfloat) palm, 0.0, 0.0, 1.0);
		glTranslatef (0.5, 0.0, 0.0);
		glPushMatrix();
			glScalef (1.0, 0.4, 2.0);
			glutWireCube (1.0);
		glPopMatrix();
		
		// Thumbf = Ibu Jari
		glPushMatrix();
			glTranslatef (0.0, 0.0, 1.1);
			glRotatef((GLfloat) thumbf, -1.0, 0.0, 0.0);
			glTranslatef (0.0, 0.0, 0.3);
			glPushMatrix();
				glScalef (0.5, 0.4, 0.8);
				glutWireCube (1.0);
			glPopMatrix();
		glPopMatrix();
		
		// Indexf = Jari Telunjuk
		glPushMatrix();
			glTranslatef (0.75, 0.0, -0.2);
			glRotatef((GLfloat) indexf, 0.0, 0.0, 1.0);
			glTranslatef (0.5, 0.0, -0.6);
			glPushMatrix();
				glScalef (1.5, 0.4, 0.3);
				glutWireCube (1.0);
			glPopMatrix();
		glPopMatrix();
		
		// Middlef = Jari Tengah
		glPushMatrix();
			glTranslatef (0.5, 0.0, -0.2);
			glRotatef((GLfloat) middlef, 0.0, 0.0, 1.0);
			glTranslatef (1.0, 0.0, -0.2);
			glPushMatrix();
				glScalef (2.0, 0.4, 0.3);
				glutWireCube (1.0);
			glPopMatrix();
		glPopMatrix();
		
		// Ringf = Jari Manis
		glPushMatrix();
			glTranslatef (0.75, 0.0, 0.2);
			glRotatef((GLfloat) ringf, 0.0, 0.0, 1.0);
			glTranslatef (0.5, 0.0, 0.2);
			glPushMatrix();
				glScalef (1.5, 0.4, 0.3);
				glutWireCube (1.0);
			glPopMatrix();	
		glPopMatrix();
		
		// Littlef = Jari Kelingking
		glPushMatrix();
			glTranslatef (0.5, 0.0, 0.5);
			glRotatef((GLfloat) littlef, 0.0, 0.0, 1.0);
			glTranslatef (0.5, 0.0, 0.5);
			glPushMatrix();
				glScalef (1.0, 0.4, 0.3);
				glutWireCube (1.0);
			glPopMatrix();
		 glPopMatrix();
		 
	glPopMatrix();       
	glutSwapBuffers();   
}   
   
void reshape (int w, int h) 
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);       
	glMatrixMode (GL_PROJECTION);        
	glLoadIdentity();   
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);       
	glMatrixMode(GL_MODELVIEW);        
	glLoadIdentity();   
    glTranslatef (0.0, 0.0, -5.0);   
}  
   
void keyboard(unsigned char key, int x, int y) 
{
	switch (key) 
	{
		case 's': shoulder = (shoulder + 5) % 360;                   
			glutPostRedisplay();                    
			break;   
        case 'S': shoulder = (shoulder - 5) % 360;                   
			glutPostRedisplay();                    
			break;   
        case 'e': elbow = (elbow + 5) % 360;                   
			glutPostRedisplay();                    
			break;   
        case 'E': elbow = (elbow - 5) % 360;                   
			glutPostRedisplay();                    
			break;              
		case 'p': palm = (palm + 5) % 360;                   
			glutPostRedisplay();                    
			break;   
        case 'P': palm = (palm - 5) % 360;                   
			glutPostRedisplay();                    
			break;            
		case 't': thumbf = (thumbf + 5) % 360;                   
			glutPostRedisplay();                    
			break;   
        case 'T': thumbf = (thumbf - 5) % 360;                   
			glutPostRedisplay();                    
			break;      
		case 'i': indexf = (indexf + 5) % 360;                   
			glutPostRedisplay();                    
			break;   
        case 'I': indexf = (indexf - 5) % 360;                   
			glutPostRedisplay();                    
			break;  
		case 'm': middlef = (middlef + 5) % 360;                   
			glutPostRedisplay();                    
			break;   
        case 'M': middlef = (middlef - 5) % 360;                   
			glutPostRedisplay();                    
			break;  
		case 'r': ringf = (ringf + 5) % 360;                   
			glutPostRedisplay();                    
			break;   
        case 'R': ringf = (ringf - 5) % 360;                   
			glutPostRedisplay();                    
			break;  
		case 'l': littlef = (littlef + 5) % 360;                   
			glutPostRedisplay();                    
			break;   
        case 'L': littlef = (littlef - 5) % 360;                   
			glutPostRedisplay();                    
			break;  
		case 27: exit(0);                    
			break;              
		default: 
			break;   
    }   
}   
   
int main(int argc, char** argv) 
{
	glutInit(&argc, argv);   
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);       
	glutInitWindowSize (700, 600);       
	glutInitWindowPosition (100, 100);       
	glutCreateWindow (argv[0]);        
	init();   
    glutDisplayFunc(display);       
	glutReshapeFunc(reshape);       
	glutKeyboardFunc(keyboard);       
	glutMainLoop();        
	
	return 0;  
}
