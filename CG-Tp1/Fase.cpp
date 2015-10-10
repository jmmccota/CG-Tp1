#include "Fase.hpp"

Fase::Fase()
{

}

Fase::~Fase()
{
    
}

void Fase::novoProjetil(Projetil *p)
{
    projeteis.push_back(p);
}
 