#include "Solido.h"

void Solido::desenha()
{
    for (int i = 0; i < nPoligonos; i++)
    {
        poligonos[i].desenha(posX, posY);
    }
}

Solido::Solido()
{
}

Solido::~Solido()
{
}