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
    SpecialeCourteFixe(std::string nom, unsigned int id, unsigned int prix, std::string description, unsigned numero);

    ~SpecialeCourteFixe();

    bool isPermanente() const{return false;}
};

#endif //_SPECIALECOURTEFIXE_H
