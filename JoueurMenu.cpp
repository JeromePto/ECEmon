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
        tmp.clear();
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
    std::string texte;
    std::string chiffre;
    std::vector<int> input;
    std::vector<CarteFixe const*> carte;
    std::istringstream ligne;

    system("cls");

    m_collection.displayAll();
    std::cout << std::endl;
    std::cout << "Entrer les id des " << Deck::getTaille() << " cartes de votres deck separee par des espaces" << std::endl;
    do
    {
        ligne.clear();
        input.clear();
        std::cout << "IDs : ";
        std::getline(std::cin, texte);
        ligne.str(texte);
        for(unsigned i = 0 ; i < Deck::getTaille() ; ++i)
        {
            ligne >> chiffre;
            input.push_back(atoi(chiffre.c_str()));
        }
    }while(!isInCollection(input, m_collection, carte, Deck::getTaille()));

    std::cout << "Donnez un nom au deck : ";
    getline(std::cin, texte);

    m_deck.push_back(Deck(carte, texte));
}

void JoueurMenu::acheterCarte()
{
    std::string texte;
    int input(0);
    bool continuer(true);
    CarteFixe const* carte(nullptr);

    std::cout << "Vos cartes :" << std::endl;
    m_collection.displayAll();
    std::cout << "Votre argent : " << m_argent << std::endl;

    do
    {
    //Boucle de saisie
        texte.clear();
        do
        {
            std::cout << "Taper l'id de la carte que vous voulez acheter ou 0 pour ne rien acheter" << std::endl;
            std::cout << "IDs : ";
            getline(std::cin, texte);
            if(texte == "0")
            {
                continuer = false;
                break;
            }
            input = atoi(texte.c_str());
        }while(Equivalence::toPointer(input) == nullptr || texte == "");

        if(Equivalence::toPointer(input) != nullptr && continuer != false)
        {
            carte = Equivalence::toPointer(input);
            if(static_cast<int>(carte->getPrix()) <= m_argent)
            {
                m_collection.ajouterCarte(carte);
                m_argent -= carte->getPrix();

                std::cout << "Vous avez acheter : " << std::endl;
                carte->displayAll();
                std::cout << "Il vous reste " << m_argent << " d'argent" << std::endl;
            }
            else
            {
                std::cout << "Vous n'avez pas asser d'argent pour acheter cette carte :" << std::endl;
                carte->displayAll();
            }

            texte.clear();
            std::cout << "Voulez-vous continuer vos achat : ";
            getline(std::cin, texte);

            if(texte == "oui" || texte == "o" || texte == "1")
            {
                continuer = true;
            }
            else
            {
                continuer = false;
            }
        }

    }while(continuer);

}

void JoueurMenu::ajouterCarte(CarteFixe const* carte)
{
    m_collection.ajouterCarte(carte);
}

void JoueurMenu::retirerCarte(CarteFixe const* carte)
{
    m_collection.retirerCarte(carte);
    for(unsigned i = 0 ; i < m_deck.size() ; ++i)
    {
        m_deck[i].retirerCarte(carte);
    }
}

void JoueurMenu::gagnerArgent(int argent)
{
    m_argent += argent;
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
        std::cout << std::endl;
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
