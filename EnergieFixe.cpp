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
    std::string tmpNom;
    unsigned int tmpID;

    //Lecture nom
    std::getline(fichier, tmpNom);

    //Lecture ID
    std::getline(fichier, ligne);
    tmpID = atoi(ligne.c_str());

    //Lecture prix
    std::getline(fichier, ligne);
    CarteFixe::init(tmpNom, tmpID, atoi(ligne.c_str()));

    //Lecture domaine
    std::getline(fichier, ligne);
    m_domaine = static_cast<Domaine>(atoi(ligne.c_str()));
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
