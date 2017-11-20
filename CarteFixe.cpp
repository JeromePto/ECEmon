/**
 * Project Untitled
 */


#include "CarteFixe.h"

CarteFixe::CarteFixe()
    :m_nom("")
{

}

CarteFixe::CarteFixe(std::string nom)
    :m_nom(nom)
{

}

CarteFixe::~CarteFixe()
{

}

void CarteFixe::init(std::string nom)
{
    m_nom = nom;
}
