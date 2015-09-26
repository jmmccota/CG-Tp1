#include <gl/glut.h>
#include <cstring>
#include <string>
#include <iostream>
#include "Score.h"
// Tamanho e posição inicial do quadrado
using namespace std;
GLfloat posX1 = 100.0f;
GLfloat PosY1 = 150.0f;
GLsizei POSrsize = 50;

// Tamanho do incremento nas direções x e y 
// (número de pixels para se mover a cada
// intervalo de tempo)
GLfloat xstep = 1.0f;
GLfloat ystep = 1.0f;

// Largura e altura da janela
GLfloat windowWidth;
GLfloat windowHeight;
bool fullscreen = false;
bool melhores = false;
bool opc = false;

// Função callback chamada para fazer o desenho
void Desenha(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);

#pragma region "Desenha o melhor Score"
	string best = "Best Score: ";
	glColor3f(0.4, 0.9, 1);
	glRasterPos2f(325, 237.5);
	for (int i = 0; i < 13;i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, best[i]);
	}

	Score bestScore = Score::getBestScore();
	string score = std::to_string(bestScore.getScore());

	glRasterPos2f(365, 237.5);
	for (int i = 0; i < score.length();i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, score[i]);
	}

	glColor3f(0.2, 0.6, 0.9);
	glLineWidth(3.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0, 239);
	glVertex2f(319, 239);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(0, 241);
	glVertex2f(319, 241);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(320, 240);
	glVertex2f(310, 247);
	glVertex2f(440, 247);
	glVertex2f(430, 240);
	glVertex2f(440, 233);
	glVertex2f(310, 233);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(432, 239);
	glVertex2f(500, 239);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glVertex2f(432, 241);
	glVertex2f(500, 241);
	glEnd();
