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
        bool czyOdbilAtak(Organizm* attacker);
        void kolizja(Organizm* other);
    


};