/**
 * Project Untitled
 */


#ifndef _JOUEURPARTIE_H
#define _JOUEURPARTIE_H

#include <iostream>
#include <fstream>
#include <string>
#include <ctype.h>

#include "enum.h"
#include "Deck.h"
#include "Cimetiere.h"
#include "Pioche.h"
#include "CreatureJeu.h"
#include "Enjeu.h"
#include "SpecialePermanenteJeu.h"
#include "EnergieJeu.h"
#include "CarteFixe.h"
#include "CodeSpeciale.h"
#include "divers.h"

class JoueurPartie
{

    friend CodeSpeciale;

private:
	Deck const* m_deck;
	int m_PV;
	std::string m_nom;
	bool m_AI;

	Pioche m_pioche;
	Enjeu m_enjeu;
	Cimetiere m_cimetiere;
	SpecialePermanenteJeu m_specialePermanente;
	EnergieJeu m_energie;
	CreatureJeu m_creature;

	CodeSpeciale m_codeSpeciale;

public:
    JoueurPartie();
    ~JoueurPartie();
    void preInit(std::string const& nom, Deck const* deck);
    void preInitAI();
    void init(JoueurPartie & ennemi);

    std::string getNom() const;
    int getPV() const;
    bool getAI() const;
    CarteFixe const* getEnjeu() const;

    void displayPlateau() const;
    void displayAutreJoueur() const;

    int jouer(JoueurPartie & ennemi);
    int jouerAI(JoueurPartie & ennemi);
    bool recevoirDegats(int degats);

    void clear();
};

#endif //_JOUEURPARTIE_H
