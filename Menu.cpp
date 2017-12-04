/**
 * Project Untitled
 */


#include "Menu.h"

bool Menu::existNomJoueur(std::string const& nom) const
{
    bool sortie(false);

    for(std::vector<JoueurMenu>::const_iterator it = m_joueur.cbegin() ; it != m_joueur.cend() ; ++it)
    {
        if(it->getNom() == nom)
        {
            sortie = true;
        }
    }

    return sortie;
}

JoueurMenu const* Menu::joueurToPointer(std::string const& nom) const
{
    JoueurMenu const* sortie(nullptr);

    for(unsigned int i = 0 ; i < m_joueur.size() ; ++i)
    {
        if(m_joueur[i].getNom() == nom)
        {
            sortie = &m_joueur[i];
        }
    }

    return sortie;
}

JoueurMenu * Menu::joueurToPointerPrivate(std::string const& nom)
{
    JoueurMenu * sortie(nullptr);

    for(unsigned int i = 0 ; i < m_joueur.size() ; ++i)
    {
        if(m_joueur[i].getNom() == nom)
        {
            sortie = &m_joueur[i];
        }
    }

    return sortie;
}


Menu::Menu()
    :m_joueur(), m_carte()
{

}

Menu::~Menu()
{
    for(std::vector<CarteFixe*>::iterator it = m_carte.begin() ; it != m_carte.end() ; ++it)
    {
        delete *it;
    }
}

short Menu::loadCartes()
{
    std::string ligne;
    std::vector<std::string> listeCarte;
    std::ifstream fichier;
    short sortie(0);

    fichier.open("ressources/cartes.txt", std::ios_base::in);

    if(fichier)
    {
        while(std::getline(fichier, ligne))
        {
            listeCarte.push_back(ligne);
        }

        fichier.close();

        for(unsigned short i = 0 ; i < listeCarte.size() ; ++i)
        {
            fichier.open("ressources/cartes/" + listeCarte[i] + ".txt", std::ios_base::in);

            std::cout << "Loading " << listeCarte[i] << " : ";

            if(fichier)
            {
                //Recuperation ligne de type
                std::getline(fichier, ligne);

                // Si pas chiffre conversion en minuscule
                if(isalpha(ligne[0]))
                {
                    std::for_each(ligne.begin(), ligne.end(), [](char & c){c = tolower(c);});
                }

                // Creation de carte en fonction du type
                if(ligne=="creature" || ligne=="crea" || ligne=="0")
                {
                    m_carte.push_back(new CreatureFixe());
                    m_carte[i]->initFichier(fichier);
                }
                else if(ligne=="energie" || ligne=="ener" || ligne=="1")
                {
                    m_carte.push_back(new EnergieFixe());
                    m_carte[i]->initFichier(fichier);
                }
                else if(ligne=="specialecourte" || ligne=="specialcourte" || ligne=="specialec" || ligne=="specialc" || ligne=="spec" || ligne=="specourte" || ligne=="2")
                {
                    m_carte.push_back(new SpecialeCourteFixe());
                    m_carte[i]->initFichier(fichier);
                }
                else if(ligne=="specialepermanente" || ligne=="specialpermanente" || ligne=="specialeperm" || ligne=="specialperm" || ligne=="specialep" || ligne=="specialp" || ligne=="spep" || ligne=="speperm" || ligne=="spepermanente" || ligne=="3")
                {
                    m_carte.push_back(new SpecialePermanenteFixe());
                    m_carte[i]->initFichier(fichier);
                }
                else
                {
                    std::cerr << "Pas type" << std::endl;
                }

                std::cout << "OK" << std::endl;

                fichier.close();
            }
            else
            {
                std::cerr << "Error opening element card file" << std::endl;
                sortie = -2;
            }
        }
    }
    else
    {
        std::cerr << "Error opening main card file" << std::endl;
        sortie = -1;
    }

    return sortie;
}

short Menu::loadJoueur()
{
    std::string ligne;
    std::vector<std::string> listeJoueur;
    std::ifstream fichier;
    short sortie(0);

    fichier.open("ressources/joueurs.txt", std::ios_base::in);

    if(fichier)
    {
        while(std::getline(fichier, ligne))
        {
            listeJoueur.push_back(ligne);
        }

        fichier.close();

        for(unsigned short i = 0 ; i < listeJoueur.size() ; ++i)
        {
            fichier.open("ressources/joueurs/" + listeJoueur[i] + ".txt", std::ios_base::in);

            std::cout << "Loading " << listeJoueur[i] << " : ";

            if(fichier)
            {
                m_joueur.push_back(JoueurMenu());
                m_joueur[i].initFichier(fichier);

                std::cout << "OK" << std::endl;

                fichier.close();
            }
            else
            {
                std::cerr << "Error opening element player file" << std::endl;
                sortie = -4;
            }
        }
    }
    else
    {
        std::cerr << "Error opening main player file" << std::endl;
        sortie = -3;
    }

    return sortie;
}

