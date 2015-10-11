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
int telaAtual = 0;
/* ---------------------- Variavel inteira de FLAG para TELA de MENU ---------------------------

		telaAtual = 0 -> Tela do Menu Inicial
			//    = 1 -> Tela de Melhores Pontuação
			//    = 2 -> Tela de Opções
			//    = 3 -> Sair

----------------------------------------------------------------------------------------------*/

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

	pair<int, int> sizeS = EfeitoVisual::getInstance().sizeScreen();
	float rasterX = 1200;
	float rasterY = 550;

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
		glVertex2f(rasterX + 588.8888889, rasterY + 35.5555556);
		glVertex2f(rasterX + 593.3333333, rasterY + 31.1111111);
		glVertex2f(rasterX + 596.6666667, rasterY + 24.4444444);
		glVertex2f(rasterX + 598.8888889, rasterY + 13.3333333);
		glVertex2f(rasterX + 600, rasterY + 0.1111111);
		glVertex2f(rasterX + 600, rasterY - 0.1111111);
		glVertex2f(rasterX + 598.8888889, rasterY - 13.3333333);
		glVertex2f(rasterX + 596.6666667, rasterY - 24.4444444);
		glVertex2f(rasterX + 593.3333333, rasterY - 31.1111111);
		glVertex2f(rasterX + 588.8888889, rasterY - 35.5555556);
		glVertex2f(rasterX - 88.8888889, rasterY - 35.5555556);
		glVertex2f(rasterX - 93.3333333, rasterY - 31.1111111);
		glVertex2f(rasterX - 96.6666667, rasterY - 24.4444444);
		glVertex2f(rasterX - 98.8888889, rasterY - 13.3333333);
		glVertex2f(rasterX - 100, rasterY - 0.1111111);
		glVertex2f(rasterX - 100, rasterY + 0.1111111);
		glVertex2f(rasterX - 98.8888889, rasterY + 13.3333333);
		glVertex2f(rasterX - 96.6666667, rasterY + 24.4444444);
		glVertex2f(rasterX - 93.3333333, rasterY + 31.1111111);
		glVertex2f(rasterX - 88.8888889, rasterY + 35.5555556);
		glEnd();
		//---------------------- END BOXES DE OPÇÕES ----------------------

        PositionMenuElement pElement;
        pElement.posInit_X = rasterX - 100;
        pElement.posEnd_X = rasterX + 600;
        pElement.posInit_Y = rasterY - 160;
        pElement.posEnd_Y = rasterY - 85;

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

	switch (telaAtual)
	{
	case 1: //Tela Melhores Pontuações
		drawSquad(150, 600, "MELHORES PONTUACOES");
		break;
	case 2: //Tela de Opções
		drawSquad(150, 600, "OPCOES");
		break;
	case 3: //Sair
		exit(1);
		break;
	default: //Opções do Menu Inicial
		char *options[4];
		options[0] = "NOVO JOGO";
		options[1] = "MELHORES PONTUACOES";
		options[2] = "OPCOES";
		options[3] = "SAIR";
		drawOptionsMenu(options, 4);

		//Desenha Avião
		Spitfire *spitfire = new Spitfire(500, 500, 0.025, nullptr);
		spitfire->desenha();

		break;
	}

	glutSwapBuffers();
}

void Menu::terminou()
{
	if (saiu)
	{
		cout << "terminou\n";
		Jogo::getInstance().setProxFase(-1);
		Jogo::getInstance().proximaFase();
	}
	else if (comecou)
	{
		Jogo::getInstance().setProxFase(1);
		Jogo::getInstance().proximaFase();
	}
}

void Menu::atualiza(int value) {

	//Testa se a fase acabou
	terminou();

    if (melhores)
        telaAtual = 1;
    else if (opc)
        telaAtual = 2;
    else
        telaAtual = 0;

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
	if (opc) {
		switch (key) {
		    case 8:
			    cout << "Voltar Opcoes";//ir pro menu de função		
			    opc = false;
			    break;
		    case 'f':
			    EfeitoVisual::getInstance().setFullScreen();
			    break;
		    }
	}
    else if (melhores) {
		switch (key) {
		    case 8:
			    cout << "Voltar Melhores";//ir pro menu de função		
			    melhores = false;
			    break;
		    case 'f':
			    EfeitoVisual::getInstance().setFullScreen();
			    break;
		}
	}
	else if (!melhores && !opc) {
		switch (key) {
		    case 'O':
		    case 'o':
			    cout << "Opcoes";//ir pro menu de função		
			    opc = true;
			    break;
		    case 13:
			    cout << "Iniciar";//ENTER -> ir pro jogo
			    comecou = true;
			    break;
		    case  27:
			    cout << "Sair";// ESC-> sair do jogo
			    saiu = true;
			    break;
		    case 'M':
		    case 'm':
			    cout << "melhores";//ir para melhores pontuaçoes
			    melhores = true;
			    break;
		    case 'f':
			    EfeitoVisual::getInstance().setFullScreen();
			    break;
		}
	}
}
void Menu::keyUp(unsigned char key, int x, int y)
{
}
void Menu::mouse(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		cout << "Position: (" << x << "," << y << ")" << endl;

        for (int i = 0; i < vetPosMenuElements.size(); i++) {
            PositionMenuElement p = vetPosMenuElements[i];
            if ((x >= p.posInit_X && x <= p.posEnd_X) && (y >= p.posInit_Y && y <= p.posEnd_Y)) {
                switch (i)
                {
                    case 1:
                        melhores = true;
                        break;
                    case 2:
                        opc = true;
                        break;
                    case 3:
                        saiu = true;
                }
                return;
			}
		}
	}



}


// Inicializa parâmetros de rendering
void Menu::inicializa()
{
	EfeitoSonoro::getInstance().playMainTheme();
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
