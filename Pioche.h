/**
 * Project Untitled
 */


#ifndef _PIOCHE_H
#define _PIOCHE_H

#include <deque>

#include "CarteFixe.h"

class Pioche {
private:
	std::deque<CarteFixe const*> m_carte;
};

#endif //_PIOCHE_H
