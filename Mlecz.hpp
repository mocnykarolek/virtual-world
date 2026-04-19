#pragma once

#include "Roslina.hpp"

class Roslina;
class Mlecz : public Roslina {


    private:
       

    protected:


    public:

        Mlecz(int x, int y, Swiat* world);
        
        
        bool czyOdbilAtak(Organizm* attacker);
        
        
        void new_organism(Vector2d child_cords);
        void akcja();


};