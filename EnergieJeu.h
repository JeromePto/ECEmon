/**
 * Project Untitled
 */


#ifndef _ENERGIEJEU_H
#define _ENERGIEJEU_H

#include <vector>

#include "EnergieFixe.h"

class EnergieJeu{
private:
	std::vector<EnergieFixe const*> m_carte;
	int m_energie[4];
};

#endif //_ENERGIEJEU_H
