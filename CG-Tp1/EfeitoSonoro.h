#ifndef EFEITOSONORO_ABS
#define EFEITOSONORO_ABS


#ifdef _WIN32
#include <windows.h>
#endif
#include <GL/gl.h>
#include <GL/glut.h>
#include <conio.h>
#include <stdio.h>
#include "OpenAL/al.h"
#include "OpenAL/alc.h"


/*
	Classe usada para efeitos sonoros
		(efeito sonoro, musica, ...)
*/


class EfeitoSonoro
{
protected:
	ALCdevice* device = alcOpenDevice(NULL);
	ALCcontext* context = alcCreateContext(device, NULL);
	
public:
	EfeitoSonoro();
	~EfeitoSonoro();
	void MainTheme();
};



#endif