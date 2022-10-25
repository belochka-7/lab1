#include "Render.h"

#include <Windows.h>
#include <GL\GL.h>
#include <GL\GLU.h>

void Render(double delta_time)
{
	const double P1[8][3] = { { 0,  0, 0},
							  { 0,  7, 0},
							  { 6,  8, 0},
							  { 3,  1, 0},
							  { 7, -3, 0},
							  { 1, -1, 0},
							  {-3, -8, 0},
							  {-4, -1, 0} };
	const double h = 5;
	double P2[8][3]{};

	for (int i = 0; i < 8; ++i) {
		P2[i][0] = P1[i][0];
		P2[i][1] = P1[i][1];
		P2[i][2] = P1[i][2] + h;
	}

	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_TRIANGLES);

	glVertex3dv(P1[0]);
	glVertex3dv(P1[1]);
	glVertex3dv(P2[0]);

	glVertex3dv(P2[0]);
	glVertex3dv(P2[1]);
	glVertex3dv(P1[1]);

	for (int i = 1; i < 8; ++i)
	{
		int prv = i - 1, nxt = (i + 1) % 8;
		glVertex3dv(P1[0]);
		glVertex3dv(P1[i]);
		glVertex3dv(P1[nxt]);

		glVertex3dv(P2[0]);
		glVertex3dv(P2[i]);
		glVertex3dv(P2[nxt]);

		glVertex3dv(P1[i]);
		glVertex3dv(P1[nxt]);
		glVertex3dv(P2[i]);

		glVertex3dv(P2[i]);
		glVertex3dv(P2[nxt]);
		glVertex3dv(P1[nxt]);
	}

	glEnd();
}