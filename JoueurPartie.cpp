/**
 * Project Untitled
 */


#include "JoueurPartie.h"
#include "SpecialePermanenteFixe.h"
#include "SpecialeCourteFixe.h"
#include "SpecialeFixe.h"

JoueurPartie::JoueurPartie()
    :m_deck(nullptr), m_PV(0), m_nom(""), m_AI(false), m_pioche(), m_enjeu(), m_cimetiere(), m_specialePermanente(), m_energie(), m_creature(), m_codeSpeciale()
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

JoueurPartie::~JoueurPartie()
{
    if(m_AI == true && m_deck != nullptr)
    {
        delete m_deck;
    }
}

void JoueurPartie::preInit(std::string const& nom, Deck const* deck)
{
    m_nom = nom;
    m_deck = deck;
}

void JoueurPartie::preInitAI()
{
    m_nom = "Ordinateur";
    m_AI = true;
    Deck * deck = new Deck;
    deck->setPD();
    m_deck = deck;
}

void JoueurPartie::init(JoueurPartie & ennemi)
{
    m_pioche.init(m_deck);
    m_enjeu.init(m_pioche.tirerCarte());
    m_codeSpeciale.init(this, &ennemi);

}

std::string JoueurPartie::getNom() const
{
    return m_nom;
}

int JoueurPartie::getPV() const
{
    return m_PV;
}

bool JoueurPartie::getAI() const
{
    return m_AI;
}

CarteFixe const* JoueurPartie::getEnjeu() const
{
    return m_enjeu.getEnjeu();
}

void JoueurPartie::displayPlateau() const
{
    Divers::setColor(12, 0);
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
    std::cout << std::endl;
    m_energie.display();
    std::cout << std::endl;
    Divers::setColor(7, 0);
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
    if(m_creature.hasCreature() == false && m_pioche.hasCarte() == true)
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
                m_codeSpeciale.actionPermanente();
            }
        }

    }
    else if(m_creature.hasCreature() == true)
    {
        if(m_pioche.hasCarte())
        {
            m_codeSpeciale.actionPermanente();

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

            }
            while(choix < 1 || choix > 2 || texte == "");
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
                    Divers::setColor(12, 0);
                    std::cout << "Nouvelle valeur des energies :" << std::endl;
                    m_energie.display();
                    Divers::setColor(7, 0);

                }
                else if(dynamic_cast<SpecialePermanenteFixe const*>(cartePiocher) != nullptr) // si c'est une speciale permanente
                {
                    if(m_specialePermanente.hasSpecialePermanente())
                    {
                        m_codeSpeciale.stopSpecialePermanente();
                        aTuer = m_specialePermanente.remplacerSpecialePermanente(dynamic_cast<SpecialePermanenteFixe const*>(cartePiocher));
                        m_cimetiere.ajouterCarte(aTuer);
                        m_codeSpeciale.lancerSpecialePermanente(dynamic_cast<SpecialePermanenteFixe const*>(cartePiocher));
                    }
                    else
                    {
                        m_specialePermanente.setSpecialePermanente(dynamic_cast<SpecialePermanenteFixe const*>(cartePiocher));
                        m_codeSpeciale.lancerSpecialePermanente(dynamic_cast<SpecialePermanenteFixe const*>(cartePiocher));
                    }

                }
                else if(dynamic_cast<SpecialeCourteFixe const*>(cartePiocher) != nullptr) // si c'est une speciale courte
                {
                    m_codeSpeciale.lancerSpecialeCourte(dynamic_cast<SpecialeCourteFixe const*>(cartePiocher));
                    m_cimetiere.ajouterCarte(cartePiocher);
                }

            }
        }
        else
        {
            std::cout << "Vous n'avez plus de carte dans la pioche" << std::endl;
            choix = 2;
        }

        if(choix == 2 || dynamic_cast<CreatureFixe const*>(cartePiocher) == nullptr)
        {
            std::cout << "Attaque disponible :" << std::endl;
            std::cout << "0 : ne pas attquer" << std::endl;
            Divers::setColor(15, 0);
            m_creature.displayAttaque();
            Divers::setColor(7, 0);
            boucleAttaque = true;
            do
            {
                do
                {
                    std::cout << "choissisez une attaque : ";
                    getline(std::cin, texte);
                    choixAttaque = atoi(texte.c_str());

                }
                while(choixAttaque < 0 || choixAttaque > m_creature.getNombreAttaque());
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

            }
            while(boucleAttaque);

            std::cout << std::endl;

        }

        if(ennemi.getPV() <= 0)
        {
            sortie = 1;
        }
    }
    else
    {
        sortie = -1;
    }
    system("pause");
    return sortie;
}

