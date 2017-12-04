#ifndef MENUMATCH_H_INCLUDED
#define MENUMATCH_H_INCLUDED

#include <iostream>
#include <string>
#include <windows.h>
#include <ctype.h>

#include "JoueurMenu.h"
#include "Deck.h"

class Menu;
class Match;

class MenuMatch
{
public:
    static Menu * m_menu;
    static Match * m_match;

    static bool initJoueurMatch();

    static void gagnerCarteArgent(CarteFixe const* carte, std::string nom);
    static void perdreCarte(CarteFixe const* carte, std::string nom);
};

#endif // MENUMATCH_H_INCLUDED
