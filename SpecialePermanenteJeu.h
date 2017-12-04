/**
 * Project Untitled
 */


#ifndef _SPECIALEPERMANENTEJEU_H
#define _SPECIALEPERMANENTEJEU_H

//#include "SpecialePermanenteFixe.h"

class SpecialePermanenteFixe;

class SpecialePermanenteJeu{
private:
	SpecialePermanenteFixe const* m_carte;

public:
    SpecialePermanenteJeu();

    void setSpecialePermanente(SpecialePermanenteFixe const* carte);
    SpecialePermanenteFixe const* remplacerSpecialePermanente(SpecialePermanenteFixe const* speciale);

    bool hasSpecialePermanente() const;

    void display() const;

    void clear();
};

#endif //_SPECIALEPERMANENTEJEU_H
