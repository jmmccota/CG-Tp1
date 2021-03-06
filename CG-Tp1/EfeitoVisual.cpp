#include "EfeitoVisual.hpp"
#include <cmath>
#define FULLHD_ORTHO_X 1920
#define FULLHD_ORTHO_Y 1080


EfeitoVisual::EfeitoVisual()
{
    fullscreen = false;
    sizeX = 1280;
    sizeY = 720;
}
//teste
EfeitoVisual::~EfeitoVisual()
{
}

void EfeitoVisual::ortho2D()
{
    gluOrtho2D(0.0f, FULLHD_ORTHO_X, 0.0f, FULLHD_ORTHO_Y);
}

pair<GLfloat, GLfloat> EfeitoVisual::getOrtho2D()
{
    return pair<GLfloat, GLfloat>(FULLHD_ORTHO_X, FULLHD_ORTHO_Y);
}

bool EfeitoVisual::colisao(Solido *a, Solido *b)
{
    if ((abs(a->getX() - b->getX()) <= (a->getTamX() + b->getTamX())) &&
        (abs(a->getY() - b->getY()) <= (a->getTamY() + b->getTamY())))
        return true;
    return false;
}

void EfeitoVisual::resize(GLsizei w, GLsizei h)
{
    // Especifica as dimens�es da Viewport
    if (w * 9 / 16 < h)
        glViewport(0, 0, w, w * 9 / 16);
    else
        glViewport(0, 0, h * 16 / 9, h);

    // Inicializa o sistema de coordenadas
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    EfeitoVisual::getInstance().sizeX = w;
    EfeitoVisual::getInstance().sizeY = h;
}

bool EfeitoVisual::isFullScreen()
{
    return fullscreen;
}

pair<GLint, GLint> EfeitoVisual::sizeScreen()
{
    return pair<GLint, GLint>(sizeX, sizeY);
}

pair<double, double> EfeitoVisual::positionScreen(char * type)
{
    pair<double, double> val;
    if (type == "center") {
        val.first = ((GetSystemMetrics(SM_CXSCREEN) - sizeScreen().first) / 2);
        val.second = ((GetSystemMetrics(SM_CYSCREEN) - sizeScreen().second) / 2);
    }
    return val;
}

void EfeitoVisual::setFullScreen()
{
    if (!fullscreen) {
        glutFullScreen();
    }
    else {
        //Default values
        sizeX = 1280;
        sizeY = 720;
        glutReshapeWindow(sizeX, sizeY);
        pair<int, int> position = positionScreen("center");
        glutInitWindowPosition(position.first, position.second);
    }
    fullscreen = !fullscreen;
}

void EfeitoVisual::desenhaExplosao(Explosao e)
{
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	GLfloat transladaX = 0;
	GLfloat transladaY = 0;
	//ajustando as coordenadas de 1920,1080 para -100, 100
	if (e.x < 960) {
		transladaX = 960 - e.x;
		transladaX = -(100 * transladaX) / 960;
	}
	else {
		transladaX = e.x - 960;
		transladaX = (100 * transladaX) / 960;
	}
	if (e.y < 540) {
		transladaY = 540 - e.y;
		transladaY = -(100 * transladaY) / 540;
	}
	else {
		transladaY = e.y - 540;
		transladaY = (100 * transladaY) / 540;
	}
	glTranslatef(transladaX, transladaY, 0);
	GLfloat value;
	if (e.value < 10)
		value = e.value;
	else
		value = 20 - e.value;
	GLfloat escala = e.escala * value;

    glScalef(escala, escala, 0);
    /*glScalef(escalaFinal, escalaFinal, escalaFinal);*/
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2f(-2, 2);
    glVertex2f(2, 2);
    glVertex2f(2, -2);
    glVertex2f(-2, -2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2f(3, 0);
    glVertex2f(0, 3);
    glVertex2f(-3, 0);
    glVertex2f(0, -3);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 0);
    glVertex2f(-1, 1);
    glVertex2f(1, 1);
    glVertex2f(1, -1);
    glVertex2f(-1, -1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1, 1, 0);
    glVertex2f(1.5, 0);
    glVertex2f(0, 1.5);
    glVertex2f(-1.5, 0);
    glVertex2f(0, -1.5);
    glEnd();
    glPopMatrix();
	glFlush();
}

