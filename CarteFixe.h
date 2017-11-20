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

public:
    CarteFixe();
    CarteFixe(std::string nom);

    virtual ~CarteFixe();

    virtual void init(std::string nom);
    virtual void initFichier(std::ifstream & fichier) = 0;

    virtual void displayAll() const = 0;
};

#endif //_CARTEFIXE_H
