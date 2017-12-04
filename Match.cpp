/**
 * Project Untitled
 */


#include "Match.h"

Match::Match()
    :m_joueur1(), m_joueur2()
{

}

bool Match::preMatch()
{
    bool sortie(true);

    if(MenuMatch::initJoueurMatch())
    {
        m_joueur1.init(m_joueur2);
        m_joueur2.init(m_joueur1);

        std::cout << "Le match commence" << std::endl;
        system("pause");
    }
    else
    {
        sortie = false;
    }

    return sortie;
}

void Match::postMatch(int gagnant)
{
    CarteFixe const* enjeu(nullptr);

    if(gagnant == 1)
    {
        std::cout << "Vous gagner l'enjeu du joueur adverse :" <<std::endl;
        enjeu = m_joueur2.getEnjeu();
        enjeu->displayAll();
        std::cout << "Le votre etait :" << std::endl;
        m_joueur1.getEnjeu()->displayAll();
        MenuMatch::gagnerCarteArgent(enjeu, m_joueur1.getNom());
        if(!m_joueur2.getAI())
        {
            MenuMatch::perdreCarte(enjeu, m_joueur2.getNom());
        }
    }
    else if(gagnant == 2 && !m_joueur2.getAI())
    {
        std::cout << "Vous gagner l'enjeu du joueur adverse :" <<std::endl;
        enjeu= m_joueur1.getEnjeu();
        enjeu->displayAll();
        std::cout << "Le votre etait :" << std::endl;
        m_joueur2.getEnjeu()->displayAll();
        MenuMatch::gagnerCarteArgent(enjeu, m_joueur2.getNom());
        MenuMatch::perdreCarte(enjeu, m_joueur1.getNom());
    }
    system("pause");
}

void Match::mainMatch()
{
    bool continuer(true);
    int tour(0);
    int gagnant(0);
    int tmp(0);

    if(preMatch())
    {
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
                    system("cls");
                    std::cout << "Fin du match" << std::endl;

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
                if(m_joueur2.getAI())
                {
                    tmp = m_joueur2.jouerAI(m_joueur1);
                }
                else
                {
                    std::cout << "Le joueur 1 a " << m_joueur1.getPV() << "PV" << std::endl;
                    m_joueur1.displayAutreJoueur();
                    std::cout << std::endl << std::endl;
                    std::cout << "Joueur 2 : " << m_joueur2.getNom() << " " << m_joueur2.getPV() << "PV" << std::endl;
                    std::cout << std::endl;
                    tmp = m_joueur2.jouer(m_joueur1);
                }
                if(tmp != 0)
                {
                    std::cout << std::endl;
                    system("cls");
                    std::cout << "Fin du match" << std::endl;

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
}

 void Match::clear()
 {
     m_joueur1.clear();
     m_joueur2.clear();
 }
