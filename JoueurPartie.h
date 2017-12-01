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

class JoueurPartie {
private:
	Deck const* m_deck;
	int m_PV;
	std::string m_nom;

	Pioche m_pioche;
	Enjeu m_enjeu;
	Cimetiere m_cimetiere;
	SpecialePermanenteJeu m_specialePermanente;
	EnergieJeu m_energie;
	CreatureJeu m_creature;

public:
    JoueurPartie();
    void preInit(std::string const& nom, Deck const* deck);
    void init();

    std::string getNom() const;
    int getPV() const;

    void displayPlateau() const;
    void displayAutreJoueur() const;

    int jouer(JoueurPartie & ennemi);
    bool recevoirDegats(int degats);
};

#endif //_JOUEURPARTIE_H
