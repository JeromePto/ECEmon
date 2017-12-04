#ifndef DIVERS_H_INCLUDED
#define DIVERS_H_INCLUDED

#include <string>
#include <ctype.h>
#include <algorithm>
#include <iterator>
#include <conio.h>
#include <windows.h>

namespace Divers
{
    bool isPrint(std::string const& chaine);
    void setColor(int back, int front);
}

#endif // DIVERS_H_INCLUDED
