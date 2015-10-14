#include "Fase_TheBlitz.hpp"
float escalaGeral = 0.25;
float transX = -2880;
float transY = -1620;
float rotacao = 0;
float transladaCena2 = 0;
float translacaoY = 0;

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

//// retangulo
//void desenha1(float translacaoX, float translacaoY, float escalaX, float escalaY, float rotacao, float red, float green, float blue){
//	glPushMatrix();
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-960, 960, -540, 540);
//	glScalef(escalaX, escalaY, 0);
//	glTranslatef(translacaoX, translacaoY, 0);
//	glRotatef(rotacao, 1, 0, 0);
//	glColor3f(red, green, blue);
//	// poligono 1
//	glBegin(GL_POLYGON);
//	glVertex2i(-50, -50);
//	glVertex2i(-50, 50);
//	glVertex2i(50, 50);
//	glVertex2i(50, -50);
//	glVertex2i(-50, -50);
//	glEnd();
//	glPopMatrix();
//	glFlush();
//}
//
//// quarteirao
//void desenha2(float translacaoX, float translacaoY, float escalaX, float escalaY, float red, float green, float blue, int altura, int largura){
//	glPushMatrix();
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-960, 960, -540, 540);
//	glScalef(escalaX, escalaY, 0);
//	glTranslatef(translacaoX + transX, translacaoY + transY, 0);
//	glColor3f(red, green, blue);
//	glBegin(GL_LINES);
//	glVertex2i(-100, altura);
//	glVertex2i(-100, 56);
//	glVertex2i(-100, 56);
//	glVertex2i(-largura, 56);
//	glEnd();
//	glBegin(GL_LINES);
//	glVertex2i(-largura, -56);
//	glVertex2i(-100, -56);
//	glVertex2i(-100, -56);
//	glVertex2i(-100, -altura);
//	glEnd();
//	glBegin(GL_LINES);
//	glVertex2i(100, -altura);
//	glVertex2i(100, -56);
//	glVertex2i(100, -56);
//	glVertex2i(largura, -56);
//	glEnd();
//	glBegin(GL_LINES);
//	glVertex2i(100, altura);
//	glVertex2i(100, 56);
//	glVertex2i(100, 56);
//	glVertex2i(largura, 56);
//	glEnd();
//	glPopMatrix();
//	glFlush();
//}
//
//// linha asfalto
//void desenha3(float translacaoX, float translacaoY, float escalaX, float escalaY, float red, float green, float blue, int altura, int largura){
//	glPushMatrix();
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-960, 960, -540, 540);
//	glScalef(escalaX, escalaY, 0);
//	glTranslatef(translacaoX + transX, translacaoY + transY, 0);
//	glColor3f(red, green, blue);
//	glBegin(GL_LINES);
//	glVertex2f(-5, altura);
//	glVertex2f(-5, 2.8);
//	glVertex2f(-5, 2.8);
//	glVertex2f(-largura, 2.8);
//	glEnd();
//	glBegin(GL_LINES);
//	glVertex2f(-largura, -2.8);
//	glVertex2f(-5, -2.8);
//	glVertex2f(-5, -2.8);
//	glVertex2f(-5, -altura);
//	glEnd();
//	glBegin(GL_LINES);
//	glVertex2f(5, -altura);
//	glVertex2f(5, -2.8);
//	glVertex2f(5, -2.8);
//	glVertex2f(largura, -2.8);
//	glEnd();
//	glBegin(GL_LINES);
//	glVertex2f(5, altura);
//	glVertex2f(5, 2.8);
//	glVertex2f(5, 2.8);
//	glVertex2f(largura, 2.8);
//	glEnd();
//	glPopMatrix();
//	glFlush();
//}
//
//void criaDesenho(float translaY){
//	transladaCena2 += translaY;
//	for (int i = 0; i < 32; i++){
//		if (i == 0){
//			transX = -2880;
//			transY = -1620;
//		}
//		else if (i == 1){
//			transX = -960;
//			transY = -1620;
//		}
//		else if (i == 2){
//			transX = 960;
//			transY = -1620;
//		}
//		else if (i == 3){
//			transX = 2880;
//			transY = -1620;
//		}
//		else if (i == 4){
//			transX = -2880;
//			transY = -540;
//		}
//		else if (i == 5){
//			transX = -960;
//			transY = -540;
//		}
//		else if (i == 6){
//			transX = 960;
//			transY = -540;
//		}
//		else if (i == 7){
//			transX = 2880;
//			transY = -540;
//		}
//		else if (i == 8){
//			transX = -2880;
//			transY = 540;
//		}
//		else if (i == 9){
//			transX = -960;
//			transY = 540;
//		}
//		else if (i == 10){
//			transX = 960;
//			transY = 540;
//		}
//		else if (i == 11){
//			transX = 2880;
//			transY = 540;
//		}
//		else if (i == 12){
//			transX = -2880;
//			transY = 1620;
//		}
//		else if (i == 13){
//			transX = -960;
//			transY = 1620;
//		}
//		else if (i == 14){
//			transX = 960;
//			transY = 1620;
//		}
//		else if (i == 15){
//			transX = 2880;
//			transY = 1620;
//		}
//		if (i == 16){
//			transX = -2880;
//			transY = -1620 + 3240;
//		}
//		else if (i == 17){
//			transX = -960;
//			transY = -1620 + 3240;
//		}
//		else if (i == 18){
//			transX = 960;
//			transY = -1620 + 3240;
//		}
//		else if (i == 19){
//			transX = 2880;
//			transY = -1620 + 3240;
//		}
//		else if (i == 20){
//			transX = -2880;
//			transY = -540 + 3240;
//		}
//		else if (i == 21){
//			transX = -960;
//			transY = -540 + 3240;
//		}
//		else if (i == 22){
//			transX = 960;
//			transY = -540 + 3240;
//		}
//		else if (i == 23){
//			transX = 2880;
//			transY = -540 + 3240;
//		}
//		else if (i == 24){
//			transX = -2880;
//			transY = 540 + 3240;
//		}
//		else if (i == 25){
//			transX = -960;
//			transY = 540 + 3240;
//		}
//		else if (i == 26){
//			transX = 960;
//			transY = 540 + 3240;
//		}
//		else if (i == 27){
//			transX = 2880;
//			transY = 540 + 3240;
//		}
//		else if (i == 28){
//			transX = -2880;
//			transY = 1620 + 3240;
//		}
//		else if (i == 29){
//			transX = -960;
//			transY = 1620 + 3240;
//		}
//		else if (i == 30){
//			transX = 960;
//			transY = 1620 + 3240;
//		}
//		else if (i == 31){
//			transX = 2880;
//			transY = 1620 + 3240;
//		}
//		// desenha quarteirao
//		desenha2(1, 1 + transladaCena2, 1 * escalaGeral, 1 * escalaGeral, 0.098, 0.098, 0.098, 540, 960);
//		//desenha casas
//		desenha1(-100 + (transX / 3), 100 + (transY / 3) + (transladaCena2 / 3), 3 * escalaGeral, 3 * escalaGeral, rotacao, 0.098, 0.098, 0.098);
//		desenha1(-230 + (transX / 3), 100 + (transY / 2) + (transladaCena2 / 2), 3 * escalaGeral, 2 * escalaGeral, rotacao, 0.098, 0.098, 0.098);
//		desenha1(-450 + (transX / 1.6), -90 + (transY / 3) + (transladaCena2 / 3), 1.6*escalaGeral, 3 * escalaGeral, rotacao, 0.098, 0.098, 0.098);
//		desenha1(-120 + (transX / 2.3), -90 + (transY / 3) + (transladaCena2 / 3), 2.3*escalaGeral, 3 * escalaGeral, rotacao, 0.098, 0.098, 0.098);
//		desenha1(120 + (transX / 3), -400 + (transY)+(transladaCena2), 3 * escalaGeral, 1 * escalaGeral, rotacao, 0.098, 0.098, 0.098);
//		desenha1(90 + (transX / 5), -100 + (transY / 2) + (transladaCena2 / 2), 5 * escalaGeral, 2 * escalaGeral, rotacao, 0.098, 0.098, 0.098);
//		desenha1(100 + (transX / 5), 75 + (transY / 4) + (transladaCena2 / 4), 5 * escalaGeral, 4 * escalaGeral, rotacao, 0.098, 0.098, 0.098);
//		//desenha linha asfalto
//		desenha3(1, 1 + transladaCena2, 1 * escalaGeral, 1 * escalaGeral, 0.1, 0.1, 0.1, 540, 960);
//		// desenha carros
//		desenha1(70 + (transX / 0.8), -200 + (transY)+(transladaCena2), 0.8*escalaGeral, 1 * escalaGeral, rotacao, 0.13, 0.07, 0.14);
//		desenha1(120 + (transX / 0.5), -250 + (transY / 0.8) + (transladaCena2 / 0.8), 0.5*escalaGeral, 0.8*escalaGeral, rotacao, 0, 0, 0);
//		desenha1(200 + (transX / 0.3), -400 + (transY / 0.5) + (transladaCena2 / 0.5), 0.3*escalaGeral, 0.5*escalaGeral, rotacao, 0.13, 0.07, 0.14);
//		desenha1(-400 + (transX / 1.45), -60 + (transY / 0.45) + (transladaCena2 / 0.45), 1.45*escalaGeral, 0.45*escalaGeral, rotacao, 0.13, 0.07, 0.14);
//		desenha1(-585 + (transX), -80 + (transY / 0.3) + (transladaCena2 / 0.3), 1 * escalaGeral, 0.3*escalaGeral, rotacao, 0, 0, 0);
//		desenha1(-730 + (transX / 0.8), -115 + (transY / 0.2) + (transladaCena2 / 0.2), 0.8*escalaGeral, 0.2*escalaGeral, rotacao, 0.13, 0.07, 0.14);
//	}
//}

