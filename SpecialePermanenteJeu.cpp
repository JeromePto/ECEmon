/**
 * Project Untitled
 */


#include "SpecialePermanenteJeu.h"
#include "SpecialePermanenteFixe.h"

SpecialePermanenteJeu::SpecialePermanenteJeu()
    :m_carte(nullptr)
{

}

void SpecialePermanenteJeu::setSpecialePermanente(SpecialePermanenteFixe const* carte)
{
    m_carte = carte;
}

SpecialePermanenteFixe const* SpecialePermanenteJeu::remplacerSpecialePermanente(SpecialePermanenteFixe const* speciale)
{
    SpecialePermanenteFixe const* tmp = m_carte;
    setSpecialePermanente(speciale);
    return tmp;
}

bool SpecialePermanenteJeu::hasSpecialePermanente() const
{
    bool sortie(false);

    if(m_carte == nullptr)
    {
        sortie = false;
    }
    else
    {
        sortie = true;
    }

    return sortie;
}

void SpecialePermanenteJeu::display() const
{
    if(hasSpecialePermanente())
    {
        m_carte->displayNom();
        m_carte->displayDescription();
    }
}

void SpecialePermanenteJeu::clear()
{
    m_carte = nullptr;
}
