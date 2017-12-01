/**
 * Project Untitled
 */


#ifndef _CIMETIERE_H
#define _CIMETIERE_H

#include <deque>

#include "CarteFixe.h"

class Cimetiere {
private:
	std::deque<CarteFixe const*> m_carte;

public:
    Cimetiere();

    void ajouterCarte(CarteFixe const* carte);
};

#endif //_CIMETIERE_H
