/**
 * Project Untitled
 */


#include "Pioche.h"

Pioche::Pioche()
    :m_carte(), m_compteur(-1), m_taille(0)
{

}

void Pioche::init(Deck const* deck)
{
    m_compteur = -1;
    m_taille = 0;
    for(unsigned i = 0 ; i < deck->size() ; ++i)
    {
        m_carte.push_back(deck->at(i));
    }
    random_shuffle(m_carte.begin(), m_carte.end());
}

CarteFixe const* Pioche::tirerCarte()
{
    CarteFixe const* sortie(nullptr);
    sortie = m_carte.back();
    m_carte.pop_back();

    if(m_compteur > -1)
    {
        m_compteur++;
    }

    return sortie;
}

void Pioche::remettreCarte(CarteFixe const* carte)
{
    m_carte.push_front(carte);
}

void Pioche::debutCompte()
{
    m_taille = m_carte.size();
    m_compteur = 0;
}

bool Pioche::tourComplet()
{
    bool sortie(false);

    if(m_compteur == m_taille)
    {
        m_taille = 0;
        m_compteur = -1;
        sortie = true;
    }

    return sortie;
}
