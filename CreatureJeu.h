/**
 * Project Untitled
 */


#ifndef _CREATUREJEU_H
#define _CREATUREJEU_H

#include "CreatureFixe.h"
#include "Attaque.h"


class CreatureJeu{
private:
	CreatureFixe const* m_carte;
	int m_PV;
	std::vector<Attaque> m_attaque;
};

#endif //_CREATUREJEU_H
