#include "Fase_TheBlitz.hpp"

Fase_TheBlitz::Fase_TheBlitz()
{
    srand(time(NULL));
}

Fase_TheBlitz::~Fase_TheBlitz()
{
    delete principal;
}

void Fase_TheBlitz::definePersonagens()
{
    pair<float, float> size = EfeitoVisual::getInstance().getOrtho2D();
    principal = new Spitfire(size.first / 2, size.second / 10, (float) 100 / 10000, this);
}

void Fase_TheBlitz::desenhaBackground()
{
}

void Fase_TheBlitz::desenha()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.05, 0.05, 0.05, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    desenhaBackground();

    for (std::list<Projetil*>::iterator i = projeteisAmigos.begin(); i != projeteisAmigos.end(); ++i)
        (*i)->desenha();

    for (std::list<Projetil*>::iterator i = projeteisInimigos.begin(); i != projeteisInimigos.end(); ++i)
        (*i)->desenha();

    for (std::list<Personagem*>::iterator i = inimigosAtivos.begin(); i != inimigosAtivos.end(); ++i)
        (*i)->desenha();

    principal->desenha();

    // Executa os comandos OpenGL
    glutSwapBuffers();
}

void Fase_TheBlitz::terminou()
{
}

void Fase_TheBlitz::atualiza(int value)
{
    if (value % 300 == 99)
    {
		pair<GLint, GLint> size = EfeitoVisual::getInstance().getOrtho2D();
        Bf109 *aux = new Bf109(rand() % size.first, size.second, (float) 100 / 10000, principal, this);
        aux->inverteY();
        inimigosAtivos.push_back(aux);
		if (value % 700 == 99)
		{
			Me163 *aux2 = new Me163(rand() % size.first, size.second, (float)100 / 10000, principal, this);
			aux2->inverteY();
			inimigosAtivos.push_back(aux2);
		}
    }

    for (std::list<Projetil*>::iterator i = projeteisAmigos.begin(); i != projeteisAmigos.end(); ++i)
        (*i)->acao();

    for (std::list<Projetil*>::iterator i = projeteisInimigos.begin(); i != projeteisInimigos.end(); ++i)
        (*i)->acao();

    for (std::list<Personagem*>::iterator i = inimigosAtivos.begin(); i != inimigosAtivos.end(); ++i)
        (*i)->acao();

    principal->acao();

	//Bala aliada X Avioes inimigos
    for (std::list<Projetil*>::iterator i = projeteisAmigos.begin(); i != projeteisAmigos.end();)
    {
		bool destruiu = false;
        for (std::list<Personagem*>::iterator j = inimigosAtivos.begin(); j != inimigosAtivos.end();)
        {
            //Se foi alvejado
            if (EfeitoVisual::getInstance().colisao((*j), (*i)))
            {
                (*j)->alvejado((*i)->getDano());
                i = projeteisAmigos.erase(i);
				Jogo::getInstance().score += (*j)->getScore();
				destruiu = true;
				break;
            }
            //Se foi destruido
            if ((*j)->destruido())
            {
                //Explode
                j = inimigosAtivos.erase(j);
            }
            //Se ta de boa ainda
            else
            {
                j++;
            }
        }
		if (!destruiu)
		{
			i++;
		}
    }


	//Bala dos inimigos X Aviao
    for (std::list<Projetil*>::iterator i = projeteisInimigos.begin(); i != projeteisInimigos.end();)
    {
        if (EfeitoVisual::getInstance().colisao((*i), principal))
        {
            principal->alvejado((*i)->getDano());
            i = projeteisInimigos.erase(i);
        }
		else
		{
			++i;
		}

        if (principal->destruido())
        {
            //Explosao
            //Perde uma vida
        }
    }

	//Colisao avioes
	for (std::list<Personagem*>::iterator i = inimigosAtivos.begin(); i != inimigosAtivos.end();)
	{
		if (EfeitoVisual::getInstance().colisao((*i), principal))
		{
			principal->alvejado((*i)->danoColisao());
			(*i)->alvejado(principal->danoColisao());
		}

		if ((*i)->destruido())
		{
			Jogo::getInstance().score += (*i)->getScore();
			i = inimigosAtivos.erase(i);
		}
		else
		{
			++i;
		}

		if (principal->destruido())
		{
			//Explosao
			//Perde uma vida
		}
	}
	
}

void Fase_TheBlitz::mouse(int button, int state, int x, int y)
{
}

void Fase_TheBlitz::keyDown(unsigned char key, int x, int y)
{
}

void Fase_TheBlitz::keyUp(unsigned char key, int x, int y)
{
    principal->detectaTiro(key, x, y);
}

void Fase_TheBlitz::specialKeyDown(int key, int x, int y)
{
   principal->detectaMovimentoDown(key, x, y);
}

void Fase_TheBlitz::specialKeyUp(int key, int x, int y)
{
    principal->detectaMovimentoUp(key, x, y);
}

void Fase_TheBlitz::inicializa()
{
    definePersonagens();
	EfeitoSonoro::getInstance().playFirstLevelTheme();
    EfeitoSonoro::getInstance().airRaidSiren();
    EfeitoSonoro::getInstance().spitfireMotor();
}
