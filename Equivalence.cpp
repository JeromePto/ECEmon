#include "Equivalence.h"

namespace Equivalence
{
    std::multimap<CarteFixe const*, unsigned int> m_carte;

    void init(std::vector<CarteFixe*>carte)
    {
        for(auto it : carte)
        {
            m_carte.insert(std::pair<CarteFixe const*, unsigned int>(it, it->getID()));
        }
    }

    CarteFixe const* toPointer(unsigned int id)
    {
        CarteFixe const* sortie(nullptr);
        for(auto it : m_carte)
        {
            if(it.second == id)
            {
                sortie = it.first;
            }
        }

        return sortie;
    }

    unsigned int toID(CarteFixe const* pointer)
    {
        return pointer->getID();
    }
}
