/**
 * Project Untitled
 */


#include "SpecialePermanenteFixe.h"

SpecialePermanenteFixe::SpecialePermanenteFixe()
    :SpecialeFixe()
{

}

SpecialePermanenteFixe::SpecialePermanenteFixe(std::string nom, unsigned int id, std::string description, void(* code)(Match * match))
    :SpecialeFixe(nom, id, description, code)
{

}

SpecialePermanenteFixe::~SpecialePermanenteFixe()
{

}

