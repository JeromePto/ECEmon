/**
 * Project Untitled
 */


#ifndef _SPECIALEPERMANENTEFIXE_H
#define _SPECIALEPERMANENTEFIXE_H

#include <string>

#include "SpecialeFixe.h"


class SpecialePermanenteFixe: public SpecialeFixe
{
public:
    SpecialePermanenteFixe();
    SpecialePermanenteFixe(std::string nom, unsigned int id, std::string description, void (*code)(Match * match));

    ~SpecialePermanenteFixe();

    bool isPermanente() const{return true;}
};

#endif //_SPECIALEPERMANENTEFIXE_H
