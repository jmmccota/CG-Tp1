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
	if ((abs(a->getX() - b->getX()) <= (a->getTamX() + b->getTamX())/2)||
		(abs(a->getY() - b->getY()) <= (a->getTamY() + b->getTamY())/2))
		return true;
	return false;
}
