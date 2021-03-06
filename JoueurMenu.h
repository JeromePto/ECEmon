/**
 * Project Untitled
 */


#ifndef _JOUEURMENU_H
#define _JOUEURMENU_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <windows.h>
#include <sstream>
#include <algorithm>

#include "CarteFixe.h"
#include "Collection.h"
#include "Deck.h"

class JoueurMenu
{
private:
	std::string m_nom;
	Collection m_collection;
	std::vector<Deck> m_deck;
	int m_argent;


public:
    JoueurMenu();
    JoueurMenu(std::string const& nom);

    ~JoueurMenu();

    void init(std::string nom, Collection collection, std::vector<Deck> deck, int argent);
    void initFichier(std::ifstream & fichier);
    void saveFichier(std::ofstream & fichier);

    std::string getNom() const;
	bool existNomDeck(std::string const& nom) const;
	Deck const* deckToPointer(std::string const& nom) const;
	void creerDeck();
	void acheterCarte();

	void ajouterCarte(CarteFixe const* carte);
	void retirerCarte(CarteFixe const* carte);
	void gagnerArgent(int argent);

    //affiche tout : info joueur + deck(s) et contenu + collection et contenu
    void displayAll() const;

    //affiche tout sans contenus des decks et de la collection (juste leur nom)
    void displayCourt() const;

    //afffiche juste le nom des decks
    void displayDeckNom(std::string avant = "") const;

};


bool isInCollection(std::vector<int> id, Collection const& collection, std::vector<CarteFixe const*> & tab, unsigned taille);

#endif //_JOUEURMENU_H
