/**
 * Project Untitled
 */


#include "EnergieJeu.h"

EnergieJeu::EnergieJeu()
    :m_carte(), m_energie{0, 0, 0, 0}
{

}

void EnergieJeu::calculeEnergie()
{
    short domaine(0);

    for(short i = 0 ; i < 4 ; ++i)
    {
        m_energie[i] = 0;
    }

    for(unsigned i = 0 ; i < m_carte.size() ; ++i)
    {
        domaine = m_carte[i]->getDomaine();
        m_energie[domaine]++;
    }
}

void EnergieJeu::ajouterEnergie(EnergieFixe const* carte)
{
    m_carte.push_back(carte);
    calculeEnergie();
}

int EnergieJeu::getNombreEnergie(int domaine) const
{
    int sortie(0);
    if(domaine >= 0 && domaine <= 4)
    {
        sortie = m_energie[domaine];
    }
    else
    {
        std::cerr << "Erreur de jeu 1" << std::endl;
        exit(-10);
    }

    return sortie;
}

int const* EnergieJeu::getEnergie() const
{
    return m_energie;
}

unsigned EnergieJeu::getNombreEnergie() const
{
    return m_carte.size();
}

EnergieFixe const* EnergieJeu::enleverEnergie(unsigned pos)
{
    EnergieFixe const* sortie(nullptr);

    if(pos >= 0 && pos < getNombreEnergie())
    {
        sortie = m_carte.at(pos);
        m_carte.erase(m_carte.begin() + pos);
    }
    else
    {
        std::cerr << "acces energie innexistante" << std::endl;
    }

    return sortie;
}

void EnergieJeu::display() const
{
    std::cout << "Energie :" << std::endl;
    std::cout << "- " << NENERGIE1 << " = " << getNombreEnergie(0) << std::endl;
    std::cout << "- " << NENERGIE2 << " = " << getNombreEnergie(1) << std::endl;
    std::cout << "- " << NENERGIE3 << " = " << getNombreEnergie(2) << std::endl;
    std::cout << "- " << NENERGIE4 << " = " << getNombreEnergie(3) << std::endl;
}

void EnergieJeu::clear()
{
    m_carte.clear();
    for(short i = 0 ; i < 4 ; ++i)
    {
        m_energie[i] = 0;
    }
}
