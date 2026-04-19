#pragma once

#include "Roslina.hpp"

class Roslina;
class Barszcz : public Roslina {


    private:
       std::vector<Organizm*> get_neighboring_animals();

    protected:
        void eaten_plant(Organizm* attacker);
        void akcja();
    public:

        Barszcz(int x, int y, Swiat* world);
        
        
        bool czyOdbilAtak(Organizm* attacker);
        
        
        void new_organism(Vector2d child_cords);
    


};