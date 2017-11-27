/**
 * Project Untitled
 */


#include "SpecialeFixe.h"

SpecialeFixe::SpecialeFixe()
    :CarteFixe(), m_description(""), m_code(nullptr)
{

}

SpecialeFixe::SpecialeFixe(std::string nom, unsigned int id, unsigned int prix, std::string description, void (*code)(Match * match))
    :CarteFixe(nom, id, prix), m_description(description), m_code(code)
{

}

SpecialeFixe::SpecialeFixe(std::string nom, unsigned int id, unsigned int prix, std::string description, unsigned int numero)
    :CarteFixe(nom, id, prix), m_description(description), m_code(nullptr)
{
    if(numero == 1)
    {
        m_code = &code1;
    }
}

SpecialeFixe::~SpecialeFixe()
{

}

void SpecialeFixe::init(std::string nom, unsigned int id, unsigned int prix, std::string description, void (*code)(Match * match))
{
    CarteFixe::init(nom, id, prix);
    m_description = description;
    m_code = code;
}


void SpecialeFixe::init(std::string nom, unsigned int id, unsigned int prix, std::string description, unsigned int numero)
{
    CarteFixe::init(nom, id, prix);
    m_description = description;
    if(numero == 1)
    {
        m_code = &code1;
    }
}

void SpecialeFixe::initFichier(std::ifstream& fichier)
{
    std::string ligne;
    std::string tmpNom;
    unsigned int tmpID;

    //Lecture nom
    std::getline(fichier, tmpNom);

    //Lecture ID
    std::getline(fichier, ligne);
    tmpID = atoi(ligne.c_str());

    //Lecture prix
    std::getline(fichier, ligne);
    CarteFixe::init(tmpNom, tmpID, atoi(ligne.c_str()));

    //Lecture description
    std::getline(fichier, ligne);
    m_description = ligne;

    //Lecture numero de la fonction
    std::getline(fichier, ligne);
    switch(atoi(ligne.c_str()))
    {
    case 1:
        m_code = &code1;
        break;
    default:
        break;
    }
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
