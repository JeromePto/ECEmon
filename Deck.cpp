/**
 * Project Untitled
 */


#include "Deck.h"

Deck::Deck()
    :m_carte(), m_nom("")
{

}

Deck::Deck(std::vector<CarteFixe const*> carte, std::string nom)
    :m_carte(carte), m_nom(nom)
{

}

Deck::~Deck()
{

}

void Deck::init(std::vector<CarteFixe const*>carte, std::string nom)
{
    m_carte = carte;
    m_nom = nom;
}

void Deck::initFichier(std::ifstream& fichier)
{
    std::string ligne;
    int nbCarte(0);

    //Lecture nom
    getline(fichier, ligne);
    m_nom = ligne;

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

void Deck::saveFichier(std::ofstream& fichier) const
{
    fichier << m_nom << std::endl;
    fichier << m_carte.size() << std::endl;
    for(auto it : m_carte)
    {
        fichier << Equivalence::toID(it) << std::endl;
    }
}

void Deck::setPD()
{
    std::ifstream fichier("ressources/deckPD.txt", std::ios_base::out);
    if(fichier)
    {
        initFichier(fichier);
    }
    else
    {
        exit(-6);
    }
}

void Deck::retirerCarte(CarteFixe const* carte)
{
    std::vector<CarteFixe const*>::iterator it;
    it = find(m_carte.begin(), m_carte.end(), carte);
    if(it != m_carte.end())
    {
        m_carte.erase(it);
    }
}

std::string Deck::getNom() const
{
    return m_nom;
}

bool Deck::deckValide() const
{
    return getTaille() == m_carte.size();
}

CarteFixe const* Deck::at(unsigned pos) const
{
    CarteFixe const* sortie(nullptr);
    if(pos < m_carte.size())
    {
        sortie = m_carte[pos];
    }
    return sortie;
}

unsigned Deck::size() const
{
    return m_carte.size();
}

void Deck::clear()
{
    m_carte.clear();
    m_nom.clear();
}

unsigned Deck::getTaille()
{
    static unsigned taille(0);

    std::string texte;

    if(taille == 0)
    {
        std::ifstream fichier("ressources/info.txt");
        getline(fichier, texte);
        getline(fichier, texte);
        taille = atoi(texte.c_str());
        fichier.close();
    }

    return taille;
}

void Deck::displayAll() const
{
    std::cout << "Deck : " << m_nom << std::endl << std::endl;
    for(std::vector<CarteFixe const*>::const_iterator it = m_carte.cbegin() ; it != m_carte.cend() ; ++it)
    {
        (*it)->displayAll();
        std::cout << std::endl;
    }
}

void Deck::displayNom() const
{
    std::cout << "Deck : " << m_nom << std::endl;
    for(std::vector<CarteFixe const*>::const_iterator it = m_carte.cbegin() ; it != m_carte.cend() ; ++it)
    {
        (*it)->displayNom();
    }
}
