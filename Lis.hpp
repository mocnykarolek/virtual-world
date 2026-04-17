#pragma once

#include "Zwierze.hpp"

class Zwierze;
class Lis : public Zwierze {


    private:
        // char asciiSymbol;
        void find_cell();
        
    protected:

        Vector2d randomMove();
    public:

        Lis(int x, int y, Swiat* world);
        void new_organism(Vector2d child_cords);
        // void akcja();
        
        // bool czyOdbilAtak(Organizm* attacker);
        // void kolizja(Organizm* other);
    


};