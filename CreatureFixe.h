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
#include "EnergieJeu.h"

class CreatureFixe: public CarteFixe {
private:
	int m_PV;
	std::string m_description;
	std::vector<Attaque> m_attaque;

public:
    CreatureFixe();
    CreatureFixe(std::string nom, unsigned int id, unsigned int prix, int PV, std::string description, std::vector<Attaque> attaque);

    ~CreatureFixe();

    void init(std::string nom, unsigned int id, unsigned int prix, int PV, std::string description, std::vector<Attaque> attaque);
    void initFichier(std::ifstream & fichier);

    int getPV() const;
    std::vector<Attaque> const& getAttaque() const;

    void displayAll() const;
    void displayNom() const;
    void displayJeu() const;
    void displayJeu(int pv) const;
};

#endif //_CREATUREFIXE_H
