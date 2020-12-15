/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mesafi <mesafi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 10:25:27 by mesafi            #+#    #+#             */
/*   Updated: 2020/12/07 10:25:29 by mesafi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GLUT/glut.h>
#include <GLUT/glutbitmap.h>

void	initGL(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	// glColor3f(0.0, 1.0, 0.0);
	// glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	gluOrtho2D(-683, 683, -384, 384);
}

void	renderBitmapString(float x, float y, char *str) {
	int		i;

	glColor3f(0, 1, 0);
	glRasterPos2f(x, y);
	i = -1;
	while (++i < 5)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, i + 65);
	// printf(">> %s", str);
}



void	drawing(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	rectangle(0, 0, 10, 10);
	// renderBitmapString(0, 0, strdup("Hello"));
	glColor3f(0, 0, 1);
	glRasterPos2f(0, 0);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, 97);
	glFlush();
}

void	keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 27:
			exit(0);
			break;

		default:
			break;
	}
}

int		main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1366, 768);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("CoreWar");
	initGL();
	glutDisplayFunc(drawing);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return (0);
}
