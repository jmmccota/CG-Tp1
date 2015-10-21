#include "Fase_TheVengeanceWeapon.hpp"
#include "FuncoesAuxiliares.hpp"
GLfloat PontosCeu[16][2];
float variacaoX = 0;
bool variacao = false;
Fase_TheVengeanceWeapon::Fase_TheVengeanceWeapon()
{
    srand(time(NULL));
    boss = nullptr;
}

Fase_TheVengeanceWeapon::~Fase_TheVengeanceWeapon()
{
    delete principal;
}

void Fase_TheVengeanceWeapon::definePersonagens()
{
    pair<float, float> size = EfeitoVisual::getInstance().getOrtho2D();
    principal = new Spitfire(size.first / 2, size.second / 10, (float)100 / 10000, this);
}


///////////////////////
//MOVER PARA EFEITOS VISUAIS

void desenhaCirculo(GLfloat raio, GLfloat Px, GLfloat Py){
	GLfloat x = 0;
	GLfloat y = 0;
	glBegin(GL_POLYGON);
	for (float i = 0; i < 360; i += 0.2){
		x = Px + raio * cos(i);
		y = Py + raio * sin(i);
		glVertex2f(x, y);
	}
	glEnd();
}

void Pedra(GLfloat X, GLfloat Y, GLfloat escala, float translacaoX, float translacaoY){
	glPushMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glScalef(escala, escala, 0);
	glTranslatef(translacaoX + variacaoX, translacaoY, 0);
	glColor3f(1, 1, 1);
	desenhaCirculo(5, 8+X, 6+Y);
	desenhaCirculo(5, 4+X, 4+Y);
	desenhaCirculo(4, 9+X, 3+Y);
	desenhaCirculo(3, 5+X, 0+Y);
	desenhaCirculo(5, 5+X, 0+Y);
	glPopMatrix();
	glFlush();
}
void desenhaBackgroundAnterior(){
	for (int i = 0; i < 14; i = i + 2){
		Pedra(0, 0, 2, PontosCeu[i][0], PontosCeu[i][1]);
	}
}

void desenhabackgroudPosterior(){
	for (int i = 0; i < 14; i = i + 2){
		Pedra(0, 0, 2.5, PontosCeu[i + 1][0], PontosCeu[i + 1][1]);
	}
}

/////////

void Fase_TheVengeanceWeapon::desenhaBackground()
{
}

void Fase_TheVengeanceWeapon::desenha()
{

	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.1137, 0.8627, 0.8902, 1.0);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    EfeitoVisual::getInstance().ortho2D();
    desenhaBackgroundAnterior();

    for (std::list<Projetil*>::iterator i = projeteisAmigos.begin(); i != projeteisAmigos.end(); ++i)
        (*i)->desenha();

    for (std::list<Projetil*>::iterator i = projeteisInimigos.begin(); i != projeteisInimigos.end(); ++i)
        (*i)->desenha();

    principal->desenha();

    for (std::list<Personagem*>::iterator i = inimigosAtivos.begin(); i != inimigosAtivos.end(); ++i)
        (*i)->desenha();

    for (std::list<Caixa*>::iterator i = caixas.begin(); i != caixas.end(); ++i)
        (*i)->desenha();

    desenhaExplosoes();

    desenhaHUD();

    desenhabackgroudPosterior();

    if (boss != nullptr)
        desenhaHPBoss(boss->getHP(), 1800);

	glutSwapBuffers();
}
//void Fase_TheVengeanceWeapon::desenhaHUD(int hp) {
//	glBegin(GL_LINE_LOOP);
//	glColor3f(1, 1, 1);
//	glVertex2i(20, 1000);
//	glVertex2i(254, 1000);
//	glVertex2i(254, 970);
//	glVertex2i(20, 970);
//	glEnd();
//	glBegin(GL_QUADS);
//	glColor3f(1, 0, 0);
//	glVertex2i(21, 999);
//	glVertex2i(253, 999);
//	glVertex2i(253, 971);
//	glVertex2i(21, 971);
//	glEnd();	
//}

