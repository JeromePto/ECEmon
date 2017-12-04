/**
 * Project Untitled
 */


#ifndef _ENJEU_H
#define _ENJEU_H

#include <iostream>

#include "CarteFixe.h"

class Enjeu {
private:
	CarteFixe const* m_carte;

public:
    Enjeu();

    void init(CarteFixe const* carte);

    CarteFixe const* getEnjeu() const;

    void display() const;

    void clear();
};

#endif //_ENJEU_H
