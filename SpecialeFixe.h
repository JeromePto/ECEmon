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

class SpecialeFixe: public CarteFixe {
protected:
	std::string m_description;
	//bool m_permanente;
	unsigned m_code;

public:
    SpecialeFixe();
    SpecialeFixe(std::string nom, unsigned int id, unsigned int prix, std::string description, unsigned int numero);

    ~SpecialeFixe();

    void init(std::string nom, unsigned int id, unsigned int prix, std::string description, unsigned int numero);
    void initFichier(std::ifstream & fichier);

    virtual bool isPermanente() const = 0;

    void displayAll() const;
    void displayNom() const;
    void displayDescription() const;
    void displayJeu() const;
};

#endif //_SPECIALEFIXE_H
