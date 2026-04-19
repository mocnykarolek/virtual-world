#pragma once

#include "Zwierze.hpp"

class Zwierze;
class Antylopa : public Zwierze {


    private:
       

    protected:


    public:

        Antylopa(int x, int y, Swiat* world);
        void new_organism(Vector2d child_cords);
        
        bool czyOdbilAtak(Organizm* attacker);
        
    


};