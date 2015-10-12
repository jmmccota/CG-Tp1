#include "Menu.hpp"
#define FONT_DEFAULT GLUT_BITMAP_HELVETICA_18

Menu::Menu() {
}

Menu::~Menu() {
	Fase::~Fase();
}

void Menu::definePersonagens() {
}

void Menu::desenhaBackground() {
}

#pragma region "Pack de Desenho do Menu"

//-------------- Usado para pegar Dinamicamente a Posição dos Elementos do Menu ---------------
struct PositionMenuElement
{
	float posInit_X;
	float posEnd_X;
	float posInit_Y;
	float posEnd_Y;

};
vector<PositionMenuElement> vetPosMenuElements;
//----------------------------------------------------------------------------------------------
int setaSelectOption = 0;
bool limitX = false;
// mover aviao d opcoes
GLfloat translacaoOpcoesY = 0.0f;
GLfloat translacaoOpcoesX = 0.0f;
GLfloat translacaoTiro = 0.0f;
boolean atirou = false;

//Desenha uma Linha - Parametro: posição em relação ao eixo Y
void drawLine(float pos, char eixo) {

	pair<int, int> size = EfeitoVisual::getInstance().getOrtho2D();

	//glColor3f(0, 1.0, 0.9);
	glColor3f(1, 0.27, 0);
	glLineWidth(3.0f);
	if (eixo == 'x') {
		glBegin(GL_LINE_LOOP);
		glVertex2f(pos, 0.0);
		glVertex2f(pos, size.second);
		glEnd();
	}
	else if (eixo == 'y') {
		glBegin(GL_LINE_LOOP);
		glVertex2f(0.0, pos);
		glVertex2f(size.first, pos);
		glEnd();
	}
}

