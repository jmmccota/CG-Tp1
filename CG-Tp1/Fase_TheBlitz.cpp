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
    if (value % 400 == 99)
    {
        //Bf109 *aux = new Bf109(rand() % 1920, 1080, (float) 120 / 10000, principal, this);
        Bf109 *aux = new Bf109(900, 1080, (float)100 / 10000, principal, this);
        aux->inverteY();
        inimigosAtivos.push_back(aux);
    }

    for (std::list<Projetil*>::iterator i = projeteisAmigos.begin(); i != projeteisAmigos.end(); ++i)
        (*i)->acao();

    for (std::list<Projetil*>::iterator i = projeteisInimigos.begin(); i != projeteisInimigos.end(); ++i)
        (*i)->acao();

    for (std::list<Personagem*>::iterator i = inimigosAtivos.begin(); i != inimigosAtivos.end(); ++i)
        (*i)->acao();

    principal->acao();

    if (projeteisInimigos.size() > 0)
    {
        int a = 1 + 1;
    }


    for (std::list<Projetil*>::iterator i = projeteisAmigos.begin(); i != projeteisAmigos.end();)
    {
        for (std::list<Personagem*>::iterator j = inimigosAtivos.begin(); j != inimigosAtivos.end();)
        {
            //Se foi alvejado
            if (EfeitoVisual::getInstance().colisao((*j), (*i)))
            {
                (*j)->alvejado((*i)->getDano());
                i = projeteisAmigos.erase(i);
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
    }



    for (std::list<Projetil*>::iterator i = projeteisInimigos.begin(); i != projeteisInimigos.end();)
    {
        if (EfeitoVisual::getInstance().colisao((*i), principal))
        {
            principal->alvejado((*i)->getDano());
            i = projeteisInimigos.erase(i);
        }

        if (principal->destruido())
        {
            //Explosao
            //Perde uma vida
        }
        else
        {
            ++i;
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