void Fase_TheVengeanceWeapon::terminou()
{
    EfeitoSonoro::getInstance().finishAllAudios();
    Jogo::getInstance().setProxFase(5);
    Jogo::getInstance().proximaFase();
}

void Fase_TheVengeanceWeapon::atualiza(int value)
{
	for (int i = 0; i < 14; i++){
		PontosCeu[i][1] -= 0.3;
	}
	for (int i = 0; i < 14; i++){
		if (PontosCeu[i][1] < -100){
			PontosCeu[i][1] = 100;
		}
	}


    pair<GLint, GLint> size = EfeitoVisual::getInstance().getOrtho2D();

    //Passa de Fase
    if (passouFase) {
        if (principal->venceu()) {
            terminou();
        }
    }

    //Inimigos normais
    if (value < 10000)
    {
        if (value % 150 == 149)
        {
            Bf109 *aux = new Bf109(rand() % size.first, size.second, (float)100 / 10000, principal, this);
            aux->inverteY();
            inimigosAtivos.push_back(aux);
            EfeitoSonoro::getInstance().playBf109Motor();
        }
        if (value % 400 == 399)
        {
            Me163 *aux2 = new Me163(rand() % size.first, size.second, (float)100 / 10000, principal, this);
            aux2->inverteY();
            inimigosAtivos.push_back(aux2);
        }
        if (value % 3000 == 2999)
        {
            Bf109Amarelo *aux2 = new Bf109Amarelo(rand() % size.first, size.second, (float)100 / 10000, principal, this);
            aux2->inverteY();
            inimigosAtivos.push_back(aux2);
            EfeitoSonoro::getInstance().playBf109Motor();
        }
        if (value % 2000 == 1999)
        {
            Bf109Verde *aux2 = new Bf109Verde(rand() % size.first, size.second, (float)100 / 10000, principal, this);
            aux2->inverteY();
            inimigosAtivos.push_back(aux2);
            EfeitoSonoro::getInstance().playBf109Motor();
        }
        if (value % 3000 == 2999)
        {
            Me262 *aux2 = new Me262(rand() % size.first, size.second, (float)100 / 10000, principal, this);
            aux2->inverteY();
            inimigosAtivos.push_back(aux2);
            EfeitoSonoro::getInstance().playMe262Motor();
        }
    }
    //Chefao
    else if (value == 10200)
    {
        boss = new V2(size.first / 2, size.second + 499, (float) 400 / 10000, this);
        inimigosAtivos.push_back(boss);
    }
    else
    {
        //Boss ativo

        if (value % 500 == 299)
        {
            Me262 *aux = new Me262(rand() % size.first, size.second, (float)100 / 10000, principal, this);
            aux->inverteY();
            inimigosAtivos.push_back(aux);
            EfeitoSonoro::getInstance().playMe262Motor();
        }
        if (value % 750 == 449)
        {
            Me262 *aux = new Me262(size.first, rand() % size.second, (float)100 / 10000, principal, this);
            aux->gira();
            aux->inverteX();
            inimigosAtivos.push_back(aux);
            EfeitoSonoro::getInstance().playMe262Motor();
        }
        if (value % 950 == 649)
        {
            Me262 *aux = new Me262(0, rand() % size.second, (float)100 / 10000, principal, this);
            aux->gira();
            inimigosAtivos.push_back(aux);
            EfeitoSonoro::getInstance().playMe262Motor();
        }
        if (value % 1250 == 949)
        {
            Me262 *aux = new Me262(rand() % size.first, 0, (float)100 / 10000, principal, this);
            inimigosAtivos.push_back(aux);
            EfeitoSonoro::getInstance().playMe262Motor();
        }
    }

    for (std::list<Projetil*>::iterator i = projeteisAmigos.begin(); i != projeteisAmigos.end();)
    {
        (*i)->acao();
        if ((*i)->getX() < 0 || (*i)->getX() > size.first || (*i)->getY() < 0 || (*i)->getY() > size.second)
            i = projeteisAmigos.erase(i);
        else
            i++;
    }

    for (std::list<Projetil*>::iterator i = projeteisInimigos.begin(); i != projeteisInimigos.end();)
    {
        (*i)->acao();
        if ((*i)->getX() < 0 || (*i)->getX() > size.first || (*i)->getY() < 0 || (*i)->getY() > size.second)
            i = projeteisInimigos.erase(i);
        else
            i++;
    }

    for (std::list<Personagem*>::iterator i = inimigosAtivos.begin(); i != inimigosAtivos.end();)
    {
        (*i)->acao();
        if ((*i)->getX() < -300 || (*i)->getX() > size.first + 300 || (*i)->getY() < -300 || (*i)->getY() > size.second + 500)
            i = inimigosAtivos.erase(i);
        else
            i++;
    }

    principal->acao();

    //Para os sons dos avioes abatidos
    if (inimigosAtivos.size() == 0)
    {
        EfeitoSonoro::getInstance().stopBf109Motor();
        EfeitoSonoro::getInstance().stopMe163Motor();
    }
    //else
    //{
    //    bool bf109 = false, me163 = false;
    //    for (std::list<Personagem*>::iterator i = inimigosAtivos.begin(); i != inimigosAtivos.end(); ++i)
    //    {
    //        if ((*i)->getNome() == "Bf109")
    //            bf109 = true;
    //        else if ((*i)->getNome() == "Me163")
    //            me163 = true;
    //        if (bf109 && me163)
    //            break;
    //    }
    //    if (!me163)
    //        EfeitoSonoro::getInstance().stopMe163Motor();
    //    if (!bf109)
    //        EfeitoSonoro::getInstance().stopBf109Motor();
    //}

    //Bala aliada X Avioes inimigos
    string nome;
    for (std::list<Projetil*>::iterator i = projeteisAmigos.begin(); i != projeteisAmigos.end();)
    {
        bool destruiu = false;
        for (std::list<Personagem*>::iterator j = inimigosAtivos.begin(); j != inimigosAtivos.end();)
        {
            //Se foi alvejado
            nome = (*j)->getNome();
            if (EfeitoVisual::getInstance().colisao((*j), (*i)))
            {
                (*j)->alvejado((*i)->getDano());
                i = projeteisAmigos.erase(i);
                destruiu = true;
            }
            //Se foi destruido
            if ((*j)->destruido())
            {
                explosoesAtivas.push_back(new Explosao((*j)->getX(), (*j)->getY(), 1));
                EfeitoSonoro::getInstance().playExplosion();
                Jogo::getInstance().score->incScoreValue((*j)->getScore());

                if (nome == "Bf109Verde")
                    caixas.push_back(new Caixa((*j)->getX(), (*j)->getY(), 1));
                else if (nome == "Bf109Amarelo")
                    caixas.push_back(new Caixa((*j)->getX(), (*j)->getY(), 2));
                else if (nome == "V2")
                    passouFase = true;

                j = inimigosAtivos.erase(j);
            }
            //Se ta de boa ainda
            else
                j++;

            if (destruiu)
                break;
        }
        if (!destruiu)
            i++;

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
            ++i;

        if (principal->destruido())
        {
            explosoesAtivas.push_back(new Explosao(principal->getX(), principal->getY(), 1));
            principal->powerUp = 0;
            Jogo::getInstance().numeroVidas--;
            principal->morreu();
        }
    }

    //Colisao avioes
    for (std::list<Personagem*>::iterator i = inimigosAtivos.begin(); i != inimigosAtivos.end();)
    {
        if (EfeitoVisual::getInstance().colisao((*i), principal))
        {
            nome = (*i)->getNome();
            if (nome == "V2")
            {
                i++;
                continue;
            }
            principal->alvejado((*i)->danoColisao());
            (*i)->alvejado(principal->danoColisao());
            if (nome == "Me163")
                (*i)->alvejado(1000);
        }

        if ((*i)->destruido())
        {
            if (rand() % 20 == 0)
                principal->powerUp = 1;
            Jogo::getInstance().score->incScoreValue((*i)->getScore());
            if (nome == "V2")
            {
                explosoesAtivas.push_back(new Explosao(((*i)->getX() + principal->getX()) / 2, ((*i)->getY() + principal->getY()) / 2, 5));
            }
            else
            {
                if (nome == "Bf109Verde")
                    caixas.push_back(new Caixa((*i)->getX(), (*i)->getY(), 1));
                else if (nome == "Bf109Amarelo")
                    caixas.push_back(new Caixa((*i)->getX(), (*i)->getY(), 2));

                explosoesAtivas.push_back(new Explosao(((*i)->getX() + principal->getX()) / 2, ((*i)->getY() + principal->getY()) / 2, 2));
            }
            EfeitoSonoro::getInstance().playExplosion();
            i = inimigosAtivos.erase(i);
        }
        else
        {
            ++i;
        }

        if (principal->destruido())
        {
            if (nome != "Me163")
                explosoesAtivas.push_back(new Explosao(principal->getX(), principal->getY(), 1));
            principal->powerUp = 0;
            Jogo::getInstance().numeroVidas--;
            principal->morreu();
        }
    }

    for (std::list<Caixa*>::iterator i = caixas.begin(); i != caixas.end();)
    {
        if (EfeitoVisual::getInstance().colisao(*i, principal))
        {
            if ((*i)->tipo == 1)
            {
                principal->municao[1]++;
                principal->powerUp = 1;
            }
            else if ((*i)->tipo == 2)
            {
                principal->morreu();
                Jogo::getInstance().numeroVidas++;
            }
            i = caixas.erase(i);
        }
        else
        {
            i++;
        }
    }

    if (Jogo::getInstance().numeroVidas == 0) {
        terminou();
    }
}

