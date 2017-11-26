#include "divers.h"

namespace Divers
{
    bool isPrint(std::string const& chaine)
    {
        bool sortie(true);
        for(std::string::const_iterator it = chaine.cbegin() ; it != chaine.cend() ; ++it)
        {
            if(!isprint(*it))
            {
                sortie = false;
            }
        }

        return sortie;
    }
}
