/**
 * Project Untitled
 */


#include "EnergieFixe.h"

EnergieFixe::EnergieFixe()
    :CarteFixe(), m_domaine(static_cast<Domaine>(0))
{

}

EnergieFixe::EnergieFixe(std::string nom, unsigned int id, unsigned int prix, Domaine domaine)
    :CarteFixe(nom, id, prix), m_domaine(domaine)
{

}

EnergieFixe::~EnergieFixe()
{

}

void EnergieFixe::init(std::string nom, unsigned int id, unsigned int prix, Domaine domaine)
{
    CarteFixe::init(nom, id, prix);
    m_domaine = domaine;
}

void EnergieFixe::initFichier(std::ifstream& fichier)
{
    std::string ligne;

    CarteFixe::initFichier(fichier);

    //Lecture domaine
    std::getline(fichier, ligne);
    m_domaine = static_cast<Domaine>(atoi(ligne.c_str()));
}

Domaine EnergieFixe::getDomaine() const
{
    return m_domaine;
}

void EnergieFixe::displayAll() const
{
    std::cout << "Energie : " << m_nom << std::endl;
    std::cout << "ID = " << m_id << std::endl;
    std::cout << "Prix = " << m_prix << std::endl;
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

void EnergieFixe::displayNom() const
{
    std::cout << "Energie : " << m_nom << std::endl;
}

void EnergieFixe::displayJeu() const
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
