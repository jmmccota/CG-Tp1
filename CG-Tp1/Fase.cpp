#include "Fase.hpp"

Fase::Fase()
{

}

Fase::~Fase()
{

}

void Fase::desenhaExplosoes()
{
    for (std::list<Explosao*>::iterator i = explosoesAtivas.begin(); i != explosoesAtivas.end();)
    {
        if ((*i)->value < 60)
        {
            EfeitoVisual::getInstance().desenhaExplosao(*(*i));
            (*i)->value++;
            i++;
        }
        else
        {
            i = explosoesAtivas.erase(i);
        }
    }
}

void Fase::desenhaHUD() {
	//HP
    int hp = 1000 * principal->getHP() / VIDA_SPITFIRE;
	glBegin(GL_LINE_LOOP);
	glColor3f(1, 1, 1);
	glVertex2i(20, 1000);
	glVertex2i(254, 1000);
	glVertex2i(254, 970);
	glVertex2i(20, 970);
	glEnd();
	double partes = 0.234;
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	glVertex2f(21, 999);
	if ((partes*hp + 20) > 21) {
		glVertex2f(partes*hp + 20, 999);
		glVertex2f(partes*hp + 20, 971);
	}
	else {
		glVertex2f(21, 999);
		glVertex2f(21, 971);
	}
	glVertex2f(21, 971);
	glEnd();

	//Vidas
	for (int i = 0; i < Jogo::getInstance().numeroVidas; i++) {
		Jogo::getInstance().vidas[i]->desenha();
	}

	//Score
	int sco = Jogo::getInstance().score->getScoreValue();
	glRasterPos2f(1630, 1000);
	int contrSc = Jogo::getInstance().getControlaScore();

	if (sco >= contrSc) {

		if (Jogo::getInstance().numeroVidas < 5) {
			Jogo::getInstance().numeroVidas++;
		}
		Jogo::getInstance().setControlaScore();
		EfeitoSonoro::getInstance().playStreamAudio("audio/sfx/ganhaVida.mp3");
		//ADICIONAR SOM PARA MOSTRAR QUE GANHOU VIDA


	}
	glColor3f(1, 0.27, 0);
	glRasterPos2f(1600, 970);
	FuncoesAuxiliares::writeWord_BITMAP(std::to_string(Jogo::getInstance().score->getScoreValue()), GLUT_BITMAP_TIMES_ROMAN_24);

	//Armamento Bomba
	Bomba *bomba = new Bomba(30.0, 65.0, (float)20 / 10000);
	bomba->desenha();
	glColor3f(1, 0.27, 0);
	glRasterPos2f(50, 50);
	FuncoesAuxiliares::writeWord_BITMAP("x " + std::to_string(principal->getQtdTiros()), GLUT_BITMAP_TIMES_ROMAN_24);
}

void Fase::desenha() {
	//desenhaBackground();
}

void Fase::novoProjetilInimigo(Projetil *p)
{
	projeteisInimigos.push_back(p);
}

void Fase::novoProjetilAmigo(Projetil *p)
{
	projeteisAmigos.push_back(p);
}
void Fase::desenhaGameOver() {
	int x = 500, y;
	if (melhorScore) {
		y = 1000;
	}
	else {
		y = 600;
	}
	if (gameOver) {
		//G
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
		glVertex2i(x + 835, y - 70);
		glVertex2i(x + 865, y - 70);
		glVertex2i(x + 895, y - 120);
		glVertex2i(x + 865, y - 120);
		glEnd();

	}
	else if (fimDeJogo) {
		//G
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
		glVertex2i(x + 835, y - 70);
		glVertex2i(x + 865, y - 70);
		glVertex2i(x + 895, y - 120);
		glVertex2i(x + 865, y - 120);
		glEnd();
	}
}
