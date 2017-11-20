/**
 * Project Untitled
 */


#ifndef _SPECIALECOURTEFIXE_H
#define _SPECIALECOURTEFIXE_H

#include <string>

#include "SpecialeFixe.h"


class SpecialeCourteFixe: public SpecialeFixe {
public:
    SpecialeCourteFixe();
    SpecialeCourteFixe(std::string nom, std::string description, void (*code)(Match * match));

    ~SpecialeCourteFixe();

    bool isPermanente() const{return false;}
};

#endif //_SPECIALECOURTEFIXE_H
