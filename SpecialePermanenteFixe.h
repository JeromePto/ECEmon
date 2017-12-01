/**
 * Project Untitled
 */


#ifndef _SPECIALEPERMANENTEFIXE_H
#define _SPECIALEPERMANENTEFIXE_H

#include <string>

#include "SpecialeFixe.h"

class Match;

class SpecialePermanenteFixe: public SpecialeFixe
{
public:
    SpecialePermanenteFixe();
    SpecialePermanenteFixe(std::string nom, unsigned int id, unsigned int prix, std::string description, unsigned numero);

    ~SpecialePermanenteFixe();

    bool isPermanente() const{return true;}
};

#endif //_SPECIALEPERMANENTEFIXE_H
