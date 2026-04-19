#pragma once

#include "Zwierze.hpp"

class Zwierze;
class Zolw : public Zwierze {


    private:
        // char asciiSymbol;

    protected:


    public:

        Zolw(int x, int y, Swiat* world);
        void new_organism(Vector2d child_cords);
        // void akcja();
        // Vector2d randomMove();
        Vector2d action_modifier();
        // bool czyOdbilAtak(Organizm* attacker);
        // void kolizja(Organizm* other);
        bool czyOdbilAtak(Organizm* attacker);


};