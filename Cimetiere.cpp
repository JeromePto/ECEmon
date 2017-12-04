/**
 * Project Untitled
 */


#include "Cimetiere.h"

Cimetiere::Cimetiere()
    :m_carte()
{

}

void Cimetiere::ajouterCarte(CarteFixe const* carte)
{
    m_carte.push_back(carte);
}

CarteFixe const* Cimetiere::recupererCarte()
{
    CarteFixe const* sortie;
    sortie = m_carte.back();
    m_carte.pop_back();
    return sortie;
}

void Cimetiere::clear()
{
    m_carte.clear();
}
