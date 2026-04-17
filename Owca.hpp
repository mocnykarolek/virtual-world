#pragma once

#include "Zwierze.hpp"

class Zwierze;
class Owca : public Zwierze {


    private:
        // char asciiSymbol;

    protected:


    public:

        Owca(int x, int y, Swiat* world);
        void new_organism(Vector2d child_cords);
        // void akcja();
        
        // bool czyOdbilAtak(Organizm* attacker);
        // void kolizja(Organizm* other);
    


};