// retangulo
void EfeitoVisual::desenhaRetangulo(float translacaoX, float translY, float escalaX, float escalaY, float rot, float red, float green, float blue) {
    glPushMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-960, 960, -540, 540);
    glScalef(escalaX, escalaY, 0);
    glTranslatef(translacaoX, translY, 0);
    glRotatef(rot, 1, 0, 0);
    glColor3f(red, green, blue);
    // poligono 1
    glBegin(GL_POLYGON);
    glVertex2i(-50, -50);
    glVertex2i(-50, 50);
    glVertex2i(50, 50);
    glVertex2i(50, -50);
    glVertex2i(-50, -50);
    glEnd();
    glPopMatrix();
    glFlush();
}

// quarteirao
void EfeitoVisual::desenhaQuarteirao(float translacaoX, float translY, float escalaX, float escalaY, float red, float green, float blue, int altura, int largura, int tX, int tY) {
    glPushMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-960, 960, -540, 540);
    glScalef(escalaX, escalaY, 0);
    glTranslatef(translacaoX + tX, translY + tY, 0);
    glColor3f(red, green, blue);
    glBegin(GL_LINES);
    glVertex2i(-100, altura);
    glVertex2i(-100, 56);
    glVertex2i(-100, 56);
    glVertex2i(-largura, 56);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(-largura, -56);
    glVertex2i(-100, -56);
    glVertex2i(-100, -56);
    glVertex2i(-100, -altura);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(100, -altura);
    glVertex2i(100, -56);
    glVertex2i(100, -56);
    glVertex2i(largura, -56);
    glEnd();
    glBegin(GL_LINES);
    glVertex2i(100, altura);
    glVertex2i(100, 56);
    glVertex2i(100, 56);
    glVertex2i(largura, 56);
    glEnd();
    glPopMatrix();
    glFlush();
}

void EfeitoVisual::desenhaLinhaAsfalto(float translacaoX, float translY, float escalaX, float escalaY, float red, float green, float blue, int altura, int largura, int tX, int tY) {
    glPushMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-960, 960, -540, 540);
    glScalef(escalaX, escalaY, 0);
    glTranslatef(translacaoX + tX, translY + tY, 0);
    glColor3f(red, green, blue);
    glBegin(GL_LINES);
    glVertex2f(-5, altura);
    glVertex2f(-5, 2.8);
    glVertex2f(-5, 2.8);
    glVertex2f(-largura, 2.8);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(-largura, -2.8);
    glVertex2f(-5, -2.8);
    glVertex2f(-5, -2.8);
    glVertex2f(-5, -altura);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(5, -altura);
    glVertex2f(5, -2.8);
    glVertex2f(5, -2.8);
    glVertex2f(largura, -2.8);
    glEnd();
    glBegin(GL_LINES);
    glVertex2f(5, altura);
    glVertex2f(5, 2.8);
    glVertex2f(5, 2.8);
    glVertex2f(largura, 2.8);
    glEnd();
    glPopMatrix();
    glFlush();
}
void EfeitoVisual::desenhaQuadrado(int x, int y, int x1, int y1) {	
	glColor3f(1,0.27,0);
	glBegin(GL_QUADS);
	glVertex2i(x, y);
	glVertex2i(x1, y);
	glVertex2i(x1, y1);
	glVertex2i(x, y1);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2i(x+1, y+1);
	glVertex2i(x1+1, y+1);
	glVertex2i(x1+1, y1+1);
	glVertex2i(x+1, y1+1);
	glEnd();
}

