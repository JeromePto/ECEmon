/**
 * Project Untitled
 */


#include "Enjeu.h"

Enjeu::Enjeu()
    :m_carte(nullptr)
{

}

void Enjeu::init(CarteFixe const* carte)
{
    m_carte = carte;
}

CarteFixe const* Enjeu::getEnjeu() const
{
    return m_carte;
}

void Enjeu::display() const
{
    m_carte->displayAll();
}

void Enjeu::clear()
{
    m_carte = nullptr;
}
