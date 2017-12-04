#include <iostream>
#include <ctime>
#include <windows.h>
#include <string>

#include "enum.h"
#include "divers.h"
#include "Attaque.h"
#include "CarteFixe.h"
#include "Cimetiere.h"
#include "Collection.h"
#include "CreatureFixe.h"
#include "CreatureJeu.h"
#include "Deck.h"
#include "EnergieFixe.h"
#include "EnergieJeu.h"
#include "Enjeu.h"
#include "JoueurMenu.h"
#include "JoueurPartie.h"
#include "Match.h"
#include "Menu.h"
#include "Pioche.h"
#include "SpecialeCourteFixe.h"
#include "SpecialeFixe.h"
#include "SpecialePermanenteFixe.h"
#include "SpecialePermanenteJeu.h"
#include "Equivalence.h"
#include "MenuMatch.h"

using namespace std;

Menu* MenuMatch::m_menu = nullptr;
Match* MenuMatch::m_match = nullptr;

int main()
{
    Menu menu;
    Match match;

    srand(static_cast<unsigned>(time(nullptr)));

    MenuMatch::m_menu = &menu;
    MenuMatch::m_match = &match;

    Divers::setColor(7, 0);

    menu.loadFichier();

    //menu.displayCartes();
    //system("pause");

    ///Menu principal

    std::string texte;
    int intTexte(0);
    bool continuer(true);

    ///Boucle principale
    do
    {
        system("cls");
        std::cout << "--------------------- ECEMON ---------------------" << std::endl;
        std::cout << "0 - Quitter" << std::endl;
        std::cout << "1 - Jouer" << std::endl;
        std::cout << "2 - Creer un joueur" << std::endl;
        std::cout << "3 - Modifier un joueur" << std::endl;

        do
        {
            std::cout << "Que voulez-vous faire : ";
            getline(std::cin, texte);
            intTexte = atoi(texte.c_str());
        }while(intTexte < 0 || intTexte > 3 || texte == "");

        switch(intTexte)
        {
        case 0:
            continuer = false;
            break;
        case 1:
            match.mainMatch();
            menu.saveJoueur();
            break;
        case 2:
            menu.creerJoueur();
            break;
        case 3:
            menu.modifierJoueur();
            break;
        }

    }while(continuer);

    return 0;
}
