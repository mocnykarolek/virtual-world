#pragma once

#include "Roslina.hpp"

class Roslina;
class Trawa : public Roslina {


    private:
       

    protected:


    public:

        Trawa(int x, int y, Swiat* world);
        
        
        bool czyOdbilAtak(Organizm* attacker);
        
        
        void new_organism(Vector2d child_cords);
    


};