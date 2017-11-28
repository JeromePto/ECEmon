/**
 * Project Untitled
 */


#ifndef _MATCH_H
#define _MATCH_H

#include "JoueurPartie.h"

#include "MenuMatch.h"

class Match {

    friend MenuMatch;

private:
	JoueurPartie m_joueur1;
	JoueurPartie m_joueur2;

public:
    Match();

    void initPostJoueur();
};

#endif //_MATCH_H
