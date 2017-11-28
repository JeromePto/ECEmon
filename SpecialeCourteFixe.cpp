/**
 * Project Untitled
 */


#include "SpecialeCourteFixe.h"

SpecialeCourteFixe::SpecialeCourteFixe()
    :SpecialeFixe()
{

}

SpecialeCourteFixe::SpecialeCourteFixe(std::string nom, unsigned int id, unsigned int prix, std::string description, void(* code)(Match * match))
    :SpecialeFixe(nom, id, prix, description, code)
{

}

SpecialeCourteFixe::~SpecialeCourteFixe()
{

}

