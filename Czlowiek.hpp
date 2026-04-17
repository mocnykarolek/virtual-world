#pragma once

#include "Zwierze.hpp"

class Zwierze;
class Czlowiek : public Zwierze {


    private:
        // char asciiSymbol;
        

    protected:


    public:

        Czlowiek(int x, int y, Swiat* world);
        void akcja();
        void randomMove();
        void new_organism(Vector2d parent_cords);
        bool czyOdbilAtak(Organizm* attacker);
        void kolizja(Organizm* other);
        void nextMove(int direction);
    


};