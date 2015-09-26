#include <iostream>

#include <GL/glut.h>
#include <list>
using namespace std;

struct Ponto {
	int x;
	int y;
};
//list<Ponto> pList;
Ponto *pList;
int tam;
void desenha(int ix, int iy)//, int value)
{
	glBegin(GL_POINTS);
	glVertex2i(ix, iy);
	glEnd();
}

void bresenham(int x1, int y1, int x2, int y2)
{
	int dx, dy, i, e;
	int incx, incy, inc1, inc2;
	int x, y;

	dx = x2 - x1;
	dy = y2 - y1;

	if (dx < 0)
	{
		dx = -dx;
	}
	if (dy < 0)
	{
		dy = -dy;
	}
	incx = 1;
	if (x2 < x1) 
	{ 
		incx = -1; 
	}
	incy = 1;
	if (y2 < y1) 
	{ 
		incy = -1; 
	}
	x = x1;
	y = y1;

	if (dx > dy)
	{
		desenha(x, y);// , 0);
		e = 2 * dy - dx;
		inc1 = 2 * (dy - dx);
		inc2 = 2 * dy;
		for (i = 0; i < dx; i++)
		{
			if (e >= 0)
			{
				y += incy;
				e += inc1;
			}
			else
			{
				e += inc2;
			}
			x += incx;
			desenha(x, y);// , 0);
		}
	}
	else
	{
		desenha(x, y);// , 0);
		e = 2 * dx - dy;
		inc1 = 2 * (dx - dy);
		inc2 = 2 * dx;
		for (i = 0; i < dy; i++)
		{
			if (e >= 0)
			{
				x += incx;
				e += inc1;
			}
			else 
			{ 
				e += inc2; 
			}
			y += incy;
			desenha(x, y);// , 0);
		}
	}
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	/*Ponto p;
	for (std::list<Ponto>::iterator it = pList.begin(); it != pList.end(); ++it) {
		p = *it;
		if ((++it) != pList.end()) {
			bresenham(p.x, p.y, it->x, it->y);
		}
		--it;
	}*/
	for (int i = 0; i < tam-1; i++)
	{
		bresenham(pList[i].x, pList[i].y, pList[i+1].x, pList[i+1].y);
	}
	bresenham(pList[tam-1].x, pList[tam-1].y, pList[0].x, pList[0].y);
	//glFlush();
	glutSwapBuffers();
}


void inicializar()
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 600, 0.0, 600);
}

void draw_circle(int x, int y, int a, int b)
{
	int wx, wy;
	int thresh;
	int asq = a * a;
	int bsq = b * b;
	int xa, ya;
	bresenham(x, y + b,x,y-b);
	wx = 0;
	wy = b;
	xa = 0;
	ya = asq * 2 * b;
	thresh = asq / 4 - asq * b;
	while(true){
		thresh += xa + bsq;
		if (thresh >= 0) {
			ya -= asq * 2;
			thresh -= ya;
			wy--;
		}
		xa += bsq * 2;
		wx++;
		if (xa >= ya)
			break;
		bresenham(x + wx, y - wy, x - wx, y - wy);
		bresenham(x + wx, y + wy, x - wx, y + wy);
	}
	bresenham(x + a, y, x - a, y);
	wx = a;
	wy = 0;
	xa = bsq * 2 * a;
	ya = 0;
	thresh = bsq / 4 - bsq * a;
	while(true){
		thresh += ya + asq;
		if (thresh >= 0) {
			xa -= bsq * 2;
			thresh = thresh - xa;
			wx--;
		}
		ya += asq * 2;
		wy++;
		if (ya > xa)
			break;
		bresenham(x + wx, y - wy, x - wx, y - wy);
		bresenham(x + wx, y + wy, x - wx, y + wy);
	}
}
void display2()
{
	int startX = 300, startY = 300;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1, 0);
	draw_circle(startX, startY, 200, 200);
	glColor3f(0.0,0,1);
	draw_circle(startX, startY, 190, 190);
	glColor3f(1.0, 1, 1);
	draw_circle(startX, startY, 110, 110);
	glColor3f(1.0, 0, 0);	
	draw_circle(startX, startY, 80, 80);
	//glFlush();
	glutSwapBuffers();
}

void main(int argc, char** argv)
{
	
	/*int x , y;
	x = y = 0;
	while (x != -1 && y != -1) {
		Ponto p;
		cout << "Insira os pontos (-1 -1, para sair): " << endl;
		cin >> x >> y;
		if (x != -1 && y != -1) {
			p.x = x;
			p.y = y;
			pList.push_back(p);
		}
	}*/

	cout << "quantidade de pontos: ";
	cin >> tam;
	pList = new Ponto[tam];
	for (int  i = 0; i < tam; i++)
	{
		cin >> pList[i].x >> pList[i].y;
	}

	/* standard GLUT initialization */

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); /* default, not needed */
	glutInitWindowSize(500, 500); /* 500x500 pixel window */
	glutInitWindowPosition(10, 10); /* place window top left on display */
	glutCreateWindow("Bresenham"); /* window title */
	glutDisplayFunc(display2); /* display callback invoked when window opened */

	inicializar(); /* set attributes */

	glutMainLoop(); /* enter event loop */
}
