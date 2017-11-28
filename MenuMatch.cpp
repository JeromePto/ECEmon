#include "MenuMatch.h"
#include "Match.h"

void MenuMatch::lancerMatch()
{
    int choix(0);
    do
    {
        system("");
        std::cout << "1 : joueur vs joueur" << std::endl;
        std::cout << "2 : joueur vs ordi (indisponible)" << std::endl;
        std::cin >> choix;
    }while(choix >= 1 && choix <= 2);

}
