#include "Fase_TheBlitz.hpp"
float escalaGeral = 0.25;
float tX = -2880;
float tY = -1620;
float rot = 0;
float transladaCena2 = 0;
float translY = 0;

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
//void desenha1(float translacaoX, float translY, float escalaX, float escalaY, float rot, float red, float green, float blue){
//	glPushMatrix();
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-960, 960, -540, 540);
//	glScalef(escalaX, escalaY, 0);
//	glTranslatef(translacaoX, translY, 0);
//	glRotatef(rot, 1, 0, 0);
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
//void desenha2(float translacaoX, float translY, float escalaX, float escalaY, float red, float green, float blue, int altura, int largura){
//	glPushMatrix();
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-960, 960, -540, 540);
//	glScalef(escalaX, escalaY, 0);
//	glTranslatef(translacaoX + tX, translY + tY, 0);
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
//void desenha3(float translacaoX, float translY, float escalaX, float escalaY, float red, float green, float blue, int altura, int largura){
//	glPushMatrix();
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-960, 960, -540, 540);
//	glScalef(escalaX, escalaY, 0);
//	glTranslatef(translacaoX + tX, translY + tY, 0);
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
//			tX = -2880;
//			tY = -1620;
//		}
//		else if (i == 1){
//			tX = -960;
//			tY = -1620;
//		}
//		else if (i == 2){
//			tX = 960;
//			tY = -1620;
//		}
//		else if (i == 3){
//			tX = 2880;
//			tY = -1620;
//		}
//		else if (i == 4){
//			tX = -2880;
//			tY = -540;
//		}
//		else if (i == 5){
//			tX = -960;
//			tY = -540;
//		}
//		else if (i == 6){
//			tX = 960;
//			tY = -540;
//		}
//		else if (i == 7){
//			tX = 2880;
//			tY = -540;
//		}
//		else if (i == 8){
//			tX = -2880;
//			tY = 540;
//		}
//		else if (i == 9){
//			tX = -960;
//			tY = 540;
//		}
//		else if (i == 10){
//			tX = 960;
//			tY = 540;
//		}
//		else if (i == 11){
//			tX = 2880;
//			tY = 540;
//		}
//		else if (i == 12){
//			tX = -2880;
//			tY = 1620;
//		}
//		else if (i == 13){
//			tX = -960;
//			tY = 1620;
//		}
//		else if (i == 14){
//			tX = 960;
//			tY = 1620;
//		}
//		else if (i == 15){
//			tX = 2880;
//			tY = 1620;
//		}
//		if (i == 16){
//			tX = -2880;
//			tY = -1620 + 3240;
//		}
//		else if (i == 17){
//			tX = -960;
//			tY = -1620 + 3240;
//		}
//		else if (i == 18){
//			tX = 960;
//			tY = -1620 + 3240;
//		}
//		else if (i == 19){
//			tX = 2880;
//			tY = -1620 + 3240;
//		}
//		else if (i == 20){
//			tX = -2880;
//			tY = -540 + 3240;
//		}
//		else if (i == 21){
//			tX = -960;
//			tY = -540 + 3240;
//		}
//		else if (i == 22){
//			tX = 960;
//			tY = -540 + 3240;
//		}
//		else if (i == 23){
//			tX = 2880;
//			tY = -540 + 3240;
//		}
//		else if (i == 24){
//			tX = -2880;
//			tY = 540 + 3240;
//		}
//		else if (i == 25){
//			tX = -960;
//			tY = 540 + 3240;
//		}
//		else if (i == 26){
//			tX = 960;
//			tY = 540 + 3240;
//		}
//		else if (i == 27){
//			tX = 2880;
//			tY = 540 + 3240;
//		}
//		else if (i == 28){
//			tX = -2880;
//			tY = 1620 + 3240;
//		}
//		else if (i == 29){
//			tX = -960;
//			tY = 1620 + 3240;
//		}
//		else if (i == 30){
//			tX = 960;
//			tY = 1620 + 3240;
//		}
//		else if (i == 31){
//			tX = 2880;
//			tY = 1620 + 3240;
//		}
//		// desenha quarteirao
//		desenha2(1, 1 + transladaCena2, 1 * escalaGeral, 1 * escalaGeral, 0.098, 0.098, 0.098, 540, 960);
//		//desenha casas
//		desenha1(-100 + (tX / 3), 100 + (tY / 3) + (transladaCena2 / 3), 3 * escalaGeral, 3 * escalaGeral, rot, 0.098, 0.098, 0.098);
//		desenha1(-230 + (tX / 3), 100 + (tY / 2) + (transladaCena2 / 2), 3 * escalaGeral, 2 * escalaGeral, rot, 0.098, 0.098, 0.098);
//		desenha1(-450 + (tX / 1.6), -90 + (tY / 3) + (transladaCena2 / 3), 1.6*escalaGeral, 3 * escalaGeral, rot, 0.098, 0.098, 0.098);
//		desenha1(-120 + (tX / 2.3), -90 + (tY / 3) + (transladaCena2 / 3), 2.3*escalaGeral, 3 * escalaGeral, rot, 0.098, 0.098, 0.098);
//		desenha1(120 + (tX / 3), -400 + (tY)+(transladaCena2), 3 * escalaGeral, 1 * escalaGeral, rot, 0.098, 0.098, 0.098);
//		desenha1(90 + (tX / 5), -100 + (tY / 2) + (transladaCena2 / 2), 5 * escalaGeral, 2 * escalaGeral, rot, 0.098, 0.098, 0.098);
//		desenha1(100 + (tX / 5), 75 + (tY / 4) + (transladaCena2 / 4), 5 * escalaGeral, 4 * escalaGeral, rot, 0.098, 0.098, 0.098);
//		//desenha linha asfalto
//		desenha3(1, 1 + transladaCena2, 1 * escalaGeral, 1 * escalaGeral, 0.1, 0.1, 0.1, 540, 960);
//		// desenha carros
//		desenha1(70 + (tX / 0.8), -200 + (tY)+(transladaCena2), 0.8*escalaGeral, 1 * escalaGeral, rot, 0.13, 0.07, 0.14);
//		desenha1(120 + (tX / 0.5), -250 + (tY / 0.8) + (transladaCena2 / 0.8), 0.5*escalaGeral, 0.8*escalaGeral, rot, 0, 0, 0);
//		desenha1(200 + (tX / 0.3), -400 + (tY / 0.5) + (transladaCena2 / 0.5), 0.3*escalaGeral, 0.5*escalaGeral, rot, 0.13, 0.07, 0.14);
//		desenha1(-400 + (tX / 1.45), -60 + (tY / 0.45) + (transladaCena2 / 0.45), 1.45*escalaGeral, 0.45*escalaGeral, rot, 0.13, 0.07, 0.14);
//		desenha1(-585 + (tX), -80 + (tY / 0.3) + (transladaCena2 / 0.3), 1 * escalaGeral, 0.3*escalaGeral, rot, 0, 0, 0);
//		desenha1(-730 + (tX / 0.8), -115 + (tY / 0.2) + (transladaCena2 / 0.2), 0.8*escalaGeral, 0.2*escalaGeral, rot, 0.13, 0.07, 0.14);
//	}
//}

void Fase_TheBlitz::desenhaBackground()
{
	/*criaDesenho(0);*/
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
	/*transladaCena2 -= 20;
	if (transladaCena2 <= -3240){
		cout << "entra";
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
