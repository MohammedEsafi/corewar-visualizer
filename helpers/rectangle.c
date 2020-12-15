void	rectangle(int x1, int y1, int x2, int y2)
{
	glBegin(GL_QUADS);
		glColor3f(0, 1, 0);
		glVertex2f(x1, y1);
		glVertex2f(x2, y1);
		glVertex2f(x2, y2);
		glVertex2f(x1, y2);
	glEnd();
}