int JoueurPartie::jouerAI(JoueurPartie & ennemi)
{
    int sortie(0);
    CarteFixe const* cartePiocher(nullptr);
    CarteFixe const* aTuer(nullptr);
    int choix(0);
    int choixAttaque(0);
    bool tirer(true);
    bool boucleAttaque(true);

    if(m_creature.hasCreature() == false && m_pioche.hasCarte() == true)
    {
        //std::cout << "Vous n'avez pas de creature, vous piochez jusqu'a en trouver une" << std::endl;
        m_pioche.debutCompte();
        while(tirer)
        {
            cartePiocher = m_pioche.tirerCarte();
            if(dynamic_cast<CreatureFixe const*>(cartePiocher) == nullptr)
            {
                if(m_pioche.tourComplet())
                {
                    //std::cout << "Vous n'avez plus de creatures dans votre pioche : Vous avez perdue" << std::endl;
                    sortie = -1;
                    tirer = false;
                }
                else
                {
                    //std::cout << "Vous n'avez pas piocher de creature, la carte est remis sous la pioche" << std::endl;
                    m_pioche.remettreCarte(cartePiocher);
                    //std::cout << "Vous repiocher une carte" << std::endl;
                }
            }
            else
            {
                tirer = false;
                //std::cout << "Vous avez piocher une creature : " << std::endl;
                dynamic_cast<CreatureFixe const*>(cartePiocher)->displayJeu();
                //std::cout << "vous la jouer automatiquement" << std::endl;
                m_creature.setCreature(dynamic_cast<CreatureFixe const*>(cartePiocher));
                m_codeSpeciale.actionPermanente(false);
            }
        }

    }
    else if(m_creature.hasCreature() == true)
    {
        if(m_pioche.hasCarte())
        {
            m_codeSpeciale.actionPermanente(false);

            //std::cout << "Vous piochez une carte :" << std::endl;

            cartePiocher = m_pioche.tirerCarte();

            //cartePiocher->displayJeu();

            //std::cout << "1 : Jouer la carte" << std::endl;
            //std::cout << "2 : Remettre la carte" << std::endl;

            ///AI jouer ou remettre carte
            if(dynamic_cast<EnergieFixe const*>(cartePiocher) != nullptr) // si c'est une energie
            {
                choix = 1;
            }
            else if(dynamic_cast<SpecialeFixe const*>(cartePiocher) != nullptr) // si c'est une speciale
            {
                choix = 1;
            }
            else if(dynamic_cast<CreatureFixe const*>(cartePiocher) != nullptr) // si c'est une creature
            {
                CreatureJeu creaturePioche;
                creaturePioche.setCreature(dynamic_cast<CreatureFixe const*>(cartePiocher));

                if(!m_creature.attaquePossible(m_energie) && creaturePioche.attaquePossible(m_energie))
                {
                    choix = 1;
                }
                else
                {
                    choix = 2;
                }
            }


            //std::cout << std::endl;

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
                    //Divers::setColor(12, 0);
                    //std::cout << "Nouvelle valeur des energies :" << std::endl;
                    //m_energie.display();
                    //Divers::setColor(7, 0);

                }
                else if(dynamic_cast<SpecialePermanenteFixe const*>(cartePiocher) != nullptr) // si c'est une speciale permanente
                {
                    if(m_specialePermanente.hasSpecialePermanente())
                    {
                        m_codeSpeciale.stopSpecialePermanente();
                        aTuer = m_specialePermanente.remplacerSpecialePermanente(dynamic_cast<SpecialePermanenteFixe const*>(cartePiocher));
                        m_cimetiere.ajouterCarte(aTuer);
                        m_codeSpeciale.lancerSpecialePermanente(dynamic_cast<SpecialePermanenteFixe const*>(cartePiocher), false);
                    }
                    else
                    {
                        m_specialePermanente.setSpecialePermanente(dynamic_cast<SpecialePermanenteFixe const*>(cartePiocher));
                        m_codeSpeciale.lancerSpecialePermanente(dynamic_cast<SpecialePermanenteFixe const*>(cartePiocher), false);
                    }

                }
                else if(dynamic_cast<SpecialeCourteFixe const*>(cartePiocher) != nullptr) // si c'est une speciale courte
                {
                    m_codeSpeciale.lancerSpecialeCourte(dynamic_cast<SpecialeCourteFixe const*>(cartePiocher), false);
                    m_cimetiere.ajouterCarte(cartePiocher);
                }

            }
        }
        else
        {
            //std::cout << "Vous n'avez plus de carte dans la pioche" << std::endl;
            choix = 2;
        }


        if(choix == 2 || dynamic_cast<CreatureFixe const*>(cartePiocher) == nullptr)
        {
            //std::cout << "Attaque disponible :" << std::endl;
            //std::cout << "0 : ne pas attquer" << std::endl;
            //Divers::setColor(15, 0);
            //m_creature.displayAttaque();
            //Divers::setColor(12, 0);
            boucleAttaque = true;
            choixAttaque = m_creature.getNombreAttaque();
            do
            {
                if(choixAttaque != 0)
                {
                    if(m_creature.attaquePossible(choixAttaque-1, m_energie)) // attaque impossible
                    {
                        sortie = m_creature.attaquer(choixAttaque-1, ennemi);
                        boucleAttaque = false;
                    }
                }
                else
                {
                    boucleAttaque = false;
                }
                choixAttaque--;
            }
            while(boucleAttaque);

            //std::cout << std::endl;

        }

        if(ennemi.getPV() <= 0)
        {
            sortie = 1;
        }
    }
    else
    {
        sortie = -1;
    }

    //system("pause");
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

void JoueurPartie::clear()
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
        exit(-8);
    }

    if(m_AI == true && m_deck != nullptr)
    {
        delete m_deck;
    }
    m_AI = false;
    m_nom.clear();

    m_pioche.clear();
    m_enjeu.clear();
    m_cimetiere.clear();
    m_specialePermanente.clear();
    m_energie.clear();
    m_creature.clear();
    m_codeSpeciale.clear();
}
