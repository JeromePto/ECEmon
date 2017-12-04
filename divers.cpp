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

    /*
    0: noir
    1: bleu foncé
    2: vert
    3: bleu-gris
    4: marron
    5: pourpre
    6: kaki
    7: gris clair
    8: gris
    9: bleu
    10: vert fluo
    11: turquoise
    12: rouge
    13: rose fluo
    14: jaune fluo
    15: blanc
    */
    void setColor(int back, int front)
    {
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,front*16+back);
    }
}
