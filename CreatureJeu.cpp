/**
 * Project Untitled
 */


#include "CreatureJeu.h"
#include "JoueurPartie.h"

CreatureJeu::CreatureJeu()
    :m_carte(nullptr), m_PV(0), m_attaque(), m_memeCreature(true)
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

CreatureFixe const* CreatureJeu::mourir()
{
    CreatureFixe const* tmp = m_carte;

    m_carte = nullptr;
    m_attaque.clear();
    m_PV = 0;
    m_memeCreature = false;

    return tmp;
}

int CreatureJeu::getNombreAttaque() const
{
    return m_attaque.size();
}

bool CreatureJeu::attaquePossible(int attaque, EnergieJeu const& energie) const
{
    return m_attaque[attaque].isPossible(energie.getEnergie());
}

bool CreatureJeu::attaquePossible(EnergieJeu const& energie) const
{
    bool sortie(false);

    for(short i = 0 ; i < getNombreAttaque() ; i++)
    {
        if(m_attaque[i].isPossible(energie.getEnergie()))
        {
            sortie = true;
        }
    }
    return sortie;
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


int CreatureJeu::attaquer(int attaque, JoueurPartie & ennemi)
{
    int sortie(0);
    if(ennemi.recevoirDegats(m_attaque[attaque].getDegats()))
    {
        sortie = 1;
    }
    return sortie;
}

void CreatureJeu::setReference()
{
    m_memeCreature = true;
}

bool CreatureJeu::getMemeCreature() const
{
    return m_memeCreature;
}

void CreatureJeu::augmenterDegats(int degats)
{
    for(unsigned short i = 0 ; i < m_attaque.size() ; i++)
    {
        m_attaque[i].augmenterDegats(degats);
    }
}

void CreatureJeu::augmenterPV(int PV)
{
    m_PV += PV;
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

void CreatureJeu::clear()
{
    m_carte = nullptr;
    m_PV = 0;
    m_attaque.clear();
    m_memeCreature = false;
}
