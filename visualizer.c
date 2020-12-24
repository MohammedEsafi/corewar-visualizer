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

#include <visualizer.h>

// To-do: declaration global pointer on queue data from corwar 

void		initGL(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	gluOrtho2D(-SIDE, SIDE, -SIDE, SIDE);
}

void		drawing(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	draw_map();
	glFlush();
}

void		keyboard(unsigned char key, int x, int y)
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

void		*visualizer(void *queue)
{
	int		argc;
	char	*argv;

	argc = 0;
	// To-do: init global variable
	glutInit(&argc, &argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("CoreWar");
	initGL();
	glutDisplayFunc(drawing);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return (NULL);
}