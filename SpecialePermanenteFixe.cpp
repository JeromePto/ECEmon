/**
 * Project Untitled
 */


#include "SpecialePermanenteFixe.h"

SpecialePermanenteFixe::SpecialePermanenteFixe()
    :SpecialeFixe()
{

}

SpecialePermanenteFixe::SpecialePermanenteFixe(std::string nom, unsigned int id, unsigned int prix, std::string description, void(* code)(Match * match))
    :SpecialeFixe(nom, id, prix, description, code)
{

}

SpecialePermanenteFixe::~SpecialePermanenteFixe()
{

}

