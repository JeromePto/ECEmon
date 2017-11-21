/**
 * Project Untitled
 */


#include "Menu.h"

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
                std::cerr << "Error opening element card file" << std::endl;
                sortie = -2;
            }
        }
    }
    else
    {
        std::cerr << "Error opening main player file" << std::endl;
        sortie = -1;
    }

    return sortie;
}

void Menu::loadFichier()
{
    loadCartes();
    Equivalence::init(m_carte);
    loadJoueur();
}

void Menu::saveJoueur()
{
    std::ofstream fichier;

    fichier.open("ressources/joueurs.txt", std::ios_base::out);

    if(fichier)
    {
        fichier << m_joueur.size() << std::endl;

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
                std::cerr << "Error opening element card file" << std::endl;
            }
        }
    }
    else
    {
        std::cerr << "Error opening main player file" << std::endl;
    }
}


void Menu::displayAll() const
{
    for(unsigned int i = 0 ; i < m_carte.size() ; ++i)
    {
        m_carte[i]->displayAll();
        std::cout << std::endl;
    }
}
