#include <stdio.h>
#include <GL/glut.h>
#include <GL/freeglut.h>

void initGL(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	// glColor3f(0.0, 1.0, 0.0);
	// glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	// gluOrtho2D(-780, 780, -420, 420);
}

void rectangle(int x1, int y1, int x2, int y2)
{
	glBegin(GL_QUADS);
	glColor3f(0, 1, 0);
	glVertex2f(x1, y1);
	glVertex2f(x2, y1);
	glVertex2f(x2, y2);
	glVertex2f(x1, y2);

	glColor3f(0, 1, 0);
	glVertex2f(x1, y1);
	glVertex2f(-1 * x2, y1);
	glVertex2f(x2 * -1, y2 * -1);
	glVertex2f(x1, y2 * -1);
	// glRasterPos2f(0, 0);
	// glutBitmapString(GLUT_BITMAP_8_BY_13, "sasdsadasdasdass");
	glEnd();
}

void drawing(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	rectangle(0, 0, 4, 4);
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("CoreWar");
	initGL();
	glutDisplayFunc(drawing);
	glutMainLoop();
	return (0);
}