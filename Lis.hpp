#pragma once

#include "Zwierze.hpp"

class Zwierze;
class Lis : public Zwierze {


    private:
        
        
    protected:

        Vector2d randomMove();
    public:

        Lis(int x, int y, Swiat* world);
        void new_organism(Vector2d child_cords);
 
    


};