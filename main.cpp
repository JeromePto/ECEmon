#include <iostream>
#include <vector>

#include <algorithm>
#include <ctype.h>

#include "enum.h"
#include "divers.h"
#include "codeSpeciale.h"
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

using namespace std;

int main()
{

    Menu menu;
    menu.loadFichier();

    menu.displayCartes();
    menu.displayJoueurs();

    return 0;
}