void Menu::loadFichier()
{
    short erreur(-7);

    erreur = loadCartes();
    if(erreur < 0)
    {
        exit(erreur);
    }

    Equivalence::init(m_carte);

    if(loadJoueur() < 0)
    {
        m_joueur.clear();
    }
}

void Menu::saveJoueur()
{
    std::ofstream fichier;

    fichier.open("ressources/joueurs.txt", std::ios_base::out);

    if(fichier)
    {
        for(unsigned short i = 0 ; i < m_joueur.size() ; ++i)
        {
            fichier << m_joueur[i].getNom() << std::endl;
        }

        fichier.close();

        for(unsigned short i = 0 ; i < m_joueur.size() ; ++i)
        {
            fichier.open("ressources/joueurs/" + m_joueur[i].getNom() + ".txt", std::ios_base::out);

            std::cout << "Saving " << m_joueur[i].getNom() << " : ";

            if(fichier)
            {
                m_joueur[i].saveFichier(fichier);

                std::cout << "OK" << std::endl;

                fichier.close();
            }
            else
            {
                std::cerr << "Error opening element player file" << std::endl;
            }
        }
    }
    else
    {
        std::cerr << "Error opening main player file" << std::endl;
    }
}


void Menu::displayCartes() const
{
    for(unsigned int i = 0 ; i < m_carte.size() ; ++i)
    {
        m_carte[i]->displayAll();
        std::cout << std::endl;
    }
}

void Menu::displayJoueurs() const
{
    for(unsigned int i = 0 ; i < m_joueur.size() ; ++i)
    {
        m_joueur[i].displayCourt();
        std::cout << std::endl;
    }
}

void Menu::displayListeJoueurs(std::string avant, JoueurMenu const* sauf) const
{
    for(unsigned int i = 0 ; i < m_joueur.size() ; ++i)
    {
        if(&m_joueur[i] != sauf)
        {
            std::cout << avant << m_joueur[i].getNom() << std::endl;
        }
    }
}

void Menu::creerJoueur()
{
    std::string nom;
    bool tmp(false);

    do
    {
        std::cout << "Nom du joueur : ";
        getline(std::cin, nom);

        tmp = false;

        if(existNomJoueur(nom))
        {
            std::cout << "Nom deja utilisee" << std::endl;
            tmp = true;
        }
        if(!Divers::isPrint(nom))
        {
            std::cout << "Erreur de saisie" << std::endl;
            tmp = true;
        }

    }while(tmp);

    m_joueur.push_back(JoueurMenu(nom));

    saveJoueur();
}

void Menu::modifierJoueur()
{
    std::string choix;
    std::string texte;
    int intTexte(0);
    bool continuer(true);

    JoueurMenu * joueur(nullptr);

    system("cls");

    /// Selection du joueur a modifier
    std::cout << "Joueurs disponible :" << std::endl;
    displayListeJoueurs("- ");
    std::cout << std::endl;
    do
    {
        std::cout << "Quel joueur voulez vous modifier : ";
        getline(std::cin, choix);
    }while(!existNomJoueur(choix));

    joueur = joueurToPointerPrivate(choix);

    /// Menu modification joueur
    do
    {
        system("cls");
        std::cout << "Joueur : " << joueur->getNom() << std::endl;
        std::cout << "0 - Revenir au menu" << std::endl;
        std::cout << "1 - Acheter des cartes" << std::endl;
        std::cout << "2 - Creer un deck" << std::endl;

        do
        {
            std::cout << "Que voulez-vous faire : ";
            getline(std::cin, texte);
            intTexte = atoi(texte.c_str());
        }while(intTexte < 0 || intTexte > 2 || texte == "");

        switch(intTexte)
        {
        case 0:
            continuer = false;
            break;
        case 1:
            system("cls");
            std::cout << "Carte du jeu :" << std::endl;
            std::cout << std::endl;
            displayCartes();
            joueur->acheterCarte();
            break;
        case 2:
            joueur->creerDeck();
            break;
        }
    }while(continuer);

    saveJoueur();
}
