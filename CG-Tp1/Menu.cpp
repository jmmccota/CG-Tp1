#include "Menu.hpp"
#define FONT_DEFAULT GLUT_BITMAP_TIMES_ROMAN_24


Menu::Menu() {
}

Menu::~Menu() {
	Fase::~Fase();
}

void Menu::definePersonagens() {
}

void Menu::desenhaBackground() {
}

void drawOptionsMenu(char *options[], int quantOptions) {

	float rasterX = 1920;
	float rasterY = 600;

#pragma region Boxes
	glBegin(GL_LINE_LOOP);
	glVertex2f(1920, 900);
	glVertex2f(0, 900);
	glEnd();

#pragma endregion
//	//Escreve na tela
//	for (int pos = 0; pos < quantOptions; pos++) {
//		string titulo = options[pos];
//		glColor3f(0, 1.0, 1.0);
//		glRasterPos2f(rasterX, rasterY);
//		for (int i = 0; i < titulo.length(); i++) {
//			glutBitmapCharacter(FONT_DEFAULT, titulo[i]);
//		}
//#pragma region Boxes
//		glBegin(GL_LINE_LOOP);
//		glVertex2f(1920, 900);
//		glVertex2f(0, 900);
//		glEnd();
//
//#pragma endregion
//
//
//		rasterY -= 130;
//	}
}

void Menu::desenha() {

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//Opções do Menu
	char *options[4];
	options[0] = "NOVO JOGO";
	options[1] = "MELHORES PONTUACOES";
	options[2] = "OPCOES";
	options[3] = "SAIR";

	drawOptionsMenu(options, 4);

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
			//exit(0);
		}
	}
}
void Menu::keyUp(unsigned char key, int x, int y)
{
}
void Menu::mouse(int button, int state, int x, int y) {
	//cout << "Iniciar";
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {


		cout << "pos: " << x << "," << y << endl;
		//cout <<"wx: "<< windowWidth-x << "," << windowHeight-y << endl;	
		if (EfeitoVisual::getInstance().isFullScreen()) {
			if (opc) {
				//se clicar em voltar opc=false
				cout << "Mostrar opcoes";
				//585 630
				//737 720
				if (x >= 585 && x <= 737) {
					if (y >= 630 && y <= 720) {
						opc = false;
					}
				}
				//opc = false;
			}
			else if (melhores) {
				//se clicar em voltar melhores=false
				cout << "Mostrar melhores";
				//melhores = false;
			}
			else {
				if (x >= 216 && x <= 797) {
					if (y >= 291 && y <= 381) {
						//começar jogo
						cout << "Iniciar";
						comecou = true;
					}
					else if (y >= 398 && y <= 492) {
						cout << "Opcoes";
						//chamar opcoes
						opc = true;
					}
					else if (y >= 506 && y <= 598) {
						cout << "Melhores";
						//chamar melhores
						melhores = true;
					}
					else if (y >= 615 && y <= 704) {
						cout << "Sair";
						saiu = true;
						//fechar tudo
					}
				}
			}
		}
		else {
			if (opc) {
				//se clicar em voltar opc=false
				cout << "Mostrar opcoes";
				//opc = false;
				//548 591
				//690 675
				if (x >= 548 && x <= 690) {
					if (y >= 591 && y <= 675) {
						opc = false;
					}
				}
			}
			else if (melhores) {
				//se clicar em voltar melhores=false
				cout << "Mostrar melhores";
				melhores = false;
				//melhores = false;
			}
			else {
				if (x >= 203 && x <= 750) {
					if (y >= 274 && y <= 360) {
						//começar jogo
						cout << "Iniciar";
						comecou = true;
					}
					else if (y >= 375 && y <= 462) {
						cout << "Opcoes";
						opc = true;
					}
					else if (y >= 476 && y <= 562) {
						cout << "Melhores";
						melhores = true;
					}
					else if (y >= 577 && y <= 662) {
						cout << "Sair";
						saiu = true;
					}
				}
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
