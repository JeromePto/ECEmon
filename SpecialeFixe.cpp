/**
 * Project Untitled
 */


#include "SpecialeFixe.h"

SpecialeFixe::SpecialeFixe()
    :CarteFixe(), m_description(""), m_code(0)
{

}

SpecialeFixe::SpecialeFixe(std::string nom, unsigned int id, unsigned int prix, std::string description, unsigned int numero)
    :CarteFixe(nom, id, prix), m_description(description), m_code(numero)
{

}

SpecialeFixe::~SpecialeFixe()
{

}


void SpecialeFixe::init(std::string nom, unsigned int id, unsigned int prix, std::string description, unsigned int numero)
{
    CarteFixe::init(nom, id, prix);
    m_description = description;
    m_code = numero;
}

void SpecialeFixe::initFichier(std::ifstream& fichier)
{
    std::string ligne;

    CarteFixe::initFichier(fichier);

    //Lecture description
    std::getline(fichier, ligne);
    m_description = ligne;

    //Lecture numero de la fonction
    std::getline(fichier, ligne);
    m_code = atoi(ligne.c_str());
}

void SpecialeFixe::displayAll() const
{
    std::cout << "Speciale : " << m_nom << std::endl;
    std::cout << "ID = " << m_id << std::endl;
    std::cout << "Prix = " << m_prix << std::endl;
    if(isPermanente())
    {
        std::cout << "Permanente" <<  std::endl;
    }
    else
    {
        std::cout << "Non permanente" <<  std::endl;
    }
    std::cout << m_description << std::endl;
}

void SpecialeFixe::displayNom() const
{
    std::cout << "Speciale : " << m_nom << std::endl;
}

void SpecialeFixe::displayDescription() const
{
    std::cout << m_description << std::endl;
}

void SpecialeFixe::displayJeu() const
{
    std::cout << "Speciale : " << m_nom << std::endl;
    std::cout << m_description << std::endl;
}
