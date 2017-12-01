/**
 * Project Untitled
 */


#include "CreatureFixe.h"

CreatureFixe::CreatureFixe()
    :CarteFixe(), m_PV(0), m_attaque()
{

}

CreatureFixe::CreatureFixe(std::string nom, unsigned int id, unsigned int prix, int PV, std::string description, std::vector<Attaque> attaque)
    :CarteFixe(nom, id, prix), m_PV(PV), m_description(description), m_attaque(attaque)
{

}

CreatureFixe::~CreatureFixe()
{

}

void CreatureFixe::init(std::string nom, unsigned int id, unsigned int prix, int PV, std::string description, std::vector<Attaque> attaque)
{
    CarteFixe::init(nom, id, prix);
    m_PV = PV;
    m_description = description;
    m_attaque = attaque;
}

void CreatureFixe::initFichier(std::ifstream & fichier)
{
    std::string ligne;
    short nbAttaque(0);

    CarteFixe::initFichier(fichier);

    //Lecture PV
    std::getline(fichier, ligne);
    m_PV = atoi(ligne.c_str());

    //Lecture description
    std::getline(fichier, m_description);

    //Lecture attaque
    std::getline(fichier, ligne);
    nbAttaque = atoi(ligne.c_str());

    for(unsigned short i = 0 ; i < nbAttaque ; ++i)
    {
        m_attaque.push_back(Attaque());
        m_attaque[i].initFichier(fichier);
    }

}

int CreatureFixe::getPV() const
{
    return m_PV;
}

std::vector<Attaque> const& CreatureFixe::getAttaque() const
{
    return m_attaque;
}

void CreatureFixe::displayAll() const
{
    std::cout << "Creature : " << m_nom << std::endl;
    std::cout << m_description << std::endl;
    std::cout << "ID = " << m_id << std::endl;
    std::cout << "Prix = " << m_prix << std::endl;
    std::cout << "PV = " << m_PV << std::endl;

    for(unsigned short i = 0 ; i < m_attaque.size() ; i++)
    {
        std::cout << "Attaque " << i+1 << " : ";
        m_attaque[i].dispalayAll();
    }
}

void CreatureFixe::displayNom() const
{
    std::cout << "Creature : " << m_nom << std::endl;
}

void CreatureFixe::displayJeu() const
{
    std::cout << "Creature : " << m_nom << std::endl;
    std::cout << m_description << std::endl;
    std::cout << "PV = " << m_PV << std::endl;
    for(unsigned short i = 0 ; i < m_attaque.size() ; i++)
    {
        std::cout << "Attaque " << i+1 << " : ";
        m_attaque[i].dispalayAll();
    }
}

void CreatureFixe::displayJeu(int pv) const
{
    std::cout << "Creature : " << m_nom << std::endl;
    std::cout << m_description << std::endl;
    std::cout << "PV = " << pv << std::endl;
    for(unsigned short i = 0 ; i < m_attaque.size() ; i++)
    {
        std::cout << "Attaque " << i+1 << " : ";
        m_attaque[i].dispalayAll();
    }
}
