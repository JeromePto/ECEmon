/**
 * Project Untitled
 */


#ifndef _CREATUREFIXE_H
#define _CREATUREFIXE_H

#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <iostream>

#include "CarteFixe.h"
#include "Attaque.h"

class CreatureFixe: public CarteFixe {
private:
	int m_PV;
	std::vector<Attaque> m_attaque;

public:
    CreatureFixe();
    CreatureFixe(std::string nom, int PV, std::vector<Attaque> attaque);

    ~CreatureFixe();

    void init(std::string nom, int PV, std::vector<Attaque> attaque);
    void initFichier(std::ifstream & fichier);

    void displayAll() const;
};

#endif //_CREATUREFIXE_H
