#ifndef EFEITOSONORO_ABS
#define EFEITOSONORO_ABS


#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include <conio.h>
#include <stdio.h>


/*
	Classe usada para efeitos sonoros
		(efeito sonoro, musica, ...)
*/


class EfeitoSonoro
{
protected:
	
	
public:
	EfeitoSonoro();
	~EfeitoSonoro();
	void MainTheme();
};



#endif