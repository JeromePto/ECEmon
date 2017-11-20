/**
 * Project Untitled
 */


#include "CreatureFixe.h"

CreatureFixe::CreatureFixe()
    :CarteFixe(), m_PV(0), m_attaque()
{

}

CreatureFixe::CreatureFixe(std::string nom, int PV, std::vector<Attaque> attaque)
    :CarteFixe(nom), m_PV(PV), m_attaque(attaque)
{

}

CreatureFixe::~CreatureFixe()
{

}

void CreatureFixe::init(std::string nom, int PV, std::vector<Attaque> attaque)
{
    CarteFixe::init(nom);
    m_PV = PV;
    m_attaque = attaque;
}

void CreatureFixe::initFichier(std::ifstream & fichier)
{
    std::string ligne;
    short nbAttaque(0);

    //Lecture nom
    std::getline(fichier, ligne);
    CarteFixe::init(ligne);

    //Lecture PV
    std::getline(fichier, ligne);
    m_PV = atoi(ligne.c_str());

    //Lecture attaque
    std::getline(fichier, ligne);
    nbAttaque = atoi(ligne.c_str());

    for(unsigned short i = 0 ; i < nbAttaque ; ++i)
    {
        m_attaque.push_back(Attaque());
        m_attaque[i].initFichier(fichier);
    }

}

void CreatureFixe::displayAll() const
{
    std::cout << "Creature : " << m_nom << std::endl;
    std::cout << "PV = " << m_PV << std::endl;

    for(unsigned short i = 0 ; i < m_attaque.size() ; i++)
    {
        std::cout << "Attaque " << i+1 << " : ";
        m_attaque[i].dispalayAll();
    }
}
