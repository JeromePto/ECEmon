/**
 * Project Untitled
 */


#ifndef _CARTEFIXE_H
#define _CARTEFIXE_H

#include <string>
#include <fstream>
#include <map>

class CarteFixe {
protected:
	std::string m_nom;
	unsigned int m_id;

public:
    CarteFixe();
    CarteFixe(std::string nom, unsigned int id);

    virtual ~CarteFixe();

    virtual void init(std::string nom, unsigned int id);
    virtual void initFichier(std::ifstream & fichier) = 0;

    unsigned int getID() const;

    virtual void displayAll() const = 0;
    virtual void displayNom() const = 0;
};

#endif //_CARTEFIXE_H
