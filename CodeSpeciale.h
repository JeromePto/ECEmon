#ifndef CODESPECIALE_H_INCLUDED
#define CODESPECIALE_H_INCLUDED

#include "SpecialePermanenteFixe.h"
#include "SpecialeCourteFixe.h"
#include "CarteFixe.h"

#include <vector>
#include <iostream>
#include <windows.h>
#include <ctime>

class JoueurPartie;

class CodeSpeciale
{
private:
    JoueurPartie * m_moi;
    JoueurPartie * m_ennemi;
    unsigned m_codeActif;

public:

    CodeSpeciale();

    void init(JoueurPartie * moi, JoueurPartie * ennemi);

    void exeCode(unsigned numero, bool force = false, bool display = true);

    void lancerSpecialePermanente(SpecialePermanenteFixe const* carte, bool display = true);
    void stopSpecialePermanente();
    void lancerSpecialeCourte(SpecialeCourteFixe const* carte, bool display = true);

    void actionPermanente(bool display = true);

    void code1(bool display = true);
    void code2(bool force = false, bool display = true);
    void code2_inv();
    void code3(bool display = true);
    void code4(bool display = true);
    void code5(bool display = true);
    void code6(bool display = true);

    void clear();
};

#endif // CODESPECIALE_H_INCLUDED
