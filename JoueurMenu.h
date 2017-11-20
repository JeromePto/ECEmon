/**
 * Project Untitled
 */


#ifndef _JOUEURMENU_H
#define _JOUEURMENU_H

#include <string>
#include <vector>

#include "Collection.h"
#include "Deck.h"

class JoueurMenu {
private:
	std::string m_nom;
	Collection m_collection;
	std::vector<Deck> m_deck;
	int m_argent;
};

#endif //_JOUEURMENU_H
