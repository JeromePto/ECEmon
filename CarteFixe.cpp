/**
 * Project Untitled
 */


#include "CarteFixe.h"

CarteFixe::CarteFixe()
    :m_nom(""), m_id(0), m_prix(0)
{

}

CarteFixe::CarteFixe(std::string nom, unsigned int id, unsigned int prix)
    :m_nom(nom), m_id(id), m_prix(prix)
{

}

CarteFixe::~CarteFixe()
{

}

unsigned int CarteFixe::getID() const
{
    return m_id;
}

unsigned CarteFixe::getPrix() const
{
    return m_prix;
}

void CarteFixe::init(std::string nom, unsigned int id, unsigned int prix)
{
    m_nom = nom;
    m_id = id;
    m_prix = prix;
}

void CarteFixe::initFichier(std::ifstream & fichier)
{
    std::string ligne;

    //Lecture nom
    std::getline(fichier, m_nom);

    //Lecture ID
    std::getline(fichier, ligne);
    m_id = atoi(ligne.c_str());

    //Lecture prix
    std::getline(fichier, ligne);
    m_prix = atoi(ligne.c_str());
}
