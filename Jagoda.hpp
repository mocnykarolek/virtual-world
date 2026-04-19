#pragma once

#include "Roslina.hpp"

class Roslina;
class Jagoda : public Roslina {


    private:
       

    protected:
        void eaten_plant(Organizm* attacker);

    public:

        Jagoda(int x, int y, Swiat* world);
        // void akcja();
        
        bool czyOdbilAtak(Organizm* attacker);
        
        // void reporoduction_attempt(Organizm* o);
        void new_organism(Vector2d child_cords);
    


};