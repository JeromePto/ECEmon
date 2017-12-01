#include <iostream>
#include <ctime>
#include <windows.h>

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

    srand(time(nullptr));

    MenuMatch::m_menu = &menu;
    MenuMatch::m_match = &match;

    menu.loadFichier();

    menu.displayCartes();

    system("pause");

    //menu.modifierJoueur();

    match.mainMatch();

    return 0;
}
