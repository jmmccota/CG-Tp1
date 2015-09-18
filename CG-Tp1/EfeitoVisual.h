#ifndef EFEITOVISUAL_ABS
#define EFEITOVISUAL_ABS



#include <GL/gl.h>
#include <GL/glut.h>
#include "Solido.h"


/*
	Classe usada para efeitos visuais
		(deteccao de colisao, explosoes, ...)
*/


class EfeitoVisual
{
	public:
		EfeitoVisual();
		~EfeitoVisual();

		//COMO FAZER ANIMACAO EXPLOSAO?
		//void static Explosao(GLfloat x, GLfloat y, GLfloat raio, int estagio);
		
		//Retorna true caso objetos tenham colidido, false caso contrario
		bool static Colisao(Solido *a, Solido *b);
};




#endif