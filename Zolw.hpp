#pragma once

#include "Zwierze.hpp"

class Zwierze;
class Zolw : public Zwierze {


    private:
        

    protected:


    public:

        Zolw(int x, int y, Swiat* world);
        void new_organism(Vector2d child_cords);
        
        Vector2d action_modifier();
        
        bool czyOdbilAtak(Organizm* attacker);


};