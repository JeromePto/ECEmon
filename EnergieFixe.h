/**
 * Project Untitled
 */


#ifndef _ENERGIEFIXE_H
#define _ENERGIEFIXE_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "enum.h"
#include "CarteFixe.h"


class EnergieFixe: public CarteFixe {
private:
	Domaine m_domaine;

public:
    EnergieFixe();
    EnergieFixe(std::string nom, unsigned int id, Domaine domaine);

    ~EnergieFixe();

    void init(std::string nom, unsigned int id, Domaine domaine);
    void initFichier(std::ifstream & fichier);

    void displayAll() const;
    void displayNom() const;
};

#endif //_ENERGIEFIXE_H
