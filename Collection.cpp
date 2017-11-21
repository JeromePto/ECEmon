/**
 * Project Untitled
 */


#include "Collection.h"

Collection::Collection()
    :m_carte()
{

}

Collection::~Collection()
{

}

void Collection::init(std::vector<CarteFixe const*>carte)
{
    m_carte = carte;
}

void Collection::initFichier(std::ifstream& fichier)
{
    std::string ligne;
    int nbCarte(0);

    //Lecture nombre carte
    getline(fichier, ligne);
    nbCarte = atoi(ligne.c_str());

    //Lecture cartes collection
    for(int i = 0 ; i < nbCarte ; ++i)
    {
        getline(fichier, ligne);
        m_carte.push_back(Equivalence::toPointer(atoi(ligne.c_str())));
    }

}

void Collection::saveFichier(std::ofstream& fichier)
{
    fichier <<  m_carte.size() << std::endl;
    for(auto it : m_carte)
    {
        fichier << Equivalence::toID(it) << std::endl;
    }
}
