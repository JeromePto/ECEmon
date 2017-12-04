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
	bool m_memeCreature;

public:
    CreatureJeu();

    void setCreature(CreatureFixe const* creature);
    CreatureFixe const* remplacerCreature(CreatureFixe const* creature);
    CreatureFixe const* mourir();

    int getNombreAttaque() const;
    bool attaquePossible(int attaque, EnergieJeu const& energie) const;
    bool attaquePossible(EnergieJeu const& energie) const;

    int recevoirDegats(int degats);
    int attaquer(int attaque, JoueurPartie & ennemi);

    void setReference();
    bool getMemeCreature() const;
    void augmenterDegats(int degats);
    void augmenterPV(int PV);

    bool hasCreature() const;
    void display() const;
    void displayAttaque() const;

    void clear();
};

#endif //_CREATUREJEU_H
