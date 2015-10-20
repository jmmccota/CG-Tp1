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
        if ((*i)->value < 20)
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
	for (int i = 0; i < Jogo::getInstance().numeroVidas && i < 5; i++) {
		Jogo::getInstance().vidas[i]->desenha();
	}

	//Score
	int sco = Jogo::getInstance().score->getScoreValue();
	glRasterPos2f(1630, 1000);
	int contrSc = Jogo::getInstance().getControlaScore();

	if (sco >= 100) {

		if (Jogo::getInstance().numeroVidas < 5) {
			Jogo::getInstance().numeroVidas++;
			//EfeitoSonoro::getInstance().playGanhaVida();
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

void Fase::reseta()
{
	
	inimigosAtivos.clear();
	projeteisInimigos.clear();
	projeteisAmigos.clear();
	explosoesAtivas.clear();
	caixas.clear();
}

