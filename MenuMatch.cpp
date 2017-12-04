#include "MenuMatch.h"
#include "Match.h"
#include "Menu.h"

bool MenuMatch::initJoueurMatch()
{
    std::string choix;
    bool AI(false);
    JoueurMenu const* joueur(nullptr);
    Deck const* deck(nullptr);

    system("cls");

    m_match->clear();

    do
    {
        std::cout << "1 : joueur vs joueur" << std::endl;
        std::cout << "2 : joueur vs ordi" << std::endl;
        getline(std::cin, choix);
        if(choix == "0")
        {
            return false;
        }
    }
    while(choix != "1" && choix != "2");
    if(atoi(choix.c_str()) == 2)
    {
        AI = true;
    }
    ///Choix joueur et deck du joueur 1
    system("cls");
    std::cout << "Joueur 1 : " << std::endl << std::endl;

    std::cout << "Joueurs disponible :" << std::endl;
    m_menu->displayListeJoueurs("- ");
    std::cout << std::endl;
    do
    {
        std::cout << "Choissisez un joueur : ";
        getline(std::cin, choix);
        if(choix == "0")
        {
            return false;
        }
    }
    while(!m_menu->existNomJoueur(choix));

    joueur = m_menu->joueurToPointer(choix);

    std::cout << std::endl;
    std::cout << "Deck disponible :" << std::endl;
    joueur->displayDeckNom("- ");
    std::cout << std::endl;
    do
    {
        do
        {
            std::cout << "Choissisez un deck : ";
            getline(std::cin, choix);
            if(choix == "0")
            {
                return false;
            }
        }
        while(!joueur->existNomDeck(choix));
        deck = joueur->deckToPointer(choix);
        if(!deck->deckValide())
        {
            std::cout << "Deck non valide" << std::endl;
        }
    }
    while(!deck->deckValide());

    m_match->m_joueur1.preInit(joueur->getNom(), deck);


    if(AI == false)
    {
        ///Choix joueur et deck du joueur 2
        system("cls");
        std::cout << "Joueur 2 : " << std::endl << std::endl;


        std::cout << "Joueurs disponible :" << std::endl;
        m_menu->displayListeJoueurs("- ", joueur);
        std::cout << std::endl;
        do
        {
            std::cout << "Choissisez un joueur : ";
            getline(std::cin, choix);
            if(choix == "0")
            {
                return false;
            }
        }
        while(!m_menu->existNomJoueur(choix) || m_menu->joueurToPointer(choix) == joueur);

        joueur = m_menu->joueurToPointer(choix);

        std::cout << std::endl;
        std::cout << "Deck disponible :" << std::endl;
        joueur->displayDeckNom("- ");
        std::cout << std::endl;
        do
        {
            do
            {
                std::cout << "Choissisez un deck : ";
                getline(std::cin, choix);
                if(choix == "0")
                {
                    return false;
                }
            }
            while(!joueur->existNomDeck(choix));
            deck = joueur->deckToPointer(choix);
            if(!deck->deckValide())
            {
                std::cout << "Deck non valide" << std::endl;
            }
        }
        while(!deck->deckValide());

        m_match->m_joueur2.preInit(joueur->getNom(), deck);
    }
    else
    {
        m_match->m_joueur2.preInitAI();
    }
    return true;
}

void MenuMatch::gagnerCarteArgent(CarteFixe const* carte, std::string nom)
{
    m_menu->joueurToPointerPrivate(nom)->ajouterCarte(carte);
    m_menu->joueurToPointerPrivate(nom)->gagnerArgent(1000);
}

void MenuMatch::perdreCarte(CarteFixe const* carte, std::string nom)
{
    m_menu->joueurToPointerPrivate(nom)->retirerCarte(carte);
}

