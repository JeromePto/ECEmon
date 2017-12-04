/**
 * Project Untitled
 */


#include "Attaque.h"

Attaque::Attaque()
    :m_degats(0), m_energie{0, 0, 0, 0, 0}, m_nom("")
{

}

Attaque::Attaque(int degats, int energie[5], std::string nom)
    :m_degats(degats), m_energie{0, 0, 0, 0, 0}, m_nom(nom)
{
    for(unsigned char i = 0 ; i < 5 ; ++i)
    {
        m_energie[i] = energie[i];
    }
}

Attaque::~Attaque()
{

}

void Attaque::init(int degats, int energie[5], std::string nom)
{
    m_degats = degats;
    m_nom = nom;

    for(unsigned char i = 0 ; i < 5 ; ++i)
    {
        m_energie[i] = energie[i];
    }
}

void Attaque::initFichier(std::ifstream& fichier)
{
    std::string ligne;

    //Lecture nom attaque
    std::getline(fichier, ligne);
    m_nom = ligne;

    //lecture degats
    std::getline(fichier, ligne);
    m_degats = atoi(ligne.c_str());

    //Lecture energie
    std::getline(fichier, ligne);
    for(unsigned short i = 0 ; i < 5 ; i++)
    {
        m_energie[i] = ligne[i] - '0';
    }

}

bool Attaque::isPossible(int const* tab) const
{
    bool sortie(true);
    int tmp[4] = {0, 0, 0, 0};
    int tmpAll(0);

    tmpAll = m_energie[4];
    for(short i = 0 ; i < 4 ; ++i)
    {
        tmp[i] = m_energie[i];
        tmp[i] -= tab[i];
    }
    for(short i = 0 ; i < 4 ; ++i)
    {
        if(tmp[i] > 0 && tmpAll >= tmp[i])
        {
            tmpAll -= tmp[i];
            tmp[i] = 0;
        }
    }
    for(short i = 0 ; i < 4 ; ++i)
    {
        if(tmp[i] > 0)
        {
            sortie = false;
        }
    }
    return sortie;
}

int Attaque::getDegats() const
{
    return m_degats;
}

void Attaque::augmenterDegats(int degats)
{
    if(m_degats + degats >= 0)
    {
        m_degats += degats;
    }
}

void Attaque::dispalayAll() const
{
    std::cout << m_nom << std::endl;
    std::cout << "Degats = " << m_degats << std::endl;

    std::cout << NENERGIE1 << " = " << m_energie[0] << std::endl;
    std::cout << NENERGIE2 << " = " << m_energie[1] << std::endl;
    std::cout << NENERGIE3 << " = " << m_energie[2] << std::endl;
    std::cout << NENERGIE4 << " = " << m_energie[3] << std::endl;
}
