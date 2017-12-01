/**
 * Project Untitled
 */


#ifndef _ENJEU_H
#define _ENJEU_H

#include "CarteFixe.h"

class Enjeu {
private:
	CarteFixe const* m_carte;

public:
    Enjeu();

    void init(CarteFixe const* carte);
};

#endif //_ENJEU_H
