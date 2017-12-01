/**
 * Project Untitled
 */


#ifndef _CREATUREJEU_H
#define _CREATUREJEU_H

#include <iostream>

#include "CreatureFixe.h"
#include "Attaque.h"
#include "EnergieJeu.h"

class JoueurPartie;

class CreatureJeu
{
private:
	CreatureFixe const* m_carte;
	int m_PV;
	std::vector<Attaque> m_attaque;

public:
    CreatureJeu();

    void setCreature(CreatureFixe const* creature);
    CreatureFixe const* remplacerCreature(CreatureFixe const* creature);

    int getNombreAttaque() const;
    bool attaquePossible(int attaque, EnergieJeu const& energie);

    int recevoirDegats(int degats);
    void mourir();
    int attaquer(int attaque, JoueurPartie & ennemi);

    bool hasCreature() const;
    void display() const;
    void displayAttaque() const;
};

#endif //_CREATUREJEU_H
