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
