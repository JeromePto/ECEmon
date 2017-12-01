/**
 * Project Untitled
 */


#include "CreatureJeu.h"
#include "JoueurPartie.h"

CreatureJeu::CreatureJeu()
    :m_carte(nullptr), m_PV(0), m_attaque()
{

}

void CreatureJeu::setCreature(CreatureFixe const* creature)
{
    m_carte = creature;
    m_PV = m_carte->getPV();
    m_attaque = m_carte->getAttaque();
}

CreatureFixe const* CreatureJeu::remplacerCreature(CreatureFixe const* creature)
{
    CreatureFixe const* tmp = m_carte;
    setCreature(creature);
    return tmp;
}

int CreatureJeu::getNombreAttaque() const
{
    return m_attaque.size();
}

bool CreatureJeu::attaquePossible(int attaque, EnergieJeu const& energie)
{
    return m_attaque[attaque].isPossible(energie.getEnergie());
}

int CreatureJeu::recevoirDegats(int degats)
{
    int sortie(degats);
    if(degats >= m_PV)
    {
        sortie -= m_PV;
        mourir();
    }
    else
    {
        sortie = 0;
        m_PV -= degats;
    }

    return sortie;
}

void CreatureJeu::mourir()
{
    m_carte = nullptr;
    m_attaque.clear();
    m_PV = 0;
}

int CreatureJeu::attaquer(int attaque, JoueurPartie & ennemi)
{
    int sortie(0);
    if(ennemi.recevoirDegats(m_attaque[attaque].getDegats()))
    {
        sortie = 1;
    }
    return sortie;
}

bool CreatureJeu::hasCreature() const
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

void CreatureJeu::display() const
{
    if(hasCreature())
    {
        m_carte->displayNom();
        std::cout << "PV = " << m_PV << std::endl;

        for(unsigned short i = 0 ; i < m_attaque.size() ; i++)
        {
            std::cout << "Attaque " << i+1 << " : ";
            m_attaque[i].dispalayAll();
        }
    }
}

void CreatureJeu::displayAttaque() const
{
    for(unsigned i = 0 ; i < m_attaque.size() ; ++i)
    {
        std::cout << i+1 << " : ";
        m_attaque[i].dispalayAll();
    }
}

