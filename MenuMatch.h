#ifndef MENUMATCH_H_INCLUDED
#define MENUMATCH_H_INCLUDED

#include <iostream>
#include <string>
#include <windows.h>
#include <ctype.h>

#include "JoueurMenu.h"

class Menu;
class Match;

class MenuMatch
{
public:
    static Menu * m_menu;
    static Match * m_match;

    static void lancerMatch();
};

#endif // MENUMATCH_H_INCLUDED