void drawTitulo() {
	glColor3f(0, 1.0, 1.0);
	int x1, y1;
	//J
	x1 = 50;
	y1 = 100;
	//j
	FuncoesAuxiliares::bresenham(1170 + x1, 750 + y1 + 80, 1170 + x1, 660 + y1); //  |
	FuncoesAuxiliares::bresenham(1120, 660 + y1, 1170 + x1, 660 + y1); // _
	FuncoesAuxiliares::bresenham(1120, 660 + y1, 1120, 698 + y1); //i 
	FuncoesAuxiliares::bresenham(1120, 698 + y1, 1150, 698 + y1);//-
	FuncoesAuxiliares::bresenham(1150, 698 + y1, 1150, 680 + y1);//'
	FuncoesAuxiliares::bresenham(1150, 680 + y1, 1142 + x1, 680 + y1);//---
	FuncoesAuxiliares::bresenham(1142 + x1, 680 + y1, 1142 + x1, 750 + y1 + 80);// I
	FuncoesAuxiliares::bresenham(1142 + x1, 750 + y1 + 80, 1170 + x1, 750 + y1 + 80); //-
	//I
	x1 = 50;
	FuncoesAuxiliares::bresenham(1185 + x1, 750 + y1 + 80, 1185 + x1, 660 + y1);
	FuncoesAuxiliares::bresenham(1215 + x1, 660 + y1, 1185 + x1, 660 + y1);
	FuncoesAuxiliares::bresenham(1215 + x1, 660 + y1, 1215 + x1, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(1215 + x1, 750 + y1 + 80, 1185 + x1, 750 + y1 + 80);
	//R
	x1 = 65;
	FuncoesAuxiliares::bresenham(1215 + x1, 750 + y1 + 80, 1215 + x1, 660 + y1); //|
	FuncoesAuxiliares::bresenham(1215 + x1, 750 + y1 + 80, 1265 + 50 + x1, 750 + y1 + 80);//- em cima
	FuncoesAuxiliares::bresenham(1265 + x1 + 50, 750 + y1 + 80, 1265 + 50 + x1, 700 + y1 + 30);// ' ate o meio
	FuncoesAuxiliares::bresenham(1265 + 50 + x1, 700 + y1 + 30, 1240 + x1, 700 + y1 + 30);// - ate o meio do R
	FuncoesAuxiliares::bresenham(1240 + x1, 700 + y1 + 30, 1265 + 50 + x1, 660 + y1);// \ate o fim do r
	FuncoesAuxiliares::bresenham(1265 + 50 + x1, 660 + y1, 1250 + x1 + 35, 660 + y1);//
	FuncoesAuxiliares::bresenham(1240 + x1, 695 + y1 + 10, 1250 + x1 + 35, 660 + y1);//
	FuncoesAuxiliares::bresenham(1240 + x1, 695 + y1 + 10, 1240 + x1, 660 + y1);//
	FuncoesAuxiliares::bresenham(1240 + x1, 660 + y1, 1215 + x1, 660 + y1);//
	FuncoesAuxiliares::bresenham(1245 + x1 + 5, 715 + y1 + 40, 1277 + x1 + 5, 715 + y1 + 40);//quadradinho
	FuncoesAuxiliares::bresenham(1277 + x1 + 5, 715 + y1 + 40, 1277 + x1 + 5, 740 + y1 + 50);//
	FuncoesAuxiliares::bresenham(1277 + x1 + 5, 740 + y1 + 50, 1245 + x1 + 5, 740 + y1 + 50);//
	FuncoesAuxiliares::bresenham(1245 + x1 + 5, 740 + y1 + 50, 1245 + x1 + 5, 715 + y1 + 40);//
	//A
	x1 = 115;
	FuncoesAuxiliares::bresenham(1280 + x1, 750 + y1 + 80, 1280 + x1, 660 + y1);
	FuncoesAuxiliares::bresenham(1280 + x1, 750 + y1 + 80, 1330 + x1 + 50, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(1330 + x1 + 50, 750 + y1 + 80, 1330 + x1 + 50, 660 + y1);
	FuncoesAuxiliares::bresenham(1330 + x1 + 50, 660 + y1, 1313 + x1 + 35, 660 + y1);
	FuncoesAuxiliares::bresenham(1313 + x1 + 35, 660 + y1, 1313 + x1 + 35, 700 + y1 + 30);
	FuncoesAuxiliares::bresenham(1280 + x1, 660 + y1, 1297 + x1 + 15, 660 + y1);
	FuncoesAuxiliares::bresenham(1297 + x1 + 15, 700 + y1 + 30, 1297 + x1 + 15, 660 + y1);
	FuncoesAuxiliares::bresenham(1297 + x1 + 15, 700 + y1 + 30, 1313 + x1 + 35, 700 + y1 + 30);
	FuncoesAuxiliares::bresenham(1297 + x1 + 15, 715 + y1 + 45, 1313 + x1 + 35, 715 + y1 + 45);//quadradinho
	FuncoesAuxiliares::bresenham(1297 + x1 + 15, 715 + y1 + 45, 1297 + x1 + 15, 735 + y1 + 60);
	FuncoesAuxiliares::bresenham(1297 + x1 + 15, 735 + y1 + 60, 1313 + x1 + 35, 735 + y1 + 60);
	FuncoesAuxiliares::bresenham(1313 + x1 + 35, 715 + y1 + 45, 1313 + x1 + 35, 735 + y1 + 60);
	//Y
	x1 = 165;
	FuncoesAuxiliares::bresenham(1345 + x1, 660 + y1, 1360 + x1 + 20, 660 + y1);
	FuncoesAuxiliares::bresenham(1360 + x1 + 20, 660 + y1, 1395 + x1 + 55, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(1395 + x1 + 55, 750 + y1 + 80, 1380 + x1 + 35, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(1345 + x1, 660 + y1, 1363 + x1, 705 + y1);
	FuncoesAuxiliares::bresenham(1363 + x1, 705 + y1, 1340 + x1, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(1340 + x1, 750 + y1 + 80, 1350 + x1 + 15, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(1350 + x1 + 15, 750 + y1 + 80, 1368 + x1 + 15, 718 + y1 + 35);
	FuncoesAuxiliares::bresenham(1368 + x1 + 15, 718 + y1 + 35, 1380 + x1 + 35, 750 + y1 + 80);
	//A
	x1 = 340;
	FuncoesAuxiliares::bresenham(1280 + x1, 750 + y1 + 80, 1280 + x1, 660 + y1);
	FuncoesAuxiliares::bresenham(1280 + x1, 750 + y1 + 80, 1330 + x1 + 50, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(1330 + x1 + 50, 750 + y1 + 80, 1330 + x1 + 50, 660 + y1);
	FuncoesAuxiliares::bresenham(1330 + x1 + 50, 660 + y1, 1313 + x1 + 35, 660 + y1);
	FuncoesAuxiliares::bresenham(1313 + x1 + 35, 660 + y1, 1313 + x1 + 35, 700 + y1 + 30);
	FuncoesAuxiliares::bresenham(1280 + x1, 660 + y1, 1297 + x1 + 15, 660 + y1);
	FuncoesAuxiliares::bresenham(1297 + x1 + 15, 700 + y1 + 30, 1297 + x1 + 15, 660 + y1);
	FuncoesAuxiliares::bresenham(1297 + x1 + 15, 700 + y1 + 30, 1313 + x1 + 35, 700 + y1 + 30);
	FuncoesAuxiliares::bresenham(1297 + x1 + 15, 715 + y1 + 45, 1313 + x1 + 35, 715 + y1 + 45);//quadradinho
	FuncoesAuxiliares::bresenham(1297 + x1 + 15, 715 + y1 + 45, 1297 + x1 + 15, 735 + y1 + 60);
	FuncoesAuxiliares::bresenham(1297 + x1 + 15, 735 + y1 + 60, 1313 + x1 + 35, 735 + y1 + 60);
	FuncoesAuxiliares::bresenham(1313 + x1 + 35, 715 + y1 + 45, 1313 + x1 + 35, 735 + y1 + 60);
	//'
	x1 = 265;
	FuncoesAuxiliares::bresenham(1465 + x1, 750 + y1 + 80, 1465 + x1, 720 + y1 + 70);
	FuncoesAuxiliares::bresenham(1465 + x1, 750 + y1 + 80, 1480 + x1 + 10, 750 + y1 + 80);
	FuncoesAuxiliares::bresenham(1465 + x1, 720 + y1 + 70, 1480 + x1 + 10, 750 + y1 + 80);
	//s
	FuncoesAuxiliares::bresenham(1470 + x1, 718 + y1 + 30, 1510 + x1 + 15, 718 + y1 + 30);
	FuncoesAuxiliares::bresenham(1510 + x1 + 15, 718 + y1 + 30, 1510 + x1 + 15, 703 + y1 + 25);
	FuncoesAuxiliares::bresenham(1485 + x1, 703 + y1 + 25, 1510 + x1 + 15, 703 + y1 + 25);
	FuncoesAuxiliares::bresenham(1470 + x1, 718 + y1 + 30, 1470 + x1, 683 + y1 + 15);
	FuncoesAuxiliares::bresenham(1485 + x1, 703 + y1 + 25, 1485 + x1, 695 + y1 + 15);
	FuncoesAuxiliares::bresenham(1510 + x1 + 15, 695 + y1 + 15, 1485 + x1, 695 + y1 + 15);
	FuncoesAuxiliares::bresenham(1510 + x1 + 15, 695 + y1 + 15, 1510 + x1 + 15, 660 + y1);
	FuncoesAuxiliares::bresenham(1510 + x1 + 15, 660 + y1, 1470 + x1, 660 + y1);
	FuncoesAuxiliares::bresenham(1470 + x1, 671 + y1, 1470 + x1, 660 + y1);
	FuncoesAuxiliares::bresenham(1470 + x1, 671 + y1, 1495 + x1 + 15, 671 + y1);
	FuncoesAuxiliares::bresenham(1495 + x1 + 15, 683 + y1 + 15, 1495 + x1 + 15, 671 + y1);
	FuncoesAuxiliares::bresenham(1470 + x1, 683 + y1 + 15, 1495 + x1 + 15, 683 + y1 + 15);
	//fly	
	//f
	int y2 = -40;
	int x3 = 40;
	FuncoesAuxiliares::bresenham(1330 + x3, 635 + y2, 1330 + x3, 730 + y2);
	FuncoesAuxiliares::bresenham(1330 + x3, 730 + y2, 1390 + x3, 730 + y2);
	FuncoesAuxiliares::bresenham(1390 + x3, 730 + y2, 1390 + x3, 705 + y2);
	FuncoesAuxiliares::bresenham(1390 + x3, 705 + y2, 1350 + x3, 705 + y2);
	FuncoesAuxiliares::bresenham(1350 + x3, 705 + y2, 1350 + x3, 685 + y2);
	FuncoesAuxiliares::bresenham(1350 + x3, 685 + y2, 1370 + x3, 685 + y2);
	FuncoesAuxiliares::bresenham(1370 + x3, 685 + y2, 1370 + x3, 665 + y2);
	FuncoesAuxiliares::bresenham(1370 + x3, 665 + y2, 1350 + x3, 665 + y2);
	FuncoesAuxiliares::bresenham(1350 + x3, 665 + y2, 1350 + x3, 635 + y2);
	FuncoesAuxiliares::bresenham(1330 + x3, 635 + y2, 1350 + x3, 635 + y2);
	//l
	FuncoesAuxiliares::bresenham(1400 + x3, 635 + y2, 1400 + x3, 730 + y2);
	FuncoesAuxiliares::bresenham(1400 + x3, 635 + y2, 1445 + x3, 635 + y2);
	FuncoesAuxiliares::bresenham(1445 + x3, 635 + y2, 1445 + x3, 655 + y2);
	FuncoesAuxiliares::bresenham(1445 + x3, 655 + y2, 1420 + x3, 655 + y2);
	FuncoesAuxiliares::bresenham(1420 + x3, 655 + y2, 1420 + x3, 730 + y2);
	FuncoesAuxiliares::bresenham(1400 + x3, 730 + y2, 1420 + x3, 730 + y2);
	//y
	int x2 = 115;
	FuncoesAuxiliares::bresenham(1345 + x2 + x3, 635 + y2, 1360 + x2 + 5 + x3, 635 + y2);
	FuncoesAuxiliares::bresenham(1360 + x2 + 5 + x3, 635 + y2, 1395 + x2 + 5 + x3, 730 + y2);
	FuncoesAuxiliares::bresenham(1395 + x2 + 5 + x3, 730 + y2, 1380 + x2 + x3, 730 + y2);
	FuncoesAuxiliares::bresenham(1345 + x2 + x3, 635 + y2, 1363 + x2 + x3, 680 + y2);
	FuncoesAuxiliares::bresenham(1363 + x2 + x3, 680 + y2, 1335 + x2 + x3, 730 + y2);
	FuncoesAuxiliares::bresenham(1335 + x2 + x3, 730 + y2, 1350 + x2 + x3, 730 + y2);
	FuncoesAuxiliares::bresenham(1350 + x2 + x3, 730 + y2, 1368 + x2 + x3, 698 + y2);
	FuncoesAuxiliares::bresenham(1368 + x2 + x3, 698 + y2, 1380 + x2 + x3, 730 + y2);
	//circulo?????????
	glColor3f(1.0, 1.0, 0.0); //amarelo
	FuncoesAuxiliares::bresenhamCircle(1700, 650, 90, 90);
	glColor3f(0, 0.0, 0.8);
	FuncoesAuxiliares::bresenhamCircle(1700, 650, 80, 80);
	glColor3f(1.0, 1.0, 1.0);
	FuncoesAuxiliares::bresenhamCircle(1700, 650, 40, 40);
	glColor3f(1.0, 0.0, 0.0);
	FuncoesAuxiliares::bresenhamCircle(1700, 650, 30, 30);

	//katana
	int xk = 460;
	int yk = 50;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(1150 + xk, yk + 518);
	glVertex2i(1160 + xk, yk + 498);
	glVertex2i(1190 + xk, yk + 528);
	glVertex2i(1180 + xk, yk + 548);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(1151 + xk, yk + 518);
	glVertex2i(1159 + xk, yk + 498);
	glVertex2i(1189 + xk, yk + 528);
	glVertex2i(1181 + xk, yk + 548);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	FuncoesAuxiliares::bresenhamCircle(1162 + xk, yk + 515, 2, 2);
	FuncoesAuxiliares::bresenhamCircle(1177 + xk, yk + 530, 2, 2);
	glBegin(GL_LINE_LOOP);
	glVertex2i(1197 + xk, yk + 521);
	glVertex2i(1177 + xk, yk + 558);
	glVertex2i(1184 + xk, yk + 565);
	glVertex2i(1205 + xk, yk + 525);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(1196 + xk, yk + 521);
	glVertex2i(1178 + xk, yk + 558);
	glVertex2i(1185 + xk, yk + 565);
	glVertex2i(1204 + xk, yk + 525);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(1198 + xk, yk + 537);
	glVertex2i(1340 + xk, yk + 669);
	glVertex2i(1340 + xk, yk + 695);
	glVertex2i(1189 + xk, yk + 552);

	glEnd();


	//circulo?????????
	glColor3f(1.0, 1.0, 0.0); //amarelo
	FuncoesAuxiliares::bresenhamCircle(1200, 650, 90, 90);
	glColor3f(0, 0.0, 0.8);
	FuncoesAuxiliares::bresenhamCircle(1200, 650, 80, 80);
	glColor3f(1.0, 1.0, 1.0);
	FuncoesAuxiliares::bresenhamCircle(1200, 650, 40, 40);
	glColor3f(1.0, 0.0, 0.0);
	FuncoesAuxiliares::bresenhamCircle(1200, 650, 30, 30);

	//katana
	int xk2 = -50;
	int yk2 = 50;
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(1150 + xk2, yk2 + 518);
	glVertex2i(1160 + xk2, yk2 + 498);
	glVertex2i(1190 + xk2, yk2 + 528);
	glVertex2i(1180 + xk2, yk2 + 548);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(1151 + xk2, yk2 + 518);
	glVertex2i(1159 + xk2, yk2 + 498);
	glVertex2i(1189 + xk2, yk2 + 528);
	glVertex2i(1181 + xk2, yk2 + 548);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	FuncoesAuxiliares::bresenhamCircle(1162 + xk2, yk2 + 515, 2, 2);
	FuncoesAuxiliares::bresenhamCircle(1177 + xk2, yk2 + 530, 2, 2);
	glBegin(GL_LINE_LOOP);
	glVertex2i(1197 + xk2, yk2 + 521);
	glVertex2i(1177 + xk2, yk2 + 558);
	glVertex2i(1184 + xk2, yk2 + 565);
	glVertex2i(1205 + xk2, yk2 + 525);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(1196 + xk2, yk2 + 521);
	glVertex2i(1178 + xk2, yk2 + 558);
	glVertex2i(1185 + xk2, yk2 + 565);
	glVertex2i(1204 + xk2, yk2 + 525);
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_QUADS);
	glVertex2i(1198 + xk2, yk2 + 537);
	glVertex2i(1340 + xk2, yk2 + 669);
	glVertex2i(1340 + xk2, yk2 + 695);
	glVertex2i(1189 + xk2, yk2 + 552);
	glEnd();
}

//Desenha Quadrado para Opções - Paremetros: Posição x, Posição Y, Titulo 
void drawSquad(float posX, float posY, string titulo) {

	pair<float, float> fullHD = EfeitoVisual::getInstance().getOrtho2D();
	float rasterX = fullHD.first - posX;
	float rasterY = 140;

	if (EfeitoVisual::getInstance().isFullScreen()) {
		glRasterPos2f(posX - (titulo.length() * 5) + ((rasterX - posX) / 2), posY - 10);
	}
	else {
		glRasterPos2f(posX - (titulo.length() * 10) + ((rasterX - posX) / 2), posY - 10);

	}
	glColor3f(0.0, 0.0, 1);
	FuncoesAuxiliares::writeWord_BITMAP(titulo, FONT_DEFAULT);

	//-------------------- BEGIN BOXES DE BESTSCORES ---------------------
	glColor3f(0.0, 0.0, 1);
	glLineWidth(3.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(rasterX - 11.1111112, posY + 35.5555556);
	glVertex2f(rasterX - 6.6666666, posY + 31.1111111);
	glVertex2f(rasterX - 3.3333333, posY + 24.4444444);
	glVertex2f(rasterX - 2.2222222, posY + 13.3333333);
	glVertex2f(rasterX, posY);
	glVertex2f(rasterX, rasterY);
	glVertex2f(rasterX - 1.1111111, posY - 13.3333333);
	glVertex2f(rasterX - 3.3333333, posY - 24.4444444);
	glVertex2f(rasterX - 6.6666666, posY - 31.1111111);
	glVertex2f(rasterX - 11.1111112, posY - 35.5555556);
	glVertex2f(posX + 11.1111112, posY - 35.5555556);
	glVertex2f(posX + 6.6666666, posY - 31.1111111);
	glVertex2f(posX + 3.3333333, posY - 24.4444444);
	glVertex2f(posX + 1.1111111, posY - 13.3333333);
	glVertex2f(posX, posY);
	glVertex2f(posX, rasterY);
	glVertex2f(posX + 1.1111111, posY + 13.3333333);
	glVertex2f(posX + 3.3333333, posY + 24.4444444);
	glVertex2f(posX + 6.6666666, posY + 31.1111111);
	glVertex2f(posX + 11.1111112, posY + 35.5555556);
	glEnd();
	glBegin(GL_LINES);
	glVertex2f(posX, rasterY);
	glVertex2f(rasterX, rasterY);
	glEnd();
	glColor3f(1, 0.27, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(200, 630);
	glVertex2i(175, 600);
	glVertex2i(200, 570);
	glVertex2i(200, 590);
	glVertex2i(245, 590);
	glVertex2i(245, 610);
	glVertex2i(200, 610);
	glEnd();
	//-------------------- END BOXES DE BESTSCORES ---------------------
}

//Desenha as Opções Dinamicamente - Parametros: options, quantidade de Opções, e a posição inial Y
void drawOptionsMenu(char *options[], int quantOptions, int posY) {

	//Limpa vetor de posições de elementos do menu
	if (vetPosMenuElements.size() > 0) {
		vetPosMenuElements.clear();
	}

	pair<int, int> ortho = EfeitoVisual::getInstance().getOrtho2D();
	float rasterX = 1200;
	float rasterY = posY;

	//Escreve na tela
	for (int pos = 0; pos < quantOptions; pos++) {
		if (pos == setaSelectOption) {
			glColor3f(1.0, 1.0, 1.0);
		}
		else {
			//glColor3f(0, 1.0, 0.9);
			glColor3f(1, 0.27, 0);
		}

		string titulo = options[pos];
		if (EfeitoVisual::getInstance().isFullScreen()) {
			glRasterPos2f(rasterX - (titulo.length() * 5) + 251, rasterY - 10);
		}
		else {
			glRasterPos2f(rasterX - (titulo.length() * 10) + 251, rasterY - 10);
		}
		FuncoesAuxiliares::writeWord_BITMAP(titulo, FONT_DEFAULT);

		//-------------------- BEGIN BOXES DE OPÇÕES ---------------------
		glLineWidth(2.0f);
		glBegin(GL_LINE_LOOP);
		glVertex2f(rasterX + 588.89, rasterY + 35.56);
		glVertex2f(rasterX + 593.34, rasterY + 31.11);
		glVertex2f(rasterX + 596.67, rasterY + 24.44);
		glVertex2f(rasterX + 598.89, rasterY + 13.33);
		glVertex2f(rasterX + 600, rasterY + 0.11);
		glVertex2f(rasterX + 600, rasterY - 0.11);
		glVertex2f(rasterX + 598.89, rasterY - 13.33);
		glVertex2f(rasterX + 596.67, rasterY - 24.44);
		glVertex2f(rasterX + 593.33, rasterY - 31.11);
		glVertex2f(rasterX + 588.89, rasterY - 35.56);
		glVertex2f(rasterX - 88.89, rasterY - 35.56);
		glVertex2f(rasterX - 93.33, rasterY - 31.11);
		glVertex2f(rasterX - 96.67, rasterY - 24.44);
		glVertex2f(rasterX - 98.89, rasterY - 13.33);
		glVertex2f(rasterX - 100, rasterY - 0.11);
		glVertex2f(rasterX - 100, rasterY + 0.11);
		glVertex2f(rasterX - 98.89, rasterY + 13.33);
		glVertex2f(rasterX - 96.67, rasterY + 24.44);
		glVertex2f(rasterX - 93.33, rasterY + 31.11);
		glVertex2f(rasterX - 88.89, rasterY + 35.56);
		glEnd();
		//---------------------- END BOXES DE OPÇÕES ----------------------

		PositionMenuElement pElement;
		pElement.posInit_X = rasterX - 100;
		pElement.posEnd_X = rasterX + 600;
		pElement.posInit_Y = ortho.second - 35.56 - rasterY;
		pElement.posEnd_Y = ortho.second + 35.56 - rasterY;

		vetPosMenuElements.push_back(pElement);

		rasterY -= 90;
	}

}

//Desenha Melhores Scores - Parametros: bests, deslocamento no Y
void drawBestScoresMenu(vector<Score> bestScores, int decRasterY) {

	int rasterX = 250;
	int rasterY = 510;
	pair<int, int> sizeScreen = EfeitoVisual::getInstance().sizeScreen();
	glColor3f(0.93, 0.57, 0.13);

	for (int i = 0; i < bestScores.size(); i++) {
		glRasterPos2f(rasterX - 50, rasterY);
		string rank = std::to_string(i + 1) + " -  ";
		FuncoesAuxiliares::writeWord_BITMAP(rank, FONT_DEFAULT);


		string name = bestScores[i].getPlayer();
		glRasterPos2f(rasterX, rasterY);
		FuncoesAuxiliares::writeWord_BITMAP(name, FONT_DEFAULT);

		string score = std::to_string(bestScores[i].getScore());
		if (EfeitoVisual::getInstance().isFullScreen()) {
			glRasterPos2f(rasterX + (sizeScreen.first / 2) - (score.length() * 10) + 12, rasterY);
		}
		else {
			glRasterPos2f(rasterX + (sizeScreen.first / 2) + (290 - score.length() * 10), rasterY);
		}
		FuncoesAuxiliares::writeWord_BITMAP(score, FONT_DEFAULT);


		float comple = (sizeScreen.first / 2) / 10;
		string desloc = "_";
		for (int letter = 0; letter < comple; letter++) {
			desloc += "_";
		}
		glRasterPos2f(rasterX, rasterY);
		FuncoesAuxiliares::writeWord_BITMAP(desloc, FONT_DEFAULT);

		rasterY -= decRasterY;
	}
}

//Desenha a Opção do Menu - Parametro: 
void drawOpcoesMenu() {

	glColor3f(1, 1, 1);

	glRasterPos2f(200, 500);
	FuncoesAuxiliares::writeWord_BITMAP("O objetivo do jogo e terminar as 3 fases. Mate os 3 chefes e o maximo de inimigos possiveis!", FONT_DEFAULT);

	glRasterPos2f(200, 460);
	FuncoesAuxiliares::writeWord_BITMAP("A cada 100 mil pontos voce ganha uma vida.Caso perca todas, GAME OVER!", FONT_DEFAULT);

	glRasterPos2f(200, 420);
	FuncoesAuxiliares::writeWord_BITMAP("Comandos:", FONT_DEFAULT);

	glRasterPos2f(220, 380);
	FuncoesAuxiliares::writeWord_BITMAP("- Setas direcionais movimentam o Aviao.", FONT_DEFAULT);

	glRasterPos2f(220, 340);
	FuncoesAuxiliares::writeWord_BITMAP("- Barra de espaco Atira.", FONT_DEFAULT);

	glColor3f(1, 0.27, 0);

	glRasterPos2f(375, 250);
	FuncoesAuxiliares::writeWord_BITMAP("Barra de Espaco", GLUT_BITMAP_TIMES_ROMAN_24);

	glRasterPos2f(765, 250);
	FuncoesAuxiliares::writeWord_BITMAP("<-", GLUT_BITMAP_TIMES_ROMAN_24);

	glRasterPos2f(863, 250);
	FuncoesAuxiliares::writeWord_BITMAP("v", GLUT_BITMAP_TIMES_ROMAN_24);

	glRasterPos2f(935, 250);
	FuncoesAuxiliares::writeWord_BITMAP("->", GLUT_BITMAP_TIMES_ROMAN_24);

	glRasterPos2f(863, 327.5);
	FuncoesAuxiliares::writeWord_BITMAP("^", GLUT_BITMAP_TIMES_ROMAN_24);

	/*glRasterPos2f(205, 420);
	FuncoesAuxiliares::writeWord_BITMAP("- Barra de espaco atira!", FONT_DEFAULT);

	glRasterPos2f(205, 140);
	FuncoesAuxiliares::writeWord_BITMAP("Barra de espaco", FONT_DEFAULT);
*/
	glColor3f(1, 0.27, 0);
	/*--------------- BOXES COMANDOS -------------------*/
	glBegin(GL_LINE_LOOP);
	glVertex2i(220, 300); //Barra espaço
	glVertex2i(730, 300);
	glVertex2i(730, 220);
	glVertex2i(220, 220);
	glEnd();
	glBegin(GL_LINE_LOOP); //Seta esquerda
	glVertex2i(745, 300);
	glVertex2i(825, 300);
	glVertex2i(825, 220);
	glVertex2i(745, 220);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(830, 300); //Seta baixo
	glVertex2i(910, 300);
	glVertex2i(910, 220);
	glVertex2i(830, 220);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(915, 300); //Seta direita
	glVertex2i(995, 300);
	glVertex2i(995, 220);
	glVertex2i(915, 220);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(830, 385); //Seta cima
	glVertex2i(910, 385);
	glVertex2i(910, 305);
	glVertex2i(830, 305);
	glEnd();

	/*-------------- END COMANDOS SETAS ------------------*/

	if (atirou) {
		translacaoTiro += 40;
		if ((translacaoTiro > 700)) {
			atirou = false;
			translacaoTiro = 0;
		}
	}
	glPushMatrix();
	TiroSimples *tiro = new TiroSimples(1300, 400, 0.002);
	TiroSimples *tiro2 = new TiroSimples(1500, 400, 0.002);
	Spitfire *spitfire = new Spitfire(1400, 360, 0.015, nullptr);
	glTranslatef(translacaoOpcoesX, translacaoOpcoesY, 0);
	glPushMatrix();
	glTranslatef(0, translacaoTiro, 0);
	tiro->desenha();
	tiro2->desenha();
	glPopMatrix();
	spitfire->desenha();
	glPopMatrix();
}

#pragma endregion


void Menu::desenha() {

	pair<int, int> sizeScreen = EfeitoVisual::getInstance().getOrtho2D();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);

	//Desenha Linha Superior Y
	drawLine(sizeScreen.second - 40, 'y');
	//Desenha Linha Inferior Y
	drawLine(40, 'y');

	if (optMelhores) {//Tela Melhores Pontuações
		drawSquad(150, 600, "MELHORES PONTUACOES");
		// 5 Valores - Passar 80 por parametro
		// 7 Valores - Passar 55 por parametro
		// 10 Valores - Passar 37 por Parametro
		drawBestScoresMenu(Score::getInstance().getBestScore(7), 55);
	}
	else if (optOpcoes) {//Tela de Opções
		drawSquad(150, 600, "OPCOES");
		drawOpcoesMenu();
	}
	else if (optSair) {
		exit(1);
	}
	else {//Opções do Menu Inicial
		char *options[4];
		options[0] = "NOVO JOGO";
		options[1] = "MELHORES PONTUACOES";
		options[2] = "OPCOES";
		options[3] = "SAIR";
		drawOptionsMenu(options, 4, 450);
		drawTitulo();
		//Desenha Avião
		Spitfire *spitfire = new Spitfire(300, 380, 0.025, nullptr);
		glPushMatrix();

		//Movendo aviao do menu
		if (translacaoY < 500 && !limitX) {
			translacaoY += 4;
			if (translacaoY >= 500) {
				limitX = true;
			}

		}
		else if (limitX) {
			translacaoY -= 4;
			if (translacaoY <= 0) {
				limitX = false;
			}
		}
		glTranslatef(translacaoY, 0, 0);
		spitfire->desenha();
		glPopMatrix();
	}

	glutSwapBuffers();
}

void Menu::terminou()
{
	if (optSair)
	{
		Jogo::getInstance().setProxFase(-1);
		Jogo::getInstance().proximaFase();
	}
	else if (optIniciar)
	{
		Jogo::getInstance().setProxFase(1);
		Jogo::getInstance().proximaFase();
	}
}

void Menu::atualiza(int value) {

	//Testa se a fase acabou
	terminou();

	// Muda a direção quando chega na borda esquerda ou direita
	if (posX1 > windowWidth - POSrsize || posX1 < 0)
		xstep = -xstep;

	// Muda a direção quando chega na borda superior ou inferior
	if (PosY1 > windowHeight - POSrsize || PosY1 < 0)
		ystep = -ystep;

	// Verifica as bordas.  Se a window for menor e o 
	// quadrado sair do volume de visualização 
	if (posX1 > windowWidth - POSrsize)
		posX1 = windowWidth - POSrsize - 1;

	if (PosY1 > windowHeight - POSrsize)
		PosY1 = windowHeight - POSrsize - 1;

	// Move o quadrado
	posX1 += xstep;
	PosY1 += ystep;
}

void Menu::keyDown(unsigned char key, int x, int y)
{
}

void Menu::keyUp(unsigned char key, int x, int y)
{
	if (optMelhores) {

	}
	else if (optOpcoes) {
		switch (key) {
		case 32:
			atirou = true;
			break;
		}
	}
	else {
		switch (key) {
		case 'O'://Tela de Opções
		case 'o':
			EfeitoSonoro::getInstance().playEnterMenuEffect();
			optOpcoes = true;
			setaSelectOption = 2;
			break;

		case 13: //ENTER -> Iniciar Jogo
			switch (setaSelectOption)
			{
			case 1:
				EfeitoSonoro::getInstance().playEnterMenuEffect();
				optMelhores = true;
				break;
			case 2:
				EfeitoSonoro::getInstance().playEnterMenuEffect();
				optOpcoes = true;
				break;
			case 3:
				optSair = true;
			default:
				//EfeitoSonoro::getInstance().playEnterMenuEffect();
				//optIniciar = true;
				break;
			}
			break;

		case 'm': //Tela de Melhores Pontuações
		case 'M':
			EfeitoSonoro::getInstance().playEnterMenuEffect();
			optMelhores = true;
			setaSelectOption = 1;
			break;
		}
	}
	//Teclas Gerais
	switch (key)
	{
	case 8:
		optMelhores = false;
		optOpcoes = false;
		break;

	case 27: //Tecla ESC -> Sair do Jogo
		optSair = true;
		break;

	case 'f':
		EfeitoVisual::getInstance().setFullScreen();
		break;
	default:
		break;
	}

}

void Menu::specialKeyDown(int key, int x, int y)
{
	if (optOpcoes) {
		switch (key) {
		case GLUT_KEY_UP:
			if (translacaoOpcoesY < 100) {
				translacaoOpcoesY += 8;
			}
			break;
		case GLUT_KEY_DOWN:
			if (translacaoOpcoesY > -80) {
				translacaoOpcoesY -= 8;
			}
			break;
		case GLUT_KEY_LEFT:
			if (translacaoOpcoesX > -50) {
				translacaoOpcoesX -= 8;
			}
			break;
		case GLUT_KEY_RIGHT:
			if (translacaoOpcoesX < 150) {
				translacaoOpcoesX += 8;
			}
			break;
		}
	}
}

void Menu::specialKeyUp(int key, int x, int y)
{
	if (optMelhores) {

	}
	else if (optOpcoes) {

	}
	else {

		switch (key)
		{
		case GLUT_KEY_UP: //SETA CIMA
			if (setaSelectOption > 0) {
				setaSelectOption--;
				EfeitoSonoro::getInstance().playTransitioningMenuEffect();
			}
			break;
		case GLUT_KEY_DOWN: //SETA BAIXO
			if (setaSelectOption < 3) {
				setaSelectOption++;

				EfeitoSonoro::getInstance().playTransitioningMenuEffect();
			}
			break;
		default:
			break;
		}
	}
}

void Menu::mouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		cout << "Position: (" << x << "," << y << ")" << endl;

		if (optMelhores) {
			if ((x > 175 && x < 245) && (y > 450 && y < 510)) {
				optMelhores = false;
			}
		}
		else if (optOpcoes) {
			if ((x > 175 && x < 245) && (y > 450 && y < 510)) {
				optOpcoes = false;
			}
		}
		else {
			for (int i = 0; i < vetPosMenuElements.size(); i++) {
				float xInit = vetPosMenuElements[i].posInit_X;
				float xEnd = vetPosMenuElements[i].posEnd_X;
				float yInit = vetPosMenuElements[i].posInit_Y;
				float yEnd = vetPosMenuElements[i].posEnd_Y;
				if ((x >= xInit && x <= xEnd) && (y >= yInit && y <= yEnd)) {
					setaSelectOption = i;
					EfeitoSonoro::getInstance().playEnterMenuEffect();
					switch (i)
					{
					case 1:
						optMelhores = true;
						break;
					case 2:
						optOpcoes = true;
						break;
					case 3:
						optSair = true;
					}
				}
			}
		}
	}
}

// Inicializa parâmetros de rendering
void Menu::inicializa()
{
	//Transparencia
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//-------------
	//EfeitoSonoro::getInstance().playMainTheme();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
