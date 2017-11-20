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
    EnergieFixe(std::string nom, Domaine domaine);

    ~EnergieFixe();

    void init(std::string nom, Domaine domaine);
    void initFichier(std::ifstream & fichier);

    void displayAll() const;
};

#endif //_ENERGIEFIXE_H
