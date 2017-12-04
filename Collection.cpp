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

void Collection::saveFichier(std::ofstream& fichier) const
{
    fichier <<  m_carte.size() << std::endl;
    for(auto it : m_carte)
    {
        fichier << Equivalence::toID(it) << std::endl;
    }
}

void Collection::setPD()
{
    std::ifstream fichier("ressources/collectionPD.txt");
    if(fichier)
    {
        initFichier(fichier);
    }
    else
    {
        exit(-5);
    }
}

std::vector<CarteFixe const*> const& Collection::getCartes() const
{
    return m_carte;
}

bool Collection::existID(int id) const
{
    bool sortie(false);
    for(std::vector<CarteFixe const*>::const_iterator it = m_carte.cbegin() ; it != m_carte.cend() ; ++it)
    {
        if(id > 0)
        {
            if((*it)->getID() == static_cast<unsigned int>(id))
            {
                sortie = true;
            }
        }
    }

    return sortie;
}

void Collection::ajouterCarte(CarteFixe const* carte)
{
    m_carte.push_back(carte);
}

void Collection::retirerCarte(CarteFixe const* carte)
{
    std::vector<CarteFixe const*>::iterator it;
    it = find(m_carte.begin(), m_carte.end(), carte);
    if(it != m_carte.end())
    {
        m_carte.erase(it);
    }
}

void Collection::displayAll() const
{
    std::cout << "Collection : " << m_carte.size() << " cartes" << std::endl << std::endl;
    for(std::vector<CarteFixe const*>::const_iterator it = m_carte.cbegin() ; it != m_carte.cend() ; ++it)
    {
        (*it)->displayAll();
        std::cout << std::endl;
    }
}

void Collection::displayNom() const
{
    std::cout << "Collection : " << m_carte.size() << " cartes" << std::endl << std::endl;
    for(std::vector<CarteFixe const*>::const_iterator it = m_carte.cbegin() ; it != m_carte.cend() ; ++it)
    {
        (*it)->displayNom();
    }
}
