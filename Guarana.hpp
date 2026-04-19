#pragma once

#include "Roslina.hpp"

class Roslina;
class Guarana : public Roslina {


    private:
       

    protected:
        void eaten_plant(Organizm* attacker);

    public:

        Guarana(int x, int y, Swiat* world);
        
        
        bool czyOdbilAtak(Organizm* attacker);
        
        
        void new_organism(Vector2d child_cords);
        


};