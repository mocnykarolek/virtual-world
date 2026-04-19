#pragma once

#include "Zwierze.hpp"

class Zwierze;
class Antylopa : public Zwierze {


    private:
        // char asciiSymbol;

    protected:


    public:

        Antylopa(int x, int y, Swiat* world);
        void new_organism(Vector2d child_cords);
        // void akcja();
        // Vector2d randomMove();
        bool czyOdbilAtak(Organizm* attacker);
        // void kolizja(Organizm* other);
    


};