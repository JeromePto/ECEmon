/**
 * Project Untitled
 */


#include "SpecialePermanenteFixe.h"

SpecialePermanenteFixe::SpecialePermanenteFixe()
    :SpecialeFixe()
{

}

SpecialePermanenteFixe::SpecialePermanenteFixe(std::string nom, std::string description, void(* code)(Match * match))
    :SpecialeFixe(nom, description, code)
{

}

SpecialePermanenteFixe::~SpecialePermanenteFixe()
{

}

