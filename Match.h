/**
 * Project Untitled
 */


#ifndef _MATCH_H
#define _MATCH_H

#include <iostream>
#include <windows.h>

#include "MenuMatch.h"
#include "JoueurPartie.h"

class Match {

    friend MenuMatch;

private:
	JoueurPartie m_joueur1;
	JoueurPartie m_joueur2;

	bool preMatch();
	void postMatch(int gagnant);

public:
    Match();

    void mainMatch();

    void clear();
};

#endif //_MATCH_H
