/**
 * Project Untitled
 */


#ifndef _SPECIALEFIXE_H
#define _SPECIALEFIXE_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#include "CarteFixe.h"
#include "codeSpeciale.h"

class SpecialePermanenteFixe;

class SpecialeFixe: public CarteFixe {
protected:
	std::string m_description;
	bool permanente;
	void (*m_code)(Match *);

public:
    SpecialeFixe();
    SpecialeFixe(std::string nom, unsigned int id, std::string description, void (*code)(Match * match));
    SpecialeFixe(std::string nom, unsigned int id, std::string description, unsigned int numero);

    ~SpecialeFixe();

    void init(std::string nom, unsigned int id, std::string description, void (*code)(Match * match));
    void init(std::string nom, unsigned int id, std::string description, unsigned int numero);
    void initFichier(std::ifstream & fichier);

    virtual bool isPermanente() const = 0;

    void displayAll() const;
    void displayNom() const;
};

#endif //_SPECIALEFIXE_H
