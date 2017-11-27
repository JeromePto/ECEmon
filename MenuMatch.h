#ifndef MENUMATCH_H_INCLUDED
#define MENUMATCH_H_INCLUDED

class Menu;
class Match;

class MenuMatch
{
public:
    static Menu * m_menu;
    static Match * m_match;

    static void lancerMatch();
};

#endif // MENUMATCH_H_INCLUDED
