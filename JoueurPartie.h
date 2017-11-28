/**
 * Project Untitled
 */


#ifndef _JOUEURPARTIE_H
#define _JOUEURPARTIE_H

#include <iostream>
#include <fstream>

#include "Deck.h"

class JoueurPartie {
private:
	Deck const* m_deck;
	int m_PV;

public:
    JoueurPartie();
    void setDeck(Deck const* deck);
};

#endif //_JOUEURPARTIE_H
