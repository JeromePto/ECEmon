/**
 * Project Untitled
 */


#include "SpecialeCourteFixe.h"

SpecialeCourteFixe::SpecialeCourteFixe()
    :SpecialeFixe()
{

}

SpecialeCourteFixe::SpecialeCourteFixe(std::string nom, std::string description, void(* code)(Match * match))
    :SpecialeFixe(nom, description, code)
{

}

SpecialeCourteFixe::~SpecialeCourteFixe()
{

}

