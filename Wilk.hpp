#pragma once

#include "Zwierze.hpp"

class Zwierze;
class Wilk : public Zwierze {


    private:
        // char asciiSymbol;

    protected:


    public:

        Wilk(int x, int y, Swiat* world);
        // void akcja();
        
        bool czyOdbilAtak(Organizm* attacker);
        // void kolizja(Organizm* other);
    


};