/**
 * Project Untitled
 */


#include "JoueurPartie.h"

JoueurPartie::JoueurPartie()
    :m_deck(nullptr), m_PV(0)
{
    std::ifstream fichier("ressources/info.txt", std::ios_base::out);
    if(fichier)
    {
        //Lecture nombre de PV joueur
        fichier >> m_PV;
    }
    else
    {
        std::cerr << "Error opening info file" << std::endl;
        exit(-7);
    }
}

void JoueurPartie::setDeck(Deck const* deck)
{
    m_deck = deck;
}

