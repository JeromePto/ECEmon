/** * Project Untitled
 */


#include "CarteFixe.h"

CarteFixe::CarteFixe()
    :m_nom(""), m_id(0)
{

}

CarteFixe::CarteFixe(std::string nom, unsigned int id)
    :m_nom(nom), m_id(id)
{

}

CarteFixe::~CarteFixe()
{

}

unsigned int CarteFixe::getID() const
{
    return m_id;
}


void CarteFixe::init(std::string nom, unsigned int id)
{
    m_nom = nom;
    m_id = id;

}

