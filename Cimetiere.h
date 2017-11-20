/**
 * Project Untitled
 */


#ifndef _CIMETIERE_H
#define _CIMETIERE_H

#include <deque>

#include "CarteFixe.h"

class Cimetiere {
private:
	std::deque<CarteFixe const*> m_carte;
};

#endif //_CIMETIERE_H
