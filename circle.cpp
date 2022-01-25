#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include "gTime.cpp"

int windowWidth = 500;
int windowHeight = 500;

int start = getCurrentTime();
float theta = 0;

float x = 0;
float y = 0.1;

struct Line
{
	float start;
	float end;
};

std::vector<Line> lines;

void clear()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void drawCircle(float sx, float sy, float r)
{
	int now = getCurrentTime();
	float step = 0.01;
	if (now - start >= 5 && theta < 6.3 + step)
	{
		float x = sx + r * cos(theta);
		float y = sy + r * sin(theta);
		std::cout << theta << std::endl;
		std::cout << x << std::endl;
		std::cout << y << std::endl;
		std::cout << std::endl;
		Line line;
		line.start = x;
		line.end = y;
		lines.push_back(line);
		theta += step;
		start = getCurrentTime();
	}

	glPushMatrix();
	glMatrixMode(GL_MODELVIEW);

	glLineWidth(2.0);
	glBegin(GL_LINE_STRIP);

	for (int i = 0; i < lines.size(); i++)
	{
		glVertex2f(lines[i].start, lines[i].end);
	}

	glEnd();
	glPopMatrix();
	glutPostRedisplay();
}

void display()
{
	clear();

	drawCircle(0.0, 0.0, 0.4);
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(windowWidth, windowHeight);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Clock");
	glutDisplayFunc(display);
	glutMainLoop();
}