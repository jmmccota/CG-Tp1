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
//translacao bomba menu opcoes
GLfloat translacaoBomba = 0.0f;
//translacao tiro menu opcoes
GLfloat translacaoTiro = 0.0f;
// translacao tiro menu
GLfloat translacaoTiro2 = 0.0f;
// boolean para atirar do menu de opcoes
boolean atirou = false;
// boolean para bombardear do menu de opcoes
boolean bombardeou = false;
// boolean para atirar menu
boolean atirou2 = false;
float xFixo = 0;

//Desenha uma Linha - Parametro: posição em relação ao eixo Y
void drawLine(float pos, char eixo) {

	pair<int, int> size = EfeitoVisual::getInstance().getOrtho2D();

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
	//Desenha Seta para Volta
	glColor3f(1, 0.27, 0);
	glBegin(GL_LINE_LOOP);
	glVertex2i(200, 580);
	glVertex2i(175, 550);
	glVertex2i(200, 520);
	glVertex2i(200, 540);
	glVertex2i(245, 540);
	glVertex2i(245, 560);
	glVertex2i(200, 560);
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
	int rasterY = 460;
	pair<int, int> sizeScreen = EfeitoVisual::getInstance().sizeScreen();
	glColor3f(0.93, 0.57, 0.13);
	string bestName;
	for (int i = 0; i < bestScores.size(); i++) {
		glRasterPos2f(rasterX - 50, rasterY);
		string rank = std::to_string(i + 1) + " -  ";
		FuncoesAuxiliares::writeWord_BITMAP(rank, FONT_DEFAULT);

		string name = bestScores[i].getPlayer();
		if (i == 0) {
			bestName = name;
		}
		glRasterPos2f(rasterX, rasterY);
		FuncoesAuxiliares::writeWord_BITMAP(name, FONT_DEFAULT);

		string score = std::to_string(bestScores[i].getScoreValue());
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
	glColor3f(0.93, 0.57, 0.13);
	int x = 1470, x1 = 1520, y = 480, y1 = 280;
	EfeitoVisual::getInstance().desenhaQuadrado(x, y, x1, y1);
	EfeitoVisual::getInstance().desenhaQuadrado(x - 30, y, x1, y - 50);
	EfeitoVisual::getInstance().desenhaQuadrado(x - 50, y1 + 20, x1 + 50, y1 - 20);
	glRasterPos2f(x - 40, y1 - 60);
	FuncoesAuxiliares::writeWord_BITMAP(bestName, FONT_DEFAULT);
}

//Desenha a Opção do Menu 
void drawOpcoesMenu() {

	int rasterY = 480;
	glColor3f(1, 1, 1);

	glRasterPos2f(200, rasterY);
	FuncoesAuxiliares::writeWord_BITMAP("O objetivo do jogo e terminar as 3 fases. Mate os 3 chefes e o maximo de inimigos possiveis!", FONT_DEFAULT);

	glRasterPos2f(200, rasterY - 40);
	FuncoesAuxiliares::writeWord_BITMAP("A cada 10 mil pontos voce ganha uma vida.Caso perca todas, GAME OVER!", FONT_DEFAULT);

	glRasterPos2f(200, rasterY - 80);
	FuncoesAuxiliares::writeWord_BITMAP("Comandos:", FONT_DEFAULT);

	glRasterPos2f(220, rasterY - 120);
	FuncoesAuxiliares::writeWord_BITMAP("- Setas direcionais movimentam o Aviao.", FONT_DEFAULT);

	glRasterPos2f(220, rasterY - 160);
	FuncoesAuxiliares::writeWord_BITMAP("- Z(tiro simples) e X(bomba) atiram.", FONT_DEFAULT);
	glRasterPos2f(220, rasterY - 200);
	FuncoesAuxiliares::writeWord_BITMAP("- F para modo FullScreen e P para pausar.", FONT_DEFAULT);

	glColor3f(1, 0.27, 0);

	glRasterPos2f(280, 195);
	FuncoesAuxiliares::writeWord_BITMAP("Z", GLUT_BITMAP_TIMES_ROMAN_24);
	glRasterPos2f(377.5, 195);
	FuncoesAuxiliares::writeWord_BITMAP("X", GLUT_BITMAP_TIMES_ROMAN_24);
	glRasterPos2f(480, 195);
	FuncoesAuxiliares::writeWord_BITMAP("F", GLUT_BITMAP_TIMES_ROMAN_24);
	glRasterPos2f(580, 195);
	FuncoesAuxiliares::writeWord_BITMAP("P", GLUT_BITMAP_TIMES_ROMAN_24);

	glRasterPos2f(765, 195);
	FuncoesAuxiliares::writeWord_BITMAP("<-", GLUT_BITMAP_TIMES_ROMAN_24);

	glRasterPos2f(863, 195);
	FuncoesAuxiliares::writeWord_BITMAP("v", GLUT_BITMAP_TIMES_ROMAN_24);

	glRasterPos2f(935, 195);
	FuncoesAuxiliares::writeWord_BITMAP("->", GLUT_BITMAP_TIMES_ROMAN_24);

	glRasterPos2f(863, 267.5);
	FuncoesAuxiliares::writeWord_BITMAP("^", GLUT_BITMAP_TIMES_ROMAN_24);

	glColor3f(1, 0.27, 0);
	/*--------------- BOXES COMANDOS -------------------*/
	//glBegin(GL_LINE_LOOP);
	//glVertex2i(220, 260); //Barra espaço
	//glVertex2i(730, 260);
	//glVertex2i(730, 180);
	//glVertex2i(220, 180);
	//glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(250, 250); //Z
	glVertex2i(330, 250);
	glVertex2i(330, 170);
	glVertex2i(250, 170);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(350, 250); //X
	glVertex2i(430, 250);
	glVertex2i(430, 170);
	glVertex2i(350, 170);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(450, 250); //F
	glVertex2i(530, 250);
	glVertex2i(530, 170);
	glVertex2i(450, 170);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(550, 250); //P
	glVertex2i(630, 250);
	glVertex2i(630, 170);
	glVertex2i(550, 170);
	glEnd();
	
	glBegin(GL_LINE_LOOP); //Seta esquerda
	glVertex2i(745, 250);
	glVertex2i(825, 250);
	glVertex2i(825, 170);
	glVertex2i(745, 170);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(830, 250); //Seta baixo
	glVertex2i(910, 250);
	glVertex2i(910, 170);
	glVertex2i(830, 170);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(915, 250); //Seta direita
	glVertex2i(995, 250);
	glVertex2i(995, 170);
	glVertex2i(915, 170);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(830, 325); //Seta cima
	glVertex2i(910, 325);
	glVertex2i(910, 245);
	glVertex2i(830, 245);
	glEnd();

	/*-------------- END COMANDOS SETAS ------------------*/

	if (atirou) {
		translacaoTiro += 100;
		if ((translacaoTiro > 700)) {
			atirou = false;
			translacaoTiro = 0;
		}
	}
	if (bombardeou) {
		translacaoBomba += 10;
		if ((translacaoBomba > 700)) {
			bombardeou = false;
			translacaoBomba = 0;
		}
	}
	glPushMatrix();
	TiroSimples *tiro = new TiroSimples(1300, 400, 0.002);
	TiroSimples *tiro2 = new TiroSimples(1500, 400, 0.002);
	Spitfire *spitfire = new Spitfire(1400, 360, 0.015, nullptr);
	Bomba *bomba = new Bomba(1400, 360, 0.003);
	
	glPushMatrix();
	glTranslatef(translacaoOpcoesX, translacaoOpcoesY, 0);
	glPushMatrix();
	glTranslatef(0, translacaoTiro, 0);
	tiro->desenha();
	tiro2->desenha();
	glPopMatrix();
	glPushMatrix();
	
	glTranslatef(0, translacaoBomba, 0);
	bomba->desenha();
	glPopMatrix();
	glPopMatrix();
	glTranslatef(translacaoOpcoesX, translacaoOpcoesY, 0);
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
		EfeitoVisual::getInstance().desenhaTitulo(600, 65);
		drawSquad(150, 550, "MELHORES PONTUACOES");
		// 5 Valores - Passar 80 por parametro
		// 7 Valores - Passar 47 por parametro
		// 10 Valores - Passar 30 por Parametro
		drawBestScoresMenu(Score::getBestScore(7), 47);
	}
	else if (optOpcoes) {//Tela de Opções
		EfeitoVisual::getInstance().desenhaTitulo(600, 65);
		drawSquad(150, 550, "OPCOES");
		drawOpcoesMenu();
	}
	else if (optSair) {
		exit(1);
	}
	else {//Opções do Menu Inicial
		EfeitoVisual::getInstance().desenhaTitulo(1100, 0);

		char *options[4];
		options[0] = "NOVO JOGO";
		options[1] = "MELHORES PONTUACOES";
		options[2] = "OPCOES";
		options[3] = "SAIR";
		drawOptionsMenu(options, 4, 450);
		//Desenha Avião
		TiroSimples *municao1 = new TiroSimples(360, 690, 0.002);
		TiroSimples *municao2 = new TiroSimples(560, 690, 0.002);
		Spitfire *spitfire = new Spitfire(460, 530, 0.045, nullptr);
		glPushMatrix();

		//Movendo aviao do menu
		if (translacaoY < 190 && !limitX) {
			translacaoY += 4;
			if (translacaoY >= 190) {
				limitX = true;
			}

		}
		else if (limitX) {
			translacaoY -= 4;
			if (translacaoY <= 0) {
				limitX = false;
			}
		}
		//comenta daki
		glTranslatef(translacaoY, 0, 0);
		glPushMatrix();
		glTranslatef(0, translacaoTiro2, 0);
		municao1->desenha();
		municao2->desenha();
		glPopMatrix();
		spitfire->desenha();
		glPopMatrix();
		//ate aqui

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
		EfeitoSonoro::getInstance().finishAllAudios();
		optIniciar = false;
		Jogo::getInstance().setProxFase(2);
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
	if (translacaoY == 100 || translacaoY == 400) {
		atirou2 = true;
	}
	if (atirou2) {
		translacaoTiro2 += 20;
		if (translacaoTiro2 == 600) {
			atirou2 = false;
			translacaoTiro2 = 0;
		}
	}

#pragma region "Código Desenha do Daniel *-*"
	if (macete == "billgay") {
		EfeitoSonoro::getInstance().playStreamAudio("audio/sfx/owaw.mp3");
		Jogo::getInstance().numeroVidas = 999999;
		macete = "";
	}
	else if (macete == "daniball") {
		EfeitoSonoro::getInstance().playStreamAudio("audio/sfx/owaw.mp3");
		Jogo::getInstance().score->setScoreValue(100000);
		macete = "";
	}

#pragma endregion
}

void Menu::keyDown(unsigned char key, int x, int y)
{
}
void Menu::desenhaHUD(int hp)
{
}
void Menu::desenhaNumeroVidas(int numeroVidas) {

}
void Menu::writeScore(int score) {

}
void Menu::keyUp(unsigned char key, int x, int y)
{
	if (optMelhores) {

	}
	else if (optOpcoes) {
		switch (key) {
		case 'z':
			atirou = true;
			break;
		case 'x':
			bombardeou= true;
			break;
		}
	}
	else {
		switch (key) {
		case 'O'://Tela de Opções
		case 'o':
			EfeitoSonoro::getInstance().playEnterMenu();
			optOpcoes = true;
			setaSelectOption = 2;
			break;

		case 13: //ENTER -> Iniciar Jogo
			switch (setaSelectOption)
			{
			case 1:
				EfeitoSonoro::getInstance().playEnterMenu();
				optMelhores = true;
				break;
			case 2:
				EfeitoSonoro::getInstance().playEnterMenu();
				optOpcoes = true;
				break;
			case 3:
				optSair = true;
			default:
				EfeitoSonoro::getInstance().playEnterMenu();
				optIniciar = true;
				break;
			}
			break;

		case 'm': //Tela de Melhores Pontuações
		case 'M':
			EfeitoSonoro::getInstance().playEnterMenu();
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
	case 'F':
	case 'f':
		EfeitoVisual::getInstance().setFullScreen();
		break;
	default:
		macete += (char)key;
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
				EfeitoSonoro::getInstance().playTransitioningMenu();
			}
			break;
		case GLUT_KEY_DOWN: //SETA BAIXO
			if (setaSelectOption < 3) {
				setaSelectOption++;

				EfeitoSonoro::getInstance().playTransitioningMenu();
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
			if ((x > 175 && x < 245) && (y > 500 && y < 560)) {
				optMelhores = false;
			}
		}
		else if (optOpcoes) {
			if ((x > 175 && x < 245) && (y > 500 && y < 560)) {
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
					EfeitoSonoro::getInstance().playEnterMenu();
					switch (i)
					{
					case 0:
						optIniciar = true;
						break;
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
	EfeitoSonoro::getInstance().initAudios_Menu();
	EfeitoSonoro::getInstance().playMainTheme();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
