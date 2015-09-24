#include <gl/glut.h>
#include <cstring>
#include <string>
#include <iostream>
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
bool fullscreen=false;

// Função callback chamada para fazer o desenho
void Desenha(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Limpa a janela de visualização com a cor de fundo especificada
	glClear(GL_COLOR_BUFFER_BIT);

	// Especifica que a cor corrente é vermelha
	//         R     G     B
	//Jiraiya
	string titulo = "JIRAIYA's FLY";
	glColor3f(1.0,0,0);
	glRasterPos2f(100, 180);
	for (int i = 0; i < 13;i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,titulo[i]);
	}
	string start = "Iniciar";
	glColor3f(1.0, 0, 0);
	glRasterPos2f(153, 135);
	for (int i = 0; i < 7; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, start[i]);
	}
	string opt = "Opcoes";
	glColor3f(1.0, 0, 0);
	glRasterPos2f(151, 102);
	for (int i = 0; i < 6; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, opt[i]);
	}
	string mel = "Melhores Pontuacoes";
	glColor3f(1.0, 0, 0);
	glRasterPos2f(130, 67);
	for (int i = 0; i < 19; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mel[i]);
	}
	string sai = "Sair";
	glColor3f(1.0, 0, 0);
	glRasterPos2f(158, 33);
	for (int i = 0; i < 4; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, sai[i]);
	}
	glColor3f(1.0f, 0.0f, 0.0f);
	// Desenha o quadrado de fora(vermelho)
	glBegin(GL_LINE_LOOP);
	glVertex2i(50,10);
	glVertex2i(390,10);
	glVertex2i(390,170);
	glVertex2i(50,170);
	glEnd();
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
	glVertex2i(70,155);
	glVertex2i(260,155);
	glVertex2i(260,125);
	glVertex2i(70,125);
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

	switch (key) {
		case 'O': 
			cout << "Opcoes";//ir pro menu de função		
			break;
		case 'o': 
			cout << "Opcoes";//ir pro menu de função
			break;
		case 13: 
			cout << "Iniciar";//ENTER -> ir pro jogo	
			break;
		case  27:   
			cout << "Sair";// ESC-> sair do jogo
			break;
		case 'm': 
			cout << "melhores";//ir para melhores pontuaçoes
			break;
		case 'M': 
			cout << "melhores";//ir para melhores pontuaçoes
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
void mouseClick(int button, int state, int x, int y) {
	//cout << "Iniciar";
	//if (button==GLUT_LEFT_BUTTON) {
	cout <<"pos: "<< x << "," << y<<endl;
	//cout <<"wx: "<< windowWidth-x << "," << windowHeight-y << endl;	
	if (fullscreen) {
		if (x >= 216 && x <= 797) {
			if (y >= 291 && y <= 381) {
				//começar jogo
				cout << "Iniciar";
			}
			else if (y >= 398 && y <= 492) {
				cout << "Opcoes";
				//chamar opcoes
			}
			else if (y >= 506 && y <= 598) {
				cout << "Melhores";
				//chamar melhores
			}
			else if (y >= 615 && y <= 704) {
				cout << "Sair";
				//fechar tudo
			}
		}
	}
	else {
		if (x >= 203 && x <= 750) {
			if (y >= 274 && y <= 360) {
				//começar jogo
				cout << "Iniciar";
			}
			else if (y >= 375 && y <= 462) {
				cout << "Opcoes";
			}
			else if (y >= 476 && y <= 562) {
				cout << "Melhores";
			}
			else if (y >= 577 && y <= 662) {
				cout << "Sair";
			}
		}
	}
		
	
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
	glutDisplayFunc(Desenha);
	glutReshapeFunc(AlteraTamanhoJanela);
	//glutTimerFunc(33, Timer, 1);
	Inicializa();
	glutMainLoop();

	return 0;
}