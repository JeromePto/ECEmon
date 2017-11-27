/**
 * Project Untitled
 */


#ifndef _MENU_H
#define _MENU_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <ctype.h>

#include "enum.h"
#include "divers.h"
#include "JoueurMenu.h"
#include "CarteFixe.h"
#include "CreatureFixe.h"
#include "EnergieFixe.h"
#include "SpecialeFixe.h"
#include "SpecialeCourteFixe.h"
#include "SpecialePermanenteFixe.h"
#include "Equivalence.h"

#include "MenuMatch.h"

class Menu {

    friend MenuMatch;

private:
	std::vector<JoueurMenu> m_joueur;
	std::vector<CarteFixe*> m_carte;
	bool existNom(std::string const& nom);

public:
    Menu();

    ~Menu();

    short loadCartes();
    short loadJoueur();
    void loadFichier();

    void saveJoueur();

    void displayCartes() const;
    void displayJoueurs() const;

    void CreerJoueur();

};

#endif //_MENU_H
