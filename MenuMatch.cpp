#include "MenuMatch.h"
#include "Match.h"
#include "Menu.h"

void MenuMatch::lancerMatch()
{
    std::string choix;
    JoueurMenu const* joueur(nullptr);

    system("cls");

    do
    {
        std::cout << "1 : joueur vs joueur" << std::endl;
        std::cout << "2 : joueur vs ordi (indisponible)" << std::endl;
        getline(std::cin, choix);
    }while(choix != "1" && choix != "2");

    if(atoi(choix.c_str()) == 1)
    {
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
        }while(!m_menu->existNomJoueur(choix));

        joueur = m_menu->joueurToPointer(choix);

        std::cout << std::endl;
        std::cout << "Deck disponible :" << std::endl;
        joueur->displayDeckNom("- ");
        std::cout << std::endl;
        do
        {
            std::cout << "Choissisez un deck : ";
            getline(std::cin, choix);
        }while(!joueur->existNomDeck(choix));

        m_match->m_joueur1.init(joueur->getNom(), joueur->deckToPointer(choix));


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
        }while(!m_menu->existNomJoueur(choix) || m_menu->joueurToPointer(choix) == joueur);

        joueur = m_menu->joueurToPointer(choix);

        std::cout << std::endl;
        std::cout << "Deck disponible :" << std::endl;
        joueur->displayDeckNom("- ");
        std::cout << std::endl;
        do
        {
            std::cout << "Choissisez un deck : ";
            getline(std::cin, choix);
        }while(!joueur->existNomDeck(choix));

        m_match->m_joueur2.init(joueur->getNom(), joueur->deckToPointer(choix));
    }

}
