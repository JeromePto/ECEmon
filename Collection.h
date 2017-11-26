/**
 * Project Untitled
 */


#ifndef _COLLECTION_H
#define _COLLECTION_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "CarteFixe.h"
#include "Equivalence.h"


class Collection {
private:
	std::vector<CarteFixe const*> m_carte;

public:
    Collection();

    ~Collection();

    void init(std::vector<CarteFixe const*> carte);
    void initFichier(std::ifstream & fichier);
    void saveFichier(std::ofstream & fichier) const;

    void setPD();

    void displayAll() const;
    void displayNom() const;
};

#endif //_COLLECTION_H
