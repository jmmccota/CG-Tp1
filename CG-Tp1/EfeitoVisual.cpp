#include "EfeitoVisual.h"
#include <cmath>



EfeitoVisual::EfeitoVisual()
{
}


EfeitoVisual::~EfeitoVisual()
{
}

bool EfeitoVisual::Colisao(Solido *a, Solido *b)
{
	if ((abs(a->getX() - b->getX()) <= (a->getTamX() + b->getTamX()) / 2) ||
		(abs(a->getY() - b->getY()) <= (a->getTamY() + b->getTamY()) / 2))
		return true;
	return false;
}

bool EfeitoVisual::IsFullScreen() {
	return fullScreen;
}

void EfeitoVisual::Teclas(unsigned char tecla, GLint x, GLint y) {

	switch (tecla) {
		//A tecla 'f' alterna entre a tecla cheia (full screen) e não cheia.
	case 'f':
		if (!fullScreen) {
			glutFullScreen();
		}
		else {
			glutReshapeWindow(800, 600);
		}
		fullScreen = fullScreen;
		break;
	}
}