void EfeitoVisual::desenhaScore(string nome) {
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2i(650, 700);
	glVertex2i(1240, 700);
	glVertex2i(1240, 450);
	glVertex2i(650, 450);
	glEnd();
	int score = 1990;
	string recorde = "NOVO RECORDE! SCORE: ";
	recorde += score;
	glRasterPos2f(660, 650);
	FuncoesAuxiliares::writeWord_BITMAP(recorde, GLUT_BITMAP_TIMES_ROMAN_24);
	glRasterPos2f(660, 565);
	FuncoesAuxiliares::writeWord_BITMAP("Nome: ", GLUT_BITMAP_TIMES_ROMAN_24);
	glBegin(GL_LINE_LOOP);
	glVertex2i(770, 600);
	glVertex2i(1200, 600);
	glVertex2i(1200, 550);
	glVertex2i(770, 550);
	glEnd();
	glRasterPos2f(780, 565);
	cout << nome.length();
	FuncoesAuxiliares::writeWord_BITMAP(nome, GLUT_BITMAP_HELVETICA_18);
	glBegin(GL_LINE_LOOP);
	glVertex2i(1080, 530);
	glVertex2i(1200, 530);
	glVertex2i(1200, 480);
	glVertex2i(1080, 480);
	glEnd();
	glRasterPos2f(1095, 490);
	FuncoesAuxiliares::writeWord_BITMAP("Salvar", GLUT_BITMAP_TIMES_ROMAN_24);
}
void EfeitoVisual::desenhaTitulo(int posX, int posY)
{

    glColor3f(0, 1.0, 1.0);
    int x1 = 100 + posX, y1 = 100 + posY;

    //J
    FuncoesAuxiliares::bresenham(x1, 750 + y1 + 80, x1, 660 + y1); //  |
    FuncoesAuxiliares::bresenham(x1 - 100, 660 + y1, x1, 660 + y1); // _
    FuncoesAuxiliares::bresenham(x1 - 100, 660 + y1, x1, 660 + y1); // _
    FuncoesAuxiliares::bresenham(x1 - 100, 660 + y1, x1 - 100, 698 + y1); //i 
    FuncoesAuxiliares::bresenham(x1 - 100, 698 + y1, x1 - 70, 698 + y1);//-
    FuncoesAuxiliares::bresenham(x1 - 70, 698 + y1, x1 - 70, 680 + y1);//'
    FuncoesAuxiliares::bresenham(x1 - 70, 680 + y1, x1 - 28, 680 + y1);//---
    FuncoesAuxiliares::bresenham(x1 - 28, 680 + y1, x1 - 28, 750 + y1 + 80);// I
    FuncoesAuxiliares::bresenham(x1 - 28, 750 + y1 + 80, x1, 750 + y1 + 80); //-

    //I
    FuncoesAuxiliares::bresenham(x1 + 15, 750 + y1 + 80, x1 + 15, 660 + y1);
    FuncoesAuxiliares::bresenham(x1 + 45, 660 + y1, x1 + 15, 660 + y1);
    FuncoesAuxiliares::bresenham(x1 + 45, 660 + y1, x1 + 45, 750 + y1 + 80);
    FuncoesAuxiliares::bresenham(x1 + 45, 750 + y1 + 80, x1 + 15, 750 + y1 + 80);

    //R
    x1 += 15;
    FuncoesAuxiliares::bresenham(x1 + 45, 750 + y1 + 80, x1 + 45, 660 + y1); //|
    FuncoesAuxiliares::bresenham(x1 + 45, 750 + y1 + 80, x1 + 145, 750 + y1 + 80);//- em cima
    FuncoesAuxiliares::bresenham(x1 + 145, 750 + y1 + 80, x1 + 145, 700 + y1 + 30);// ' ate o meio
    FuncoesAuxiliares::bresenham(x1 + 145, 700 + y1 + 30, x1 + 70, 700 + y1 + 30);// - ate o meio do R
    FuncoesAuxiliares::bresenham(x1 + 70, 700 + y1 + 30, x1 + 145, 660 + y1);// \ate o fim do r
    FuncoesAuxiliares::bresenham(x1 + 145, 660 + y1, x1 + 115, 660 + y1);//
    FuncoesAuxiliares::bresenham(x1 + 70, 695 + y1 + 10, x1 + 115, 660 + y1);//
    FuncoesAuxiliares::bresenham(x1 + 70, 695 + y1 + 10, x1 + 70, 660 + y1);//
    FuncoesAuxiliares::bresenham(x1 + 70, 660 + y1, x1 + 45, 660 + y1);//
    FuncoesAuxiliares::bresenham(x1 + 75 + 5, 715 + y1 + 40, x1 + 112, 715 + y1 + 40);//quadradinho
    FuncoesAuxiliares::bresenham(x1 + 112, 715 + y1 + 40, x1 + 112, 740 + y1 + 50);//
    FuncoesAuxiliares::bresenham(x1 + 112, 740 + y1 + 50, x1 + 75 + 5, 740 + y1 + 50);//
    FuncoesAuxiliares::bresenham(x1 + 75 + 5, 740 + y1 + 50, x1 + 75 + 5, 715 + y1 + 40);//
    //A
    //A
    x1 += 50;
    FuncoesAuxiliares::bresenham(x1 + 110, 750 + y1 + 80, x1 + 110, 660 + y1);
    FuncoesAuxiliares::bresenham(x1 + 110, 750 + y1 + 80, x1 + 220, 750 + y1 + 80);
    FuncoesAuxiliares::bresenham(x1 + 220, 750 + y1 + 80, x1 + 220, 660 + y1);
    FuncoesAuxiliares::bresenham(x1 + 220, 660 + y1, x1 + 193, 660 + y1);
    FuncoesAuxiliares::bresenham(x1 + 193, 660 + y1, x1 + 193, 700 + y1 + 30);
    FuncoesAuxiliares::bresenham(x1 + 110, 660 + y1, x1 + 142, 660 + y1);
    FuncoesAuxiliares::bresenham(x1 + 142, 700 + y1 + 30, x1 + 142, 660 + y1);
    FuncoesAuxiliares::bresenham(x1 + 142, 700 + y1 + 30, x1 + 193, 700 + y1 + 30);
    FuncoesAuxiliares::bresenham(x1 + 142, 715 + y1 + 45, x1 + 193, 715 + y1 + 45);//quadradinho
    FuncoesAuxiliares::bresenham(x1 + 142, 715 + y1 + 45, x1 + 142, 735 + y1 + 60);
    FuncoesAuxiliares::bresenham(x1 + 142, 735 + y1 + 60, x1 + 193, 735 + y1 + 60);
    FuncoesAuxiliares::bresenham(x1 + 193, 715 + y1 + 45, x1 + 193, 735 + y1 + 60);

    //Y
    x1 += 65;
    FuncoesAuxiliares::bresenham(x1 + 175, 660 + y1, x1 + 190 + 20, 660 + y1);
    FuncoesAuxiliares::bresenham(x1 + 190 + 20, 660 + y1, x1 + 280, 750 + y1 + 80);
    FuncoesAuxiliares::bresenham(x1 + 280, 750 + y1 + 80, x1 + 245, 750 + y1 + 80);
    FuncoesAuxiliares::bresenham(x1 + 175, 660 + y1, x1 + 193, 705 + y1);
    FuncoesAuxiliares::bresenham(x1 + 193, 705 + y1, x1 + 170, 750 + y1 + 80);
    FuncoesAuxiliares::bresenham(x1 + 170, 750 + y1 + 80, x1 + 195, 750 + y1 + 80);
    FuncoesAuxiliares::bresenham(x1 + 195, 750 + y1 + 80, x1 + 213, 718 + y1 + 35);
    FuncoesAuxiliares::bresenham(x1 + 213, 718 + y1 + 35, x1 + 245, 750 + y1 + 80);

    //A
    x1 += 185;
    FuncoesAuxiliares::bresenham(x1 + 110, 750 + y1 + 80, x1 + 110, 660 + y1);
    FuncoesAuxiliares::bresenham(x1 + 110, 750 + y1 + 80, x1 + 220, 750 + y1 + 80);
    FuncoesAuxiliares::bresenham(x1 + 220, 750 + y1 + 80, x1 + 220, 660 + y1);
    FuncoesAuxiliares::bresenham(x1 + 220, 660 + y1, x1 + 193, 660 + y1);
    FuncoesAuxiliares::bresenham(x1 + 193, 660 + y1, x1 + 193, 700 + y1 + 30);
    FuncoesAuxiliares::bresenham(x1 + 110, 660 + y1, x1 + 142, 660 + y1);
    FuncoesAuxiliares::bresenham(x1 + 142, 700 + y1 + 30, x1 + 142, 660 + y1);
    FuncoesAuxiliares::bresenham(x1 + 142, 700 + y1 + 30, x1 + 193, 700 + y1 + 30);
    FuncoesAuxiliares::bresenham(x1 + 142, 715 + y1 + 45, x1 + 193, 715 + y1 + 45);//quadradinho
    FuncoesAuxiliares::bresenham(x1 + 142, 715 + y1 + 45, x1 + 142, 735 + y1 + 60);
    FuncoesAuxiliares::bresenham(x1 + 142, 735 + y1 + 60, x1 + 193, 735 + y1 + 60);
    FuncoesAuxiliares::bresenham(x1 + 193, 715 + y1 + 45, x1 + 193, 735 + y1 + 60);

    //'
    x1 += 15;
    FuncoesAuxiliares::bresenham(x1 + 220, 750 + y1 + 80, x1 + 220, 720 + y1 + 70);
    FuncoesAuxiliares::bresenham(x1 + 220, 750 + y1 + 80, x1 + 245, 750 + y1 + 80);
    FuncoesAuxiliares::bresenham(x1 + 220, 720 + y1 + 70, x1 + 245, 750 + y1 + 80);

    //s
    x1 -= 75;
    FuncoesAuxiliares::bresenham(x1 + 300, 718 + y1 + 30, x1 + 355, 718 + y1 + 30);
    FuncoesAuxiliares::bresenham(x1 + 355, 718 + y1 + 30, x1 + 355, 703 + y1 + 25);
    FuncoesAuxiliares::bresenham(x1 + 315, 703 + y1 + 25, x1 + 355, 703 + y1 + 25);
    FuncoesAuxiliares::bresenham(x1 + 300, 718 + y1 + 30, x1 + 300, 683 + y1 + 15);
    FuncoesAuxiliares::bresenham(x1 + 315, 703 + y1 + 25, x1 + 315, 695 + y1 + 15);
    FuncoesAuxiliares::bresenham(x1 + 355, 695 + y1 + 15, x1 + 315, 695 + y1 + 15);
    FuncoesAuxiliares::bresenham(x1 + 355, 695 + y1 + 15, x1 + 355, 660 + y1);
    FuncoesAuxiliares::bresenham(x1 + 355, 660 + y1, x1 + 300, 660 + y1);
    FuncoesAuxiliares::bresenham(x1 + 300, 671 + y1, x1 + 300, 660 + y1);
    FuncoesAuxiliares::bresenham(x1 + 300, 671 + y1, x1 + 340, 671 + y1);
    FuncoesAuxiliares::bresenham(x1 + 340, 683 + y1 + 15, x1 + 340, 671 + y1);
    FuncoesAuxiliares::bresenham(x1 + 300, 683 + y1 + 15, x1 + 340, 683 + y1 + 15);

    //fly	
    //f
    int y2 = -40 + posY;
    x1 = 103 + posX;
    FuncoesAuxiliares::bresenham(x1 + 160, 635 + y2, x1 + 160, 730 + y2);
    FuncoesAuxiliares::bresenham(x1 + 160, 730 + y2, x1 + 220, 730 + y2);
    FuncoesAuxiliares::bresenham(x1 + 220, 730 + y2, x1 + 220, 705 + y2);
    FuncoesAuxiliares::bresenham(x1 + 220, 705 + y2, x1 + 180, 705 + y2);
    FuncoesAuxiliares::bresenham(x1 + 180, 705 + y2, x1 + 180, 685 + y2);
    FuncoesAuxiliares::bresenham(x1 + 180, 685 + y2, x1 + 200, 685 + y2);
    FuncoesAuxiliares::bresenham(x1 + 200, 685 + y2, x1 + 200, 665 + y2);
    FuncoesAuxiliares::bresenham(x1 + 200, 665 + y2, x1 + 180, 665 + y2);
    FuncoesAuxiliares::bresenham(x1 + 180, 665 + y2, x1 + 180, 635 + y2);
    FuncoesAuxiliares::bresenham(x1 + 160, 635 + y2, x1 + 180, 635 + y2);

    //l
    FuncoesAuxiliares::bresenham(x1 + 230, 635 + y2, x1 + 230, 730 + y2);
    FuncoesAuxiliares::bresenham(x1 + 230, 635 + y2, x1 + 275, 635 + y2);
    FuncoesAuxiliares::bresenham(x1 + 275, 635 + y2, x1 + 275, 655 + y2);
    FuncoesAuxiliares::bresenham(x1 + 275, 655 + y2, x1 + 250, 655 + y2);
    FuncoesAuxiliares::bresenham(x1 + 250, 655 + y2, x1 + 250, 730 + y2);
    FuncoesAuxiliares::bresenham(x1 + 230, 730 + y2, x1 + 250, 730 + y2);

    //y
    x1 += 115;
    FuncoesAuxiliares::bresenham(x1 + 175, 635 + y2, x1 + 195, 635 + y2);
    FuncoesAuxiliares::bresenham(x1 + 195, 635 + y2, x1 + 230, 730 + y2);
    FuncoesAuxiliares::bresenham(x1 + 230, 730 + y2, x1 + 210, 730 + y2);
    FuncoesAuxiliares::bresenham(x1 + 175, 635 + y2, x1 + 193, 680 + y2);
    FuncoesAuxiliares::bresenham(x1 + 193, 680 + y2, x1 + 165, 730 + y2);
    FuncoesAuxiliares::bresenham(x1 + 165, 730 + y2, x1 + 180, 730 + y2);
    FuncoesAuxiliares::bresenham(x1 + 180, 730 + y2, x1 + 198, 698 + y2);
    FuncoesAuxiliares::bresenham(x1 + 198, 698 + y2, x1 + 210, 730 + y2);

    //Circulos com Bresenham
    glColor3f(1.0, 1.0, 0.0); //amarelo
    FuncoesAuxiliares::bresenhamCircle(620 + posX, 650 + posY, 90, 90);
    glColor3f(0, 0.0, 0.8);
    FuncoesAuxiliares::bresenhamCircle(620 + posX, 650 + posY, 80, 80);
    glColor3f(1.0, 1.0, 1.0);
    FuncoesAuxiliares::bresenhamCircle(620 + posX, 650 + posY, 40, 40);
    glColor3f(1.0, 0.0, 0.0);
    FuncoesAuxiliares::bresenhamCircle(620 + posX, 650 + posY, 30, 30);

    //katana
    int xk = 540 + posX;
    int yk = 50 + posY;
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(-20 + xk, yk + 518);
    glVertex2i(-10 + xk, yk + 498);
    glVertex2i(20 + xk, yk + 528);
    glVertex2i(10 + xk, yk + 548);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(-19 + xk, yk + 518);
    glVertex2i(-11 + xk, yk + 498);
    glVertex2i(19 + xk, yk + 528);
    glVertex2i(11 + xk, yk + 548);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    FuncoesAuxiliares::bresenhamCircle(-8 + xk, yk + 515, 2, 2);
    FuncoesAuxiliares::bresenhamCircle(7 + xk, yk + 530, 2, 2);
    glBegin(GL_LINE_LOOP);
    glVertex2i(27 + xk, yk + 521);
    glVertex2i(7 + xk, yk + 558);
    glVertex2i(14 + xk, yk + 565);
    glVertex2i(35 + xk, yk + 525);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(16 + xk, yk + 521);
    glVertex2i(8 + xk, yk + 558);
    glVertex2i(15 + xk, yk + 565);
    glVertex2i(34 + xk, yk + 525);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(28 + xk, yk + 537);
    glVertex2i(170 + xk, yk + 669);
    glVertex2i(170 + xk, yk + 695);
    glVertex2i(18 + xk, yk + 552);
    glEnd();


    //Circulos com Bresenham
    glColor3f(1.0, 1.0, 0.0); //amarelo
    FuncoesAuxiliares::bresenhamCircle(90 + posX, 650 + posY, 90, 90);
    glColor3f(0, 0.0, 0.8);
    FuncoesAuxiliares::bresenhamCircle(90 + posX, 650 + posY, 80, 80);
    glColor3f(1.0, 1.0, 1.0);
    FuncoesAuxiliares::bresenhamCircle(90 + posX, 650 + posY, 40, 40);
    glColor3f(1.0, 0.0, 0.0);
    FuncoesAuxiliares::bresenhamCircle(90 + posX, 650 + posY, 30, 30);

    //katana
    xk = 170 + posX;
    yk = 50 + posY;
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(20 + xk, yk + 518);
    glVertex2i(10 + xk, yk + 498);
    glVertex2i(-20 + xk, yk + 528);
    glVertex2i(-10 + xk, yk + 548);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(19 + xk, yk + 518);
    glVertex2i(11 + xk, yk + 498);
    glVertex2i(-19 + xk, yk + 528);
    glVertex2i(-11 + xk, yk + 548);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    FuncoesAuxiliares::bresenhamCircle(8 + xk, yk + 515, 2, 2);
    FuncoesAuxiliares::bresenhamCircle(-7 + xk, yk + 530, 2, 2);
    glBegin(GL_LINE_LOOP);
    glVertex2i(-27 + xk, yk + 521);
    glVertex2i(-7 + xk, yk + 558);
    glVertex2i(-14 + xk, yk + 565);
    glVertex2i(-35 + xk, yk + 525);
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2i(-16 + xk, yk + 521);
    glVertex2i(-8 + xk, yk + 558);
    glVertex2i(-15 + xk, yk + 565);
    glVertex2i(-34 + xk, yk + 525);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex2i(-28 + xk, yk + 537);
    glVertex2i(-170 + xk, yk + 669);
    glVertex2i(-170 + xk, yk + 695);
    glVertex2i(-18 + xk, yk + 552);
    glEnd();
}

EfeitoVisual& EfeitoVisual::getInstance()
{
    static EfeitoVisual singleton;
    return singleton;
}
