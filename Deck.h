/**
 * Project Untitled
 */


#ifndef _DECK_H
#define _DECK_H

#include <vector>
#include <fstream>
#include <cstdlib>

#include "CarteFixe.h"
#include "Equivalence.h"

class Deck {
private:
	std::vector<CarteFixe const*> m_carte;

public:
    Deck();

    ~Deck();

    void init(std::vector<CarteFixe const*> carte);
    void initFichier(std::ifstream & fichier);
    void saveFichier(std::ofstream & fichier);
};

#endif //_DECK_H
