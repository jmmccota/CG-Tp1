#define _CRT_SECURE_NO_WARNINGS
#include "GameOver.hpp"
GameOver::GameOver()
{
}

GameOver::~GameOver()
{
}

void GameOver::definePersonagens()
{
}

void GameOver::desenhaBackground()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	//cout << "entra aqui BG \n";
}

void GameOver::desenha()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.05, 0.05, 0.05, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	desenhaBackground();
	//cout << "entra aqui desenha \n";
	/*EfeitoVisual::getInstance().ortho2D();	*/
	//se gameOver true escreve grande na tela game over se fudeu etc
	desenhaGameOver();
	//se gameOver false escreve you win voce ? fod?o	

	if (Jogo::getInstance().score->getScoreValue() > 0) {
		desenhaScore();
		//coloca no meio da tela o quadradim pra digitar
	}
	if (contador > 100) {
		explosoesAtivas.push_back(new Explosao(rand() % 450, rand() % 1000, 1));
		explosoesAtivas.push_back(new Explosao(rand() % 100 + 1700, rand() % 1000, 1));
		contador = 0;
	}
	contador++;
	// Present frame buffer
	if (contador % 3 == 0) {
		desenhaExplosoes();
	}


	glutSwapBuffers();
}

void GameOver::terminou()
{
}

void GameOver::atualiza(int value)
{
	pair<GLint, GLint> size = EfeitoVisual::getInstance().getOrtho2D();
	desenha();
}

void GameOver::mouse(int button, int state, int x, int y)
{
	// send event to AntTweakBar
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		cout << "Position: (" << x << "," << y << ")" << endl;
		if (x > 1080 && x < 1200) {
			if (y < 530 && y>480) {
				Jogo::getInstance().score->saveScore(nome, Jogo::getInstance().score->getScoreValue());
				Jogo::getInstance().setProxFase(1);
				Jogo::getInstance().proximaFase();

			}
		}
	}

}

void GameOver::keyDown(unsigned char key, int x, int y)
{


}

void GameOver::keyUp(unsigned char key, int x, int y)
{
	string aux;
	switch (key) {
	case 13:
		//enter salvar
		if (Jogo::getInstance().score->getScoreValue() > 0) {
			Jogo::getInstance().score->saveScore(nome, Jogo::getInstance().score->getScoreValue());
		}
		Jogo::getInstance().setProxFase(1);
		Jogo::getInstance().proximaFase();
	case 8:

		if (nome.length() > 0) {
			for (int i = 0; i < nome.length() - 1; i++) {
				aux += nome[i];
			}
			nome = aux;
		}
		break;
	}
	if (nome.length() < 20) {
		switch (key) {
		case 'a': //
		case 'A':
			nome += "A";
			break;
		case 'b': //
		case 'B':
			nome += "B";
			break;
		case 'c': //
		case 'C':
			nome += "C";
			break;
		case 'd': //
		case 'D':
			nome += "D";
			break;
		case 'e': //
		case 'E':
			nome += "E";
			break;
		case 'f': //
		case 'F':
			nome += "F";
			break;
		case 'g': //
		case 'G':
			nome += "G";
			break;
		case 'h': //
		case 'H':
			nome += "H";
			break;
		case 'i': //
		case 'I':
			nome += "I";
			break;
		case 'j': //
		case 'J':
			nome += "J";
			break;
		case 'k': //
		case 'K':
			nome += "K";
			break;
		case 'l': //
		case 'L':
			nome += "L";
			break;
		case 'M': //
		case 'm':
			nome += "M";
			break;
		case 'n': //
		case 'N':
			nome += "N";
			break;
		case 'o': //
		case 'O':
			nome += "O";
			break;
		case 'p': //
		case 'P':
			nome += "P";
			break;
		case 'q': //
		case 'Q':
			nome += "Q";
			break;
		case 'r': //
		case 'R':
			nome += "R";
			break;
		case 's': //
		case 'S':
			nome += "S";
			break;
		case 't': //
		case 'T':
			nome += "T";
			break;
		case 'u': //
		case 'U':
			nome += "U";
			break;
		case 'V': //
		case 'v':
			nome += "V";
			break;
		case 'x': //
		case 'X':
			nome += "X";
			break;
		case 'y': //
		case 'Y':
			nome += "Y";
			break;
		case 'w': //
		case 'W':
			nome += "W";
			break;
		case 'z': //
		case 'Z':
			nome += "Z";
			break;
		}
	}
}

