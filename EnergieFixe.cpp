/**
 * Project Untitled
 */


#include "EnergieFixe.h"

EnergieFixe::EnergieFixe()
    :CarteFixe(), m_domaine(static_cast<Domaine>(0))
{

}

EnergieFixe::EnergieFixe(std::string nom, Domaine domaine)
    :CarteFixe(nom), m_domaine(domaine)
{

}

EnergieFixe::~EnergieFixe()
{

}

void EnergieFixe::init(std::string nom, Domaine domaine)
{
    m_domaine = domaine;
}

void EnergieFixe::initFichier(std::ifstream& fichier)
{
    std::string ligne;

    //Lecture nom
    std::getline(fichier, ligne);
    CarteFixe::init(ligne);

    //Lecture domaine
    std::getline(fichier, ligne);
    m_domaine = static_cast<Domaine>(atoi(ligne.c_str()));
}

void EnergieFixe::displayAll() const
{
    std::cout << "Energie : " << m_nom << std::endl;
    std::cout << "Domaine = ";
    switch(m_domaine)
    {
    case DOMAINE1:
        std::cout << NENERGIE1 << std::endl;
        break;
    case DOMAINE2:
        std::cout << NENERGIE2 << std::endl;
        break;
    case DOMAINE3:
        std::cout << NENERGIE3 << std::endl;
        break;
    case DOMAINE4:
        std::cout << NENERGIE4 << std::endl;
        break;
    }
}
