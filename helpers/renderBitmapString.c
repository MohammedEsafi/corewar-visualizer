#include <GLUT/glutbitmap.h>

void	renderBitmapString(float x, float y, char *str) {
	int		i;

	glRasterPos2f(x, y);
	i = -1;
	while (str[++i])
		glutBitmapCharacter(GLUT_STROKE_ROMAN, str[i]);
}