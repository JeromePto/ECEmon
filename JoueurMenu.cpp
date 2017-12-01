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

void JoueurMenu::creerDeck()
{
    unsigned taille(0);
    std::string texte;
    std::string chiffre;
    std::vector<int> input;
    std::vector<CarteFixe const*> carte;
    std::istringstream ligne;

    /// Taille du deck
    std::ifstream fichier("ressources/info.txt");
    getline(fichier, texte);
    getline(fichier, texte);
    taille = atoi(texte.c_str());
    fichier.close();

    m_collection.displayAll();
    std::cout << std::endl;
    std::cout << "Entrer les id des " << taille << " cartes de votres deck separee par des espaces" << std::endl;
    do
    {
        ligne.clear();
        input.clear();
        std::cout << "IDs : ";
        std::getline(std::cin, texte);
        ligne.str(texte);
        for(unsigned i = 0 ; i < taille ; ++i)
        {
            ligne >> chiffre;
            input.push_back(atoi(chiffre.c_str()));
        }
    }while(!isInCollection(input, m_collection, carte, taille));

    std::cout << "Donnez un nom au deck : ";
    getline(std::cin, texte);

    m_deck.push_back(Deck(carte, texte));
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

bool isInCollection(std::vector<int> id, Collection const& collection, std::vector<CarteFixe const*> & tab, unsigned taille)
{
    bool sortie(true);
    std::vector<CarteFixe const*> tmp;
    std::vector<CarteFixe const*> collec(collection.getCartes());
    std::vector<CarteFixe const*>::iterator it;

    for(unsigned i = 0 ; i < id.size() ; ++i)
    {
        if(collection.existID(id[i]))
        {
            tmp.push_back(Equivalence::toPointer(id[i]));
        }
    }
    if(tmp.size() == taille)
    {
        for(unsigned i = 0 ; i < taille ; ++i)
        {
            it = find(collec.begin(), collec.end(), tmp[i]);
            if(it != collec.end())
            {
                collec.erase(it);
            }
            else
            {
                sortie = false;
            }
        }
    }
    else
    {
        sortie = false;
    }

    if(sortie == true)
    {
        tab = tmp;
    }

    return sortie;
}
