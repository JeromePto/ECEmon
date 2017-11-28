/**
 * Project Untitled
 */


#ifndef _JOUEURPARTIE_H
#define _JOUEURPARTIE_H

#include <iostream>
#include <fstream>
#include <string>

#include "Deck.h"

class JoueurPartie {
private:
	Deck const* m_deck;
	int m_PV;
	std::string m_nom;

public:
    JoueurPartie();
    void init(std::string const& nom, Deck const* deck);
};

#endif //_JOUEURPARTIE_H
