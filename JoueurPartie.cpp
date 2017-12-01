/**
 * Project Untitled
 */


#include "JoueurPartie.h"
#include "SpecialePermanenteFixe.h"
#include "SpecialeCourteFixe.h"

JoueurPartie::JoueurPartie()
    :m_deck(nullptr), m_PV(0), m_nom(""), m_pioche(), m_enjeu(), m_cimetiere(), m_specialePermanente(), m_energie(), m_creature()
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

void JoueurPartie::preInit(std::string const& nom, Deck const* deck)
{
    m_nom = nom;
    m_deck = deck;
}

void JoueurPartie::init()
{
    m_pioche.init(m_deck);
    m_enjeu.init(m_pioche.tirerCarte());
}

std::string JoueurPartie::getNom() const
{
    return m_nom;
}

int JoueurPartie::getPV() const
{
    return m_PV;
}

void JoueurPartie::displayPlateau() const
{
    m_energie.display();
    std::cout << std::endl;
    if(m_creature.hasCreature() == false)
    {
        std::cout << "Pas de creature" << std::endl;
    }
    else
    {
        m_creature.display();
    }
    std::cout << std::endl;
    if(m_specialePermanente.hasSpecialePermanente())
    {
        m_specialePermanente.display();
    }

}

void JoueurPartie::displayAutreJoueur() const
{
    m_creature.display();
    m_energie.display();
    m_specialePermanente.display();
}

int JoueurPartie::jouer(JoueurPartie & ennemi)
{
    int sortie(0);
    CarteFixe const* cartePiocher(nullptr);
    CarteFixe const* aTuer(nullptr);
    std::string texte;
    int choix(0);
    int choixAttaque(0);
    bool tirer(true);
    bool boucleAttaque(true);

    displayPlateau();
    if(m_creature.hasCreature() == false)
    {
        std::cout << "Vous n'avez pas de creature, vous piochez jusqu'a en trouver une" << std::endl;
        m_pioche.debutCompte();
        while(tirer)
        {
            cartePiocher = m_pioche.tirerCarte();
            if(dynamic_cast<CreatureFixe const*>(cartePiocher) == nullptr)
            {
                if(m_pioche.tourComplet())
                {
                    std::cout << "Vous n'avez plus de creatures dans votre pioche : Vous avez perdue" << std::endl;
                    sortie = -1;
                    tirer = false;
                }
                else
                {
                    std::cout << "Vous n'avez pas piocher de creature, la carte est remis sous la pioche" << std::endl;
                    m_pioche.remettreCarte(cartePiocher);
                    std::cout << "Vous repiocher une carte" << std::endl;
                }
            }
            else
            {
                tirer = false;
                std::cout << "Vous avez piocher une creature : " << std::endl;
                dynamic_cast<CreatureFixe const*>(cartePiocher)->displayJeu();
                std::cout << "vous la jouer automatiquement" << std::endl;
                m_creature.setCreature(dynamic_cast<CreatureFixe const*>(cartePiocher));
            }
        }

    }
    else
    {
        std::cout << "Vous piochez une carte :" << std::endl;

        cartePiocher = m_pioche.tirerCarte();

        cartePiocher->displayJeu();

        std::cout << "1 : Jouer la carte" << std::endl;
        std::cout << "2 : Remettre la carte" << std::endl;
        do
        {
            std::cout << "Que voulez-vous faire : ";
            getline(std::cin, texte);
            choix = atoi(texte.c_str());
        }while(choix < 1 || choix > 2);
        std::cout << std::endl;

        if(choix == 2)
        {
            m_pioche.remettreCarte(cartePiocher);


        }
        else
        {
            if(dynamic_cast<CreatureFixe const*>(cartePiocher) != nullptr) // si c'est une creature
            {
                aTuer = m_creature.remplacerCreature(dynamic_cast<CreatureFixe const*>(cartePiocher));
                m_cimetiere.ajouterCarte(aTuer);
            }
            else if(dynamic_cast<EnergieFixe const*>(cartePiocher) != nullptr) // si c'est une energie
            {
                m_energie.ajouterEnergie(dynamic_cast<EnergieFixe const*>(cartePiocher));
                std::cout << "Nouvelle valeur des energies :" << std::endl;
                m_energie.display();

            }
            else if(dynamic_cast<SpecialePermanenteFixe const*>(cartePiocher) != nullptr) // si c'est une speciale permanente
            {

            }
            else if(dynamic_cast<SpecialeCourteFixe const*>(cartePiocher) != nullptr) // si c'est une speciale courte
            {

            }
        }

        if(choix == 2 || dynamic_cast<CreatureFixe const*>(cartePiocher) == nullptr)
        {
            std::cout << "Attaque disponible :" << std::endl;
            std::cout << "0 : ne pas attquer" << std::endl;
            m_creature.displayAttaque();
            boucleAttaque = true;
            do
            {
                do
                {
                    std::cout << "choissisez une attaque : ";
                    getline(std::cin, texte);
                    choixAttaque = atoi(texte.c_str());

                }while(choixAttaque < 0 || choixAttaque > m_creature.getNombreAttaque());
                if(choixAttaque != 0)
                {
                    if(!m_creature.attaquePossible(choixAttaque-1, m_energie)) // attaque impossible
                    {
                        std::cout << "Attaque impossible" <<std::endl;
                    }
                    else
                    {
                        std::cout << "On attaque" << std::endl;
                        sortie = m_creature.attaquer(choixAttaque-1, ennemi);
                        boucleAttaque = false;
                    }
                }
                else
                {
                    boucleAttaque = false;
                }

            }while(boucleAttaque);

            std::cout << std::endl;

        }
    }

    system("pause");
    return sortie;
}

bool JoueurPartie::recevoirDegats(int degats)
{
    bool sortie(false);
    int tmpDegats(degats);
    if(m_creature.hasCreature())
    {
        tmpDegats = m_creature.recevoirDegats(degats);

        if(m_creature.hasCreature())
        {
            std::cout << "La creature ennemi perd " << degats << " PV" << std::endl;
        }
        else
        {
            if(tmpDegats >= m_PV)
            {
                sortie = true;
                std::cout << "La creature et le joueur ennemi meurtent " << std::endl;
            }
            else
            {
                m_PV -= tmpDegats;
                std::cout << "La creature ennemi meurt et le joueur perd " << tmpDegats << " PV" << std::endl;
            }
        }

    }
    else
    {
        if(degats >= m_PV)
        {
            sortie = true;
            std::cout << "Le joueur ennemi meurt " << std::endl;
        }
        else
        {
            m_PV -= degats;
            std::cout << "Le joueur perd " << tmpDegats << " PV" << std::endl;
        }
    }

    return sortie;
}