#pragma endregion

	//Jiraiya
	string titulo = "JIRAIYA's FLY";
	glColor3f(0, 1.0, 1.0);
	glRasterPos2f(100, 180);
	for (int i = 0; i < 13; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, titulo[i]);
	}
	glColor3f(0, 1.0, 1.0);
	// Desenha o quadrado de fora(vermelho)
	glBegin(GL_LINE_LOOP);
	glVertex2i(50, 10);
	glVertex2i(390, 10);
	glVertex2i(390, 170);
	glVertex2i(50, 170);
	glEnd();
	if (opc) {
		//bloco para introdução
		glColor3f(0.0f, 0.0f, 1.0f);
		glBegin(GL_LINE_LOOP);
		glVertex2i(70, 155);
		glVertex2i(370, 155);
		glVertex2i(370, 105);
		glVertex2i(70, 105);
		glEnd();
		//colocar uma introduçao do jogo, falar que é pro aviao matar tudo
		string intro = "O objetivo do jogo e terminar as tres fases!";
		glColor3f(1.0, 1.0, 1.0);
		glRasterPos2f(80, 140);
		for (int i = 0; i < 44; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, intro[i]);
		}
		string intro2 = "Mate os 3 chefes e o maximo de inimigos possiveis!";
		glRasterPos2f(205, 140);
		for (int i = 0; i < 50; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, intro2[i]);
		}
		string intro4 = "A cada 10 mil pontos voce ganha uma vida. Caso perca todas, GAME OVER!";
		glRasterPos2f(80, 115);
		for (int i = 0; i < 70; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, intro4[i]);
		}
		/*string intro3 = "";
		glRasterPos2f(230, 115);
		for (int i = 0; i < 25; i++) {
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, intro3[i]);
		}*/

		//bloco movimentos

		string movi = "- Setas movimentam o aviao";
		glRasterPos2f(135, 83);
		for (int i = 0; i < 26; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, movi[i]);
		}
		string dir = "->";
		glRasterPos2f(120, 67);
		for (int i = 0; i < 2; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, dir[i]);
		}

		string esq = "<-";
		glRasterPos2f(84, 67);
		for (int i = 0; i < 2; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, esq[i]);
		}

		string up = "^";
		glRasterPos2f(104, 82);
		for (int i = 0; i < 1; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, up[i]);
		}
		string dow = "v";
		glRasterPos2f(104, 65);
		for (int i = 0; i < 1; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, dow[i]);
		}

		string ati = "- Barra de espaco atira!";
		glRasterPos2f(290, 83);
		for (int i = 0; i < 25; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ati[i]);
		}
		string esp = "Barra de espaco";
		glRasterPos2f(240, 66);
		for (int i = 0; i < 15; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, esp[i]);
		}

		glColor3f(0, 0, 1.0); //bloco movimentos
		glBegin(GL_LINE_LOOP);
		glVertex2i(70, 100);
		glVertex2i(370, 100);
		glVertex2i(370, 50);
		glVertex2i(70, 50);
		glEnd();
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINE_LOOP); //seta esquerda
		glVertex2i(80, 75);
		glVertex2i(95, 75);
		glVertex2i(95, 60);
		glVertex2i(80, 60);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex2i(98, 75); //seta baixo
		glVertex2i(113, 75);
		glVertex2i(113, 60);
		glVertex2i(98, 60);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex2i(116, 75); //seta direita
		glVertex2i(131, 75);
		glVertex2i(131, 60);
		glVertex2i(116, 60);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex2i(98, 93); //seta cima
		glVertex2i(113, 93);
		glVertex2i(113, 78);
		glVertex2i(98, 78);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glVertex2i(225, 75); //barra espaco
		glVertex2i(300, 75);
		glVertex2i(300, 60);
		glVertex2i(225, 60);
		glEnd();
		//bloco voltar
		glColor3f(0, 0, 1.0);
		glBegin(GL_LINE_LOOP);
		glVertex2i(190, 45);
		glVertex2i(240, 45);
		glVertex2i(240, 15);
		glVertex2i(190, 15);
		glEnd();
		glColor3f(0, 1.0, 1.0);
		string voltar = "Voltar";
		glRasterPos2f(205, 25);
		for (int i = 0; i < 6; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, voltar[i]);
		}
		//fazer 4 quadradinhos com setas para falar de cada movimento
		//falar que espaço atira????
		//botão de voltar
	}
	else if (melhores) {
		//colocar número de 1 até 5 e um traço "-"
		//de inicio por .... nos nomes, mas fazer o arquivo pra ler(futuramente)
		//colocar botão de limpar
		//colocar botão de atirar
	}
	else {
		string start = "Iniciar";
		glColor3f(0, 1.0, 1.0);
		glRasterPos2f(153, 135);
		for (int i = 0; i < 7; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, start[i]);
		}
		string opt = "Opcoes";
		glColor3f(0, 1.0, 1.0);
		glRasterPos2f(151, 102);
		for (int i = 0; i < 6; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, opt[i]);
		}
		string mel = "Melhores Pontuacoes";
		glColor3f(0, 1.0, 1.0);
		glRasterPos2f(130, 67);
		for (int i = 0; i < 19; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mel[i]);
		}
		string sai = "Sair";
		glColor3f(0, 1.0, 1.0);
		glRasterPos2f(158, 33);
		for (int i = 0; i < 4; i++) {
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, sai[i]);
		}

		glBegin(GL_LINE_LOOP); //outro quadrado vermelho com nome do trabalho e grupo???
		glVertex2i(270, 155);
		glVertex2i(380, 155);
		glVertex2i(380, 20);
		glVertex2i(270, 20);
		glEnd();
		// Especifica que a cor corrente é azul
		glColor3f(0.0f, 0.0f, 1.0f);
		//glVertex2i(GLint(x1 + rsize), GLint(y1));
		//glVertex2i(GLint(x1 + rsize), GLint(y1 + rsize));
		//desenha o quadrado dos botoes
		glBegin(GL_LINE_LOOP); //iniciar
		glVertex2i(70, 155);
		glVertex2i(260, 155);
		glVertex2i(260, 125);
		glVertex2i(70, 125);
		glEnd();
		glBegin(GL_LINE_LOOP); //opcoes
		glVertex2i(70, 120);
		glVertex2i(260, 120);
		glVertex2i(260, 90);
		glVertex2i(70, 90);
		glEnd();
		glBegin(GL_LINE_LOOP); //melhores
		glVertex2i(70, 85);
		glVertex2i(260, 85);
		glVertex2i(260, 55);
		glVertex2i(70, 55);
		glEnd();
		glBegin(GL_LINE_LOOP); //sair
		glVertex2i(70, 50);
		glVertex2i(260, 50);
		glVertex2i(260, 20);
		glVertex2i(70, 20);
		glEnd();
	}

	//LEMBRAR DE MUDAR TUDO PRA VARIAVEIS, PRA QUANDO COLOCAR EM FULLSCREEN !!!!!!!!!!
	// Executa os comandos OpenGL
	glutSwapBuffers();
}

