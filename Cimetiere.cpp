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
