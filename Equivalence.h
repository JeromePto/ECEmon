#ifndef EQUIVALENCE_H_INCLUDED
#define EQUIVALENCE_H_INCLUDED

#include <map>
#include <vector>

#include "CarteFixe.h"


namespace Equivalence
{
    void init(std::vector<CarteFixe*> carte);

    CarteFixe const* toPointer(unsigned int id);
    unsigned int toID(CarteFixe const* pointer);
};

#endif // EQUIVALENCE_H_INCLUDED
