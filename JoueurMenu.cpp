/**
 * Project Untitled
 */


#include "JoueurMenu.h"

JoueurMenu::JoueurMenu()
    :m_nom() , m_collection(), m_deck(), m_argent(0)
{

}

JoueurMenu::JoueurMenu(std::string const& nom)
    :m_nom(nom) , m_collection(), m_deck(), m_argent(1000)
{
    Deck tmp;
    tmp.setPD();
    m_collection.setPD();
    m_deck.push_back(tmp);
}

bool JoueurMenu::existNomDeck(std::string const& nom) const
{
    bool sortie(false);

    for(std::vector<Deck>::const_iterator it = m_deck.cbegin() ; it != m_deck.cend() ; ++it)
    {
        if(it->getNom() == nom)
        {
            sortie = true;
        }
    }

    return sortie;
}

Deck const* JoueurMenu::deckToPointer(std::string const& nom) const
{
    Deck const* sortie(nullptr);

    for(unsigned int i = 0 ; i < m_deck.size() ; ++i)
    {
        if(m_deck[i].getNom() == nom)
        {
            sortie = &m_deck[i];
        }
    }

    return sortie;
}

JoueurMenu::~JoueurMenu()
{

}

void JoueurMenu::init(std::string nom, Collection collection, std::vector<Deck> deck, int argent)
{
    m_nom = nom;
    m_collection = collection;
    m_deck = deck;
    m_argent = argent;
}

void JoueurMenu::initFichier(std::ifstream& fichier)
{
    std::string ligne;
    int nbDeck(0);
    Deck tmp;

    //Lecture nom
    std::getline(fichier, ligne);
    m_nom = ligne;

    //Lecture argent
    std::getline(fichier, ligne);
    m_argent = atoi(ligne.c_str());

    //lecture collection
    m_collection.initFichier(fichier);

    //lecture decks
    std::getline(fichier, ligne);
    nbDeck = atoi(ligne.c_str());

    for(int i = 0 ; i < nbDeck ; ++i)
    {
        tmp.initFichier(fichier);
        m_deck.push_back(tmp);
    }

}

void JoueurMenu::saveFichier(std::ofstream& fichier)
{
    fichier << m_nom << std::endl;
    fichier << m_argent << std::endl;
    m_collection.saveFichier(fichier);
    fichier << m_deck.size() << std::endl;
    for(unsigned int i = 0 ; i < m_deck.size() ; ++i)
    {
        m_deck[i].saveFichier(fichier);
    }
}

std::string JoueurMenu::getNom() const
{
    return m_nom;
}

void JoueurMenu::displayAll() const
{
    std::cout << "Joueur : " << m_nom << std::endl;
    std::cout << "Argent : " << m_argent << std::endl;
    m_collection.displayAll();
    std::cout << m_deck.size() << " decks :" << std::endl;
    for(unsigned int i = 0 ; i < m_deck.size() ; ++i)
    {
        m_deck[i].displayAll();
    }
}

void JoueurMenu::displayCourt() const
{
    std::cout << "Joueur : " << m_nom << std::endl;
    std::cout << "Argent : " << m_argent << std::endl;
    m_collection.displayNom();
    std::cout << std::endl;
    std::cout << m_deck.size() << " decks :" << std::endl << std::endl;
    for(unsigned int i = 0 ; i < m_deck.size() ; ++i)
    {
        m_deck[i].displayNom();
    }
}

void JoueurMenu::displayDeckNom(std::string avant) const
{
    for(unsigned int i = 0 ; i < m_deck.size() ; ++i)
    {
        std::cout << avant << m_deck[i].getNom() << std::endl;
    }
}