// Função callback chamada pela GLUT a cada intervalo de tempo
// (a window não está sendo redimensionada ou movida)
void Timer(int value)
{
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

	// Redesenha o quadrado com as novas coordenadas 
	glutPostRedisplay();
	glutTimerFunc(33, Timer, 1);
}

// Inicializa parâmetros de rendering
void Inicializa(void)
{
	// Define a cor de fundo da janela de visualização como preta
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Função callback chamada quando o tamanho da janela é alterado 
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Evita a divisao por zero
	if (h == 0) h = 1;

	// Especifica as dimensões da Viewport
	glViewport(0, 0, w, h);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (left, right, bottom, top)     
	if (w <= h) {
		windowHeight = 250.0f*h / w;
		windowWidth = 250.0f;
	}
	else {
		windowWidth = 250.0f*w / h;
		windowHeight = 250.0f;
	}

	gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}
void keyboardDown(unsigned char key, int x, int y) {
	if (opc) {
		switch (key) {
		case 8:
			cout << "Voltar Opcoes";//ir pro menu de função		
			opc = false;
			break;
		case 'f':
			if (!fullscreen) {
				fullscreen = true;
				glutFullScreen();
			}
			else {
				fullscreen = false;
				glutReshapeWindow(1280, 720);
				glutInitWindowPosition((GetSystemMetrics(SM_CXSCREEN) - 1280) / 2, (GetSystemMetrics(SM_CYSCREEN) - 720) / 2);
			}
			//fullscreen
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
			if (!fullscreen) {
				fullscreen = true;
				glutFullScreen();
			}
			else {
				fullscreen = false;
				glutReshapeWindow(1280, 720);
				glutInitWindowPosition((GetSystemMetrics(SM_CXSCREEN) - 1280) / 2, (GetSystemMetrics(SM_CYSCREEN) - 720) / 2);
			}
			//fullscreen
			break;
		}
	}
	else if (!melhores && !opc) {
		switch (key) {
		case 'O':
			cout << "Opcoes";//ir pro menu de função		
			opc = true;
			break;
		case 'o':
			cout << "Opcoes";//ir pro menu de função
			opc = true;
			break;
		case 13:
			cout << "Iniciar";//ENTER -> ir pro jogo	
			break;
		case  27:
			cout << "Sair";// ESC-> sair do jogo
			exit(0);
			break;
		case 'm':
			cout << "melhores";//ir para melhores pontuaçoes
			melhores = true;
			break;
		case 'M':
			cout << "melhores";//ir para melhores pontuaçoes
			melhores = true;
			break;
		case 'f':
			if (!fullscreen) {
				fullscreen = true;
				glutFullScreen();
			}
			else {
				fullscreen = false;
				glutReshapeWindow(1280, 720);
				glutInitWindowPosition((GetSystemMetrics(SM_CXSCREEN) - 1280) / 2, (GetSystemMetrics(SM_CYSCREEN) - 720) / 2);
			}
			//fullscreen
			break;
			//exit(0);
		}
	}

}
void keyboardUp(unsigned char key, int x, int y) {

}
void mouseClick(int button, int state, int x, int y) {
	//cout << "Iniciar";
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {


		cout << "pos: " << x << "," << y << endl;
		//cout <<"wx: "<< windowWidth-x << "," << windowHeight-y << endl;	
		if (fullscreen) {
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
						exit(0);
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
				//melhores = false;
			}
			else {
				if (x >= 203 && x <= 750) {
					if (y >= 274 && y <= 360) {
						//começar jogo
						cout << "Iniciar";
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
						exit(0);
					}
				}
			}
		}

	}
}
void idle() {
	Desenha();
}
// Programa Principal 
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1280, 720);
	glutInitWindowPosition((GetSystemMetrics(SM_CXSCREEN) - 1280) / 2, (GetSystemMetrics(SM_CYSCREEN) - 720) / 2);
	glutCreateWindow("Animação");
	glutMouseFunc(mouseClick);
	glutKeyboardFunc(keyboardDown);
	glutKeyboardUpFunc(keyboardUp);
	glutDisplayFunc(Desenha);
	glutIdleFunc(idle);
	glutReshapeFunc(AlteraTamanhoJanela);
	//glutTimerFunc(33, Timer, 1);
	Inicializa();
	glutMainLoop();

	return 0;
}