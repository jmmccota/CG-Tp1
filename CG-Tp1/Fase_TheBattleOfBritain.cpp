#include "Fase_TheBattleOfBritain.hpp"

// pontos do efeito de agua
GLfloat Pontos[16][2];

Fase_TheBattleOfBritain::Fase_TheBattleOfBritain()
{
}

Fase_TheBattleOfBritain::~Fase_TheBattleOfBritain()
{
    delete principal;
}

void Fase_TheBattleOfBritain::definePersonagens()
{
    pair<float, float> size = EfeitoVisual::getInstance().getOrtho2D();
    principal = new Spitfire(size.first / 2, size.second / 10, (float)100 / 10000, this);

    //Fora da tela so pra nao comecar vazio
    projeteisAmigos.push_back(new TiroSimples(-1000, -1000, 0));
    projeteisInimigos.push_back(new TiroSimples(-1000, -1000, 0));
    inimigosAtivos.push_back(new Bf109(-1000, -1000, 0, principal, this));
}

void drawWaves(float translacaoX, float translacaoY, float escala){
    glPushMatrix();
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    glScalef(escala, escala, 0);
    glTranslatef(translacaoX, translacaoY, 0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2i(-10, 0);
    glVertex2i(0, 10);
    glVertex2i(0, 10);
    glVertex2i(10, 0);
    glVertex2i(10, 0);
    glVertex2i(20, 10);
    glEnd();
    glPopMatrix();
    glFlush();
}

void Fase_TheBattleOfBritain::desenhaBackground()
{
    for (int i = 0; i < 16; i++){
        drawWaves(Pontos[i][0], Pontos[i][1], 0.25);
    }
    EfeitoVisual::getInstance().ortho2D();
}

void Fase_TheBattleOfBritain::desenha()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.2235f, 0.4823f, 0.8078f, 1.0);
    glMatrixMode(GL_PROJECTION);
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

void Fase_TheBattleOfBritain::terminou()
{
}

void Fase_TheBattleOfBritain::atualiza(int value)
{
    for (int i = 0; i < 16; i++){
        Pontos[i][1] -= 2;
    }
    for (int i = 0; i < 16; i++){
        if (Pontos[i][1] < -400){
            Pontos[i][1] = 600;
        }
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

void Fase_TheBattleOfBritain::mouse(int button, int state, int x, int y)
{
}

void Fase_TheBattleOfBritain::keyDown(unsigned char key, int x, int y)
{
}

void Fase_TheBattleOfBritain::keyUp(unsigned char key, int x, int y)
{
    principal->detectaTiro(key, x, y);
}

void Fase_TheBattleOfBritain::specialKeyDown(int key, int x, int y)
{
    principal->detectaMovimentoDown(key, x, y);
}

void Fase_TheBattleOfBritain::specialKeyUp(int key, int x, int y)
{
    principal->detectaMovimentoUp(key, x, y);
}

void Fase_TheBattleOfBritain::inicializa()
{
    definePersonagens();
    EfeitoSonoro::getInstance().playSecondLevelTheme();
    EfeitoSonoro::getInstance().spitfireMotor();
    Pontos[0][0] = -265;
    Pontos[0][1] = 220;
    Pontos[1][0] = 0;
    Pontos[1][1] = 150;
    Pontos[2][0] = 225;
    Pontos[2][1] = 0;
    Pontos[3][0] = 265;
    Pontos[3][1] = 220;
    Pontos[4][0] = -225;
    Pontos[4][1] = 0;
    Pontos[5][0] = -265;
    Pontos[5][1] = -220;
    Pontos[6][0] = 0;
    Pontos[6][1] = -150;
    Pontos[7][0] = 265;
    Pontos[7][1] = -220;
    for (int i = 8; i < 16; i++){
        Pontos[i][0] = Pontos[i - 8][0];
        Pontos[i][1] = Pontos[i - 8][1] + 570;
    }
}
