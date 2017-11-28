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


void CarteFixe::init(std::string nom, unsigned int id, unsigned int prix)
{
    m_nom = nom;
    m_id = id;
    m_prix = prix;
}

