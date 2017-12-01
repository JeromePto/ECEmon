#ifndef ENUM_H_INCLUDED
#define ENUM_H_INCLUDED

enum {ENERGIE1 = 0, ENERGIE2 = 1, ENERGIE3 = 2, ENERGIE4 = 3, ENERGIEALL = 4};

#define NENERGIE1 "Chanteur"
#define NENERGIE2 "Musicien"
#define NENERGIE3 "Peintre"
#define NENERGIE4 "Acteur"

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
