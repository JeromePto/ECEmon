/**
 * Project Untitled
 */


#ifndef _DECK_H
#define _DECK_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <algorithm>

#include "CarteFixe.h"
#include "Equivalence.h"

class Deck {
private:
	std::vector<CarteFixe const*> m_carte;
	std::string m_nom;

public:
    Deck();
    Deck(std::vector<CarteFixe const*> carte, std::string nom);

    ~Deck();

    void init(std::vector<CarteFixe const*> carte, std::string nom);
    void initFichier(std::ifstream & fichier);
    void saveFichier(std::ofstream & fichier) const;

    void setPD();
    void retirerCarte(CarteFixe const* carte);

    std::string getNom() const;
    bool deckValide() const;

    CarteFixe const* at(unsigned pos) const;
    unsigned size() const;
    void clear();

    static unsigned getTaille();

    //affiche tous : carte et leurs contenus
    void displayAll() const;

    //affiche juste nom des cartes du decks
    void displayNom() const;
};

#endif //_DECK_H