void Fase_TheBlitz::desenhaBackground()
{
	//criaDesenho(0);
	//// Executa os comandos OpenGL
	//glutSwapBuffers();
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
	desenhaHUD(principal->getHP());
	//desenhaVidas(principal->getNumeroVidas());
    // Executa os comandos OpenGL
    glutSwapBuffers();
}
void Fase_TheBlitz::desenhaHUD(int hp) {
	glBegin(GL_LINE_LOOP);
	hp = 100;
	glColor3f(1, 1, 1);
	glVertex2i(20, 1000);
	glVertex2i(254, 1000);
	glVertex2i(254, 970);
	glVertex2i(20, 970);
	glEnd();
	double partes = 2.34;
	glBegin(GL_QUADS);
	glColor3f(1, 0, 0);
	cout << "Partes: " << partes;
	cout << "HP: " << hp;
	cout << "Sangue: " << partes*hp+20;
	glVertex2f(21, 999);
	glVertex2f(partes*hp+20, 999);
	glVertex2f(partes*hp+20, 971);
	glVertex2f(21, 971);
	glEnd();	
}
void Fase_TheBlitz::terminou()
{
}

void Fase_TheBlitz::atualiza(int value)
{
	/*transladaCena2 -= 60;
	if (transladaCena2 <= -3240){
		transladaCena2 = 0;
	}*/
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
