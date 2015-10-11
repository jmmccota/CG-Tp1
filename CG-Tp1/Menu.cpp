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

//Desenha uma Linha - Parametro: posição em relação ao eixo Y
void drawLine(float posY) {
	glColor3f(0, 1.0, 0.9);
	glLineWidth(3.0f);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.0, posY);
	glVertex2f(EfeitoVisual::getInstance().getOrtho2D().first, posY);
	glEnd();
}

//Desenha as Opções Dinamicamente - Parametros: options, quantidade de Opções
void drawOptionsMenu(char *options[], int quantOptions) {

	//Limpa vetor de posições de elementos do menu
	if (vetPosMenuElements.size() > 0) {
		vetPosMenuElements.clear();
	}

	pair<int, int> ortho = EfeitoVisual::getInstance().getOrtho2D();
	float rasterX = 1200;
	float rasterY = 600;

	//Escreve na tela
	for (int pos = 0; pos < quantOptions; pos++) {
		glColor3f(0, 1.0, 0.9);

		string titulo = options[pos];
		if (EfeitoVisual::getInstance().isFullScreen()) {
			glRasterPos2f(rasterX - (titulo.length() * 5) + 251, rasterY - 10);
		}
		else {
			glRasterPos2f(rasterX - (titulo.length() * 10) + 251, rasterY - 10);
		}
		for (int i = 0; i < titulo.length(); i++) {
			glutBitmapCharacter(FONT_DEFAULT, titulo[i]);
		}

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

//Desenha Quadrado para Opções - Paremetros: Posição x, Posição Y, Titulo 
void drawSquad(float posX, float posY, string titulo) {

	pair<float, float> fullHD = EfeitoVisual::getInstance().getOrtho2D();
	float rasterX = fullHD.first - posX;
	float rasterY = 190;

	if (EfeitoVisual::getInstance().isFullScreen()) {
		glRasterPos2f(posX - (titulo.length() * 5) + ((rasterX - posX) / 2), posY - 10);
	}
	else {
		glRasterPos2f(posX - (titulo.length() * 10) + ((rasterX - posX) / 2), posY - 10);

	}

	for (int i = 0; i < titulo.length(); i++) {
		glutBitmapCharacter(FONT_DEFAULT, titulo[i]);
	}

	//-------------------- BEGIN BOXES DE BESTSCORES ---------------------
	glColor3f(0, 1.0, 0.9);
	glLineWidth(2.0f);
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
	//-------------------- END BOXES DE BESTSCORES ---------------------
}

//Desenha Melhores Scores - Parametros: bests, quantidade de melhores pontuações
void drawBestScores(char *bests[], int quantBests) {

}

#pragma endregion

void Menu::desenha() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);


	//Desenha Linha Superior
	drawLine(1000);

	if (optMelhores) {//Tela Melhores Pontuações
		drawSquad(150, 600, "MELHORES PONTUACOES");
	}
	else if (optOpcoes) {//Tela de Opções
		drawSquad(150, 600, "OPCOES");
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
		drawOptionsMenu(options, 4);

		//Desenha Avião
		Spitfire *spitfire = new Spitfire(500, 500, 0.025, nullptr);
		glPushMatrix();
		//movendo aviao do menu
		if (translacaoY < 900){
			translacaoY += 8;
		}
		else{
			translacaoY = -700;
		}
		glTranslatef(0, translacaoY, 0);
		spitfire->desenha();
		glPopMatrix();
	}


	glutSwapBuffers();
}

void Menu::terminou()
{
	if (optSair)
	{
		cout << "terminou\n";
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
	switch (key) {
	case 27: //Tecla ESC -> Sair do Jogo
		optSair = true;
		break;
	case 'f':
		EfeitoVisual::getInstance().setFullScreen();
		break;
	}
}
void Menu::keyUp(unsigned char key, int x, int y)
{
}
void Menu::specialKeyDown(int key, int x, int y)
{

}
void Menu::specialKeyUp(int key, int x, int y)
{

}
void Menu::mouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		cout << "Position: (" << x << "," << y << ")" << endl;

		for (int i = 0; i < vetPosMenuElements.size(); i++) {
			float xInit = vetPosMenuElements[i].posInit_X;
			float xEnd = vetPosMenuElements[i].posEnd_X;
			float yInit = vetPosMenuElements[i].posInit_Y;
			float yEnd = vetPosMenuElements[i].posEnd_Y;
			if ((x >= xInit && x <= xEnd) && (y >= yInit && y <= yEnd)) {
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


// Inicializa parâmetros de rendering
void Menu::inicializa()
{
	//EfeitoSonoro::getInstance().playMainTheme();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
