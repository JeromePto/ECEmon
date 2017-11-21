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

class Menu {
private:
	std::vector<JoueurMenu> m_joueur;
	std::vector<CarteFixe*> m_carte;

public:
    Menu();

    ~Menu();

    short loadCartes();
    short loadJoueur();
    void loadFichier();

    void saveJoueur();

    void displayAll() const;

};

#endif //_MENU_H
