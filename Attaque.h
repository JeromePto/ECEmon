/**
 * Project Untitled
 */


#ifndef _ATTAQUE_H
#define _ATTAQUE_H

#include <string>
#include <fstream>
#include <cstdlib>
#include <iostream>

#include "enum.h"

class Attaque {
private:
	int m_degats;
	int m_energie[5];
	std::string m_nom;

public:
    Attaque();
    Attaque(int degats, int energie[5], std::string nom);

    ~Attaque();

    void init(int degats, int energie[5], std::string nom);
    void initFichier(std::ifstream & fichier);

    bool isPossible(int const* tab) const;
    int getDegats() const;

    void augmenterDegats(int degats);

    void dispalayAll() const;
};

#endif //_ATTAQUE_H
