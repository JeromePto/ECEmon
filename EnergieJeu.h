/**
 * Project Untitled
 */


#ifndef _ENERGIEJEU_H
#define _ENERGIEJEU_H

#include <vector>
#include <iostream>

#include "EnergieFixe.h"
#include "enum.h"

class EnergieJeu{
private:
	std::vector<EnergieFixe const*> m_carte;
	int m_energie[4];

	void calculeEnergie();

public:
    EnergieJeu();

    void ajouterEnergie(EnergieFixe const* carte);
    int getNombreEnergie(int domaine) const;
    int const* getEnergie() const;
    unsigned getNombreEnergie() const;
    EnergieFixe const* enleverEnergie(unsigned pos);

    void display() const;

    void clear();
};

#endif //_ENERGIEJEU_H
