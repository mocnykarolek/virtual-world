#pragma once

#include "Roslina.hpp"

class Roslina;
class Trawa : public Roslina {


    private:
       

    protected:


    public:

        Trawa(int x, int y, Swiat* world);
        // void akcja();
        
        bool czyOdbilAtak(Organizm* attacker);
        void kolizja(Organizm* other);

        void new_organism(Vector2d parent_cords);
    


};