void GameOver::specialKeyDown(int key, int x, int y)
{

}

void GameOver::specialKeyUp(int key, int x, int y)
{


}
void GameOver::desenhaGameOver() {
	//cout << "entra aqui gameOVer\n";
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	EfeitoVisual::getInstance().ortho2D();
	int x = 500, y;
	glColor3f(1, 0.27, 0);
	if (Jogo::getInstance().score->getScoreValue() > 0) {
		y = 1000;
	}
	else {
		y = 600;
	}
	if (Jogo::getInstance().numeroVidas == 0) {
		x += 30;
		//G
		EfeitoVisual::getInstance().desenhaQuadrado(x - 10, y + 10, x + 60, y - 20);
		EfeitoVisual::getInstance().desenhaQuadrado(x - 10, y, x + 20, y - 120);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 10, y - 100, x + 70, y - 120);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 50, y - 100, x + 70, y - 60);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 40, y - 60, x + 70, y - 50);
		//		
		EfeitoVisual::getInstance().desenhaQuadrado(x - 10, y + 10, x + 60, y - 20);
		EfeitoVisual::getInstance().desenhaQuadrado(x - 10, y, x + 20, y - 120);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 10, y - 100, x + 70, y - 120);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 50, y - 100, x + 70, y - 60);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 40, y - 60, x + 70, y - 50);
		//A
		EfeitoVisual::getInstance().desenhaQuadrado(x + 85, y - 10, x + 115, y - 120);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 85, y - 20, x + 180, y + 10);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 150, y + 10, x + 180, y - 120);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 85, y - 60, x + 180, y - 50);
		//M
		EfeitoVisual::getInstance().desenhaQuadrado(x + 195, y + 10, x + 225, y - 120);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 265, y + 10, x + 295, y - 120);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 225, y - 30, x + 235, y - 40);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 255, y - 30, x + 265, y - 40);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 235, y - 40, x + 255, y - 60);
		//E
		EfeitoVisual::getInstance().desenhaQuadrado(x + 315, y + 10, x + 345, y - 120);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 315, y + 10, x + 405, y - 10);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 315, y - 50, x + 395, y - 60);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 315, y - 100, x + 405, y - 120);
		//O
		EfeitoVisual::getInstance().desenhaQuadrado(x + 455, y + 10, x + 485, y - 120);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 525, y + 10, x + 555, y - 120);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 455, y + 10, x + 555, y - 10);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 455, y - 100, x + 555, y - 120);
		//V
		EfeitoVisual::getInstance().desenhaQuadrado(x + 575, y + 10, x + 605, y - 80);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 645, y + 10, x + 675, y - 80);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 585, y - 80, x + 665, y - 95);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 595, y - 95, x + 655, y - 105);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 605, y - 95, x + 645, y - 120);
		//E
		EfeitoVisual::getInstance().desenhaQuadrado(x + 695, y + 10, x + 725, y - 120);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 695, y + 10, x + 785, y - 10);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 695, y - 50, x + 775, y - 60);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 695, y - 100, x + 785, y - 120);
		//R
		EfeitoVisual::getInstance().desenhaQuadrado(x + 805, y + 10, x + 835, y - 120);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 805, y + 10, x + 895, y - 10);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 875, y + 10, x + 895, y - 70);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 805, y - 50, x + 895, y - 70);
		glBegin(GL_QUADS);
		glColor3f(1, 0.27, 0);
		glVertex2i(x + 835, y - 70);
		glVertex2i(x + 865, y - 70);
		glVertex2i(x + 895, y - 120);
		glVertex2i(x + 865, y - 120);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(1, 1, 1);
		glVertex2i(x + 835 + 1, y - 70);
		glVertex2i(x + 865 + 1, y - 70);
		glVertex2i(x + 895 + 1, y - 120);
		glVertex2i(x + 865 + 1, y - 120);
		glEnd();

	}
	else {
		//V
		x += 100;
		EfeitoVisual::getInstance().desenhaQuadrado(x - 10, y + 10, x + 20, y - 80);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 60, y + 10, x + 90, y - 80);
		EfeitoVisual::getInstance().desenhaQuadrado(x, y - 80, x + 80, y - 95);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 10, y - 95, x + 70, y - 105);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 20, y - 95, x + 60, y - 120);
		//I
		EfeitoVisual::getInstance().desenhaQuadrado(x + 110, y + 10, x + 140, y - 120);
		//C
		EfeitoVisual::getInstance().desenhaQuadrado(x + 160, y + 10, x + 190, y - 120);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 160, y + 10, x + 240, y - 20);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 160, y - 90, x + 240, y - 120);
		//T
		EfeitoVisual::getInstance().desenhaQuadrado(x + 300, y + 10, x + 330, y - 120);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 260, y + 10, x + 370, y - 20);
		//O
		EfeitoVisual::getInstance().desenhaQuadrado(x + 390, y + 10, x + 420, y - 120);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 390, y + 10, x + 460, y - 20);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 390, y - 90, x + 460, y - 120);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 460, y + 10, x + 490, y - 120);
		//R
		EfeitoVisual::getInstance().desenhaQuadrado(x + 510, y + 10, x + 540, y - 120);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 510, y + 10, x + 600, y - 10);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 580, y + 10, x + 600, y - 70);
		EfeitoVisual::getInstance().desenhaQuadrado(x + 510, y - 50, x + 600, y - 70);
		glBegin(GL_QUADS);
		glColor3f(1, 0.27, 0);
		glVertex2i(x + 540, y - 70);
		glVertex2i(x + 570, y - 70);
		glVertex2i(x + 600, y - 120);
		glVertex2i(x + 570, y - 120);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(1, 1, 1);
		glVertex2i(x + 541, y - 70);
		glVertex2i(x + 571, y - 70);
		glVertex2i(x + 601, y - 120);
		glVertex2i(x + 571, y - 120);
		glEnd();
		//Y
		EfeitoVisual::getInstance().desenhaQuadrado(x + 660, y - 60, x + 690, y - 120);
		glBegin(GL_QUADS);
		glColor3f(1, 0.27, 0);
		glVertex2i(x + 620, y + 10);
		glVertex2i(x + 650, y + 10);
		glVertex2i(x + 690, y - 60);
		glVertex2i(x + 660, y - 60);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(1, 1, 1);
		glVertex2i(x + 621, y + 10);
		glVertex2i(x + 651, y + 10);
		glVertex2i(x + 691, y - 60);
		glVertex2i(x + 661, y - 60);
		glEnd();
		glBegin(GL_QUADS);
		glColor3f(1, 0.27, 0);
		glVertex2i(x + 730, y + 10);
		glVertex2i(x + 700, y + 10);
		glVertex2i(x + 660, y - 60);
		glVertex2i(x + 690, y - 60);
		glEnd();
		glBegin(GL_LINE_LOOP);
		glColor3f(1, 1, 1);
		glVertex2i(x + 731, y + 10);
		glVertex2i(x + 701, y + 10);
		glVertex2i(x + 661, y - 60);
		glVertex2i(x + 691, y - 60);
		glEnd();

	}
	glPopMatrix();
}
//void GameOver::desenhaQuadrado(int x,int y,int x1,int y1) {
//	glColor3f(1, 1, 1);
//	glBegin(GL_QUADS);
//	glVertex2i(x, y);
//	glVertex2i(x1, y);
//	glVertex2i(x1, y1);
//	glVertex2i(x, y1);
//	glEnd();
//}
void GameOver::desenhaScore() {
	//cout << "entra aqui SCORE\n";
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 0.27, 0);
	glVertex2i(650, 700);
	glVertex2i(1240, 700);
	glVertex2i(1240, 450);
	glVertex2i(650, 450);
	glEnd();
	string recorde = "SALVE SEU SCORE!";

	glRasterPos2f(660, 650);
	FuncoesAuxiliares::writeWord_BITMAP(recorde, GLUT_BITMAP_TIMES_ROMAN_24);
	//string sco = score;
	glRasterPos2f(660, 565);
	FuncoesAuxiliares::writeWord_BITMAP("Nome: ", GLUT_BITMAP_TIMES_ROMAN_24);
	glBegin(GL_LINE_LOOP);
	glVertex2i(770, 600);
	glVertex2i(1200, 600);
	glVertex2i(1200, 550);
	glVertex2i(770, 550);
	glEnd();
	string score = "Score: " + std::to_string(Jogo::getInstance().score->getScoreValue());
	glRasterPos2f(660, 480);
	FuncoesAuxiliares::writeWord_BITMAP(score, GLUT_BITMAP_TIMES_ROMAN_24);
	glRasterPos2f(780, 565);
	//cout << nome.length();
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
void GameOver::inicializa()
{
	// se game over true coloca musica de game over else musica de victory
	EfeitoSonoro::getInstance().initAudios_GameOver();
	EfeitoSonoro::getInstance().playMainTheme();

	desenha();
}