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
    principal = new Spitfire(500, 500, (float)100 / 10000, this);

    //Fora da tela so pra nao comecao vazio
    projeteisAmigos.push_back(new TiroSimples(-1000, -1000, 0));
    projeteisInimigos.push_back(new TiroSimples(-1000, -1000, 0));
    inimigosAtivos.push_back(new Bf109(-1000, -1000, 0, principal, this));
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
    if (value % 400 == 0)
    {
        inimigosAtivos.push_back(new Bf109(rand() % 1920, 1080, (float)100 / 10000, principal, this));
        std::list<Personagem*>::iterator aux = inimigosAtivos.end();
        (*aux)->inverteY();
    }



    for (std::list<Projetil*>::iterator i = projeteisAmigos.begin(); i != projeteisAmigos.end(); ++i)
    {
        //Calcula os disparos dados
        (*i)->acao();

        //Atualiza situacao dos inimigos
        for (std::list<Personagem*>::iterator j = inimigosAtivos.begin(); j != inimigosAtivos.end();)
        {
            //Se foi alvejado
            if (EfeitoVisual::getInstance().colisao((*j), (*i)))
                (*j)->alvejado((*i)->getDano());
            //Se foi destruido
            if ((*j)->destruido())
            {
                //Explode
                j = inimigosAtivos.erase(j);
            }
            //Se ta de boa ainda
            else
            {
                (*j)->acao();
                j++;
            }
        }
    }



    for (std::list<Projetil*>::iterator i = projeteisInimigos.begin(); i != projeteisInimigos.end(); ++i)
    {
        (*i)->acao();

        if (EfeitoVisual::getInstance().colisao((*i), principal))
            principal->alvejado((*i)->getDano());

        if (principal->destruido())
        {
            //Explosao
            //Perde uma vida
        }
        else
        {
            principal->acao();
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
