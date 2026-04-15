#include "Trawa.hpp"


Trawa::Trawa(int x, int y, Swiat* world) : Roslina::Roslina(x, y, world){

    asciiSymbol = 'T';
    sila = 0;
    age = 0;
    name="Trawa";
    alive = true;



}


// void Trawa::akcja(){

// }
        
bool Trawa::czyOdbilAtak(Organizm* attacker){return false;}
void Trawa::kolizja(Organizm* other){}

