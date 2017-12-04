/**
 * Project Untitled
 */


#ifndef _PIOCHE_H
#define _PIOCHE_H

#include <deque>
#include <algorithm>

#include "CarteFixe.h"
#include "Deck.h"

class Pioche {
private:
	std::deque<CarteFixe const*> m_carte;
	int m_compteur;
	int m_taille;

public:
    Pioche();

    void init(Deck const* deck);

    CarteFixe const* tirerCarte();
    void remettreCarte(CarteFixe const* carte);

    void debutCompte();
    bool tourComplet();
    bool hasCarte() const;

    void clear();
};

#endif //_PIOCHE_H
