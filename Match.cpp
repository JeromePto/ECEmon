/**
 * Project Untitled
 */


#include "Match.h"

Match::Match()
    :m_joueur1(), m_joueur2()
{

}

void Match::preMatch()
{
    MenuMatch::initJoueurMatch();
    m_joueur1.init();
    m_joueur2.init();
}

void Match::postMatch(int gagnant)
{
    /// fin du match a implementer
}

void Match::mainMatch()
{
    bool continuer(true);
    int tour(0);
    int gagnant(0);
    int tmp(0);

    preMatch();

    while(continuer)
    {
        system("cls");
        if(tour%2 == 0)
        {
            std::cout << "Le joueur 2 a " << m_joueur2.getPV() << "PV" << std::endl;
            m_joueur2.displayAutreJoueur();
            std::cout << std::endl << std::endl;
            std::cout << "Joueur 1 : " << m_joueur1.getNom() << " " << m_joueur1.getPV() << "PV" << std::endl;
            std::cout << std::endl;
            tmp = m_joueur1.jouer(m_joueur2);
            if(tmp != 0)
            {
                std::cout << std::endl;
                std::cout << "Fin du match" << std::endl;
                system("pause");
                system("clear");

                if(tmp == 1)
                {
                    gagnant = 1;
                    std::cout << "joueur 1 : " << m_joueur1.getNom() << " a gagner" << std::endl;
                }
                else if(tmp == -1)
                {
                    gagnant = 2;
                    std::cout << "joueur 2 : " << m_joueur2.getNom() << " a gagner" << std::endl;
                }

                std::cout << std::endl;
                continuer = false;
                system("pause");
            }

        }
        else
        {
            std::cout << "Le joueur 1 a " << m_joueur1.getPV() << "PV" << std::endl;
            m_joueur1.displayAutreJoueur();
            std::cout << std::endl << std::endl;
            std::cout << "Joueur 2 : " << m_joueur2.getNom() << " " << m_joueur2.getPV() << "PV" << std::endl;
            std::cout << std::endl;
            tmp = m_joueur2.jouer(m_joueur1);
            if(tmp != 0)
            {
                std::cout << std::endl;
                std::cout << "Fin du match" << std::endl;
                system("pause");
                system("clear");

                if(tmp == 1)
                {
                    gagnant = 2;
                    std::cout << "joueur 2 : " << m_joueur2.getNom() << " a gagner" << std::endl;
                }
                else if(tmp == -1)
                {
                    gagnant = 1;
                    std::cout << "joueur 1 : " << m_joueur1.getNom() << " a gagner" << std::endl;
                }

                std::cout << std::endl;
                continuer = false;
                system("pause");
            }
        }

        tour++;
    }

    postMatch(gagnant);
}
