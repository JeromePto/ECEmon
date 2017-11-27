/**
 * Project Untitled
 */


#ifndef _CARTEFIXE_H
#define _CARTEFIXE_H

#include <string>
#include <fstream>

class CarteFixe {
protected:
	std::string m_nom;
	unsigned int m_id;
	unsigned int m_prix;

public:
    CarteFixe();
    CarteFixe(std::string nom, unsigned int id, unsigned int prix);

    virtual ~CarteFixe();

    virtual void init(std::string nom, unsigned int id, unsigned int prix);
    virtual void initFichier(std::ifstream & fichier) = 0;

    unsigned int getID() const;

    virtual void displayAll() const = 0;
    virtual void displayNom() const = 0;
};

#endif //_CARTEFIXE_H
