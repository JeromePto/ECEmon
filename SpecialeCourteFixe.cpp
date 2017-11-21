/**
 * Project Untitled
 */


#include "SpecialeCourteFixe.h"

SpecialeCourteFixe::SpecialeCourteFixe()
    :SpecialeFixe()
{

}

SpecialeCourteFixe::SpecialeCourteFixe(std::string nom, unsigned int id, std::string description, void(* code)(Match * match))
    :SpecialeFixe(nom, id, description, code)
{

}

SpecialeCourteFixe::~SpecialeCourteFixe()
{

}

