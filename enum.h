#ifndef ENUM_H_INCLUDED
#define ENUM_H_INCLUDED

enum {ENERGIE1 = 0, ENERGIE2 = 1, ENERGIE3 = 2, ENERGIE4 = 3, ENERGIEALL = 4};

#define NENERGIE1 "Ener1"
#define NENERGIE2 "Ener2"
#define NENERGIE3 "Ener3"
#define NENERGIE4 "Ener4"

enum Domaine : short
{
    DOMAINE1 = 0,
    DOMAINE2 = 1,
    DOMAINE3 = 2,
    DOMAINE4 = 3
};

enum Type : short
{
    CREATURE = 0,
    ENERGIE = 1,
    SPECIALECOURTE = 2,
    SPECIALEPERMANENTE = 3
};

#endif // ENUM_H_INCLUDED
