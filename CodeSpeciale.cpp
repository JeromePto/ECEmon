#include "CodeSpeciale.h"
#include "JoueurPartie.h"

CodeSpeciale::CodeSpeciale()
    :m_moi(nullptr), m_ennemi(nullptr), m_codeActif(0)
{

}

void CodeSpeciale::init(JoueurPartie * moi, JoueurPartie * ennemi)
{
    m_moi = moi;
    m_ennemi = ennemi;
}

void CodeSpeciale::exeCode(unsigned numero, bool force, bool display)
{
    switch(numero)
    {
    case 1:
        code1(display);
        break;
    case 2:
        code2(force, display);
        break;
    case 3:
        code3(display);
        break;
    case 4:
        code4(display);
        break;
    case 5:
        code5(display);
        break;
    case 6:
        code6(display);
        break;
    default:
        std::cerr << "Erreur de numero de code, numero valait : " << numero << std::endl;
        break;
    }
}

void CodeSpeciale::lancerSpecialePermanente(SpecialePermanenteFixe const* carte, bool display)
{
    m_codeActif = carte->getCode();
    m_moi->m_creature.setReference();
    exeCode(m_codeActif, true, display);
}

void CodeSpeciale::stopSpecialePermanente()
{
    if(m_codeActif == 2)
    {
        code2_inv();
    }
    m_codeActif = 0;

}

void CodeSpeciale::lancerSpecialeCourte(SpecialeCourteFixe const* carte, bool display)
{
    unsigned tmp(0);

    tmp = carte->getCode();
    exeCode(tmp, false, display);
}

void CodeSpeciale::actionPermanente(bool display)
{
    if(m_codeActif != 0)
    {
        exeCode(m_codeActif, false, display);
    }
}

void CodeSpeciale::code1(bool display)
{
    ///Courte
    //20 PV retires directement sur le joueur adverse
    m_ennemi->m_PV -= 20;
    if(display)
    {
        std::cout << "Le joueur ennemi perd 20 PV" << std::endl;
    }
}

void CodeSpeciale::code2(bool force, bool display)
{
    ///Permanente
    //+10 degats sur chaque attaque de la creature sur le terrain

    if(!m_moi->m_creature.getMemeCreature() || force)
    {
        m_moi->m_creature.setReference();
        m_moi->m_creature.augmenterDegats(10);
    }
    if(display)
    {
        std::cout << "Votre creature a 10 point d'attaque en plus" << std::endl;
        std::cout << std::endl;
    }
}

void CodeSpeciale::code2_inv()
{
    if(m_moi->m_creature.getMemeCreature())
    {
        m_moi->m_creature.augmenterDegats(-10);
    }
}

void CodeSpeciale::code3(bool display)
{
    ///Courte
    //toutes les creatures en jeu sont envoyees au cimetiere
    CarteFixe const* tmp;

    if(m_ennemi->m_creature.hasCreature())
    {
        tmp = m_ennemi->m_creature.mourir();
        m_ennemi->m_cimetiere.ajouterCarte(tmp);
    }
    if(m_moi->m_creature.hasCreature())
    {
        tmp = m_moi->m_creature.mourir();
        m_moi->m_cimetiere.ajouterCarte(tmp);
    }
}

void CodeSpeciale::code4(bool display)
{
    //une carte energie ennemi est detruite
    CarteFixe const* tmp;

    if(m_ennemi->m_energie.getNombreEnergie() > 0)
    {
        tmp = m_ennemi->m_energie.enleverEnergie( rand() % m_ennemi->m_energie.getNombreEnergie() );
        m_ennemi->m_cimetiere.ajouterCarte(tmp);
    }
    if(display)
    {
        std::cout << "Une carte energie ennemi au hasard est envoyee au cimetiere" << std::endl;
    }
}

void CodeSpeciale::code5(bool display)
{
    ///Permanente
    //+10 PV a chaque tour pour la creature en jeu
    m_moi->m_creature.augmenterPV(10);
    if(display)
    {
        std::cout << "Votre creature gagne 10 point de vie" << std::endl;
    }
}

void CodeSpeciale::code6(bool display)
{
    ///Courte
    //Vous allez au cimetiere recuperer la derniere carte perdue
    CarteFixe const* tmp;

    tmp = m_moi->m_cimetiere.recupererCarte();
    m_moi->m_pioche.remettreCarte(tmp);
    if(display)
    {
        std::cout << "La derniere carte envoye au cimetiere retourne dans votre pioche" << std::endl;
    }

}

void CodeSpeciale::clear()
{
    m_moi = nullptr;
    m_ennemi = nullptr;
    m_codeActif = 0;
}