void Fase_TheVengeanceWeapon::mouse(int button, int state, int x, int y)
{
}

void Fase_TheVengeanceWeapon::keyDown(unsigned char key, int x, int y)
{
}

void Fase_TheVengeanceWeapon::keyUp(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'F':
    case 'f':
        EfeitoVisual::getInstance().setFullScreen();
        break;
    case 'p':
    case 'P':
        Jogo::getInstance().pausado = !Jogo::getInstance().pausado;
        break;
    default:
        principal->detectaTiro(key, x, y);
    }
}

void Fase_TheVengeanceWeapon::specialKeyDown(int key, int x, int y)
{
    principal->detectaMovimentoDown(key, x, y);
}

void Fase_TheVengeanceWeapon::specialKeyUp(int key, int x, int y)
{
    principal->detectaMovimentoUp(key, x, y);
}

void Fase_TheVengeanceWeapon::inicializa()
{
    reseta();
	definePersonagens();
	EfeitoSonoro::getInstance().initAudios_TheVengeanceWeapon();
	EfeitoSonoro::getInstance().playMainTheme();

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	PontosCeu[0][0] = -35;
	PontosCeu[0][1] = 30;
	PontosCeu[1][0] = -5;
	PontosCeu[1][1] = 15;
	PontosCeu[2][0] = 25;
	PontosCeu[2][1] = 30;
	PontosCeu[4][0] = -5;
	PontosCeu[4][1] = 20;
	PontosCeu[5][0] = -40;
	PontosCeu[5][1] = -25;
	PontosCeu[6][0] = 35;
	PontosCeu[6][1] = -30;
	PontosCeu[7][0] = -5;
	PontosCeu[7][1] = -45;
	for (int i = 8; i < 14; i++){
		PontosCeu[i][0] = PontosCeu[i - 7][0];
		PontosCeu[i][1] = PontosCeu[i - 7][1] + 100;
	}
}
