#include "Equivalence.h"

namespace Equivalence
{
    std::map<unsigned int, CarteFixe const*> m_carte;

    void init(std::vector<CarteFixe*>carte)
    {
        for(auto it : carte)
        {
            m_carte.insert(std::pair<unsigned int, CarteFixe const*>(it->getID(), it));
        }
    }

    CarteFixe const* toPointer(unsigned int id)
    {
        CarteFixe const* sortie(nullptr);

        sortie = m_carte[id];

        return sortie;
    }

    unsigned int toID(CarteFixe const* pointer)
    {
        return pointer->getID();
    }
}
