#include "Wilk.hpp"


// void Czlowiek::setInitailCords(Vector2d cords){

//     this->cords = cords;
    


// }

Wilk::Wilk(int x, int y, Swiat* world) : Zwierze(x, y, world){

    asciiSymbol = 'W';
    this->inicjatywa = 5;
    this->sila = 9;
    this->age = 0;
    name="Wilk";
    alive = true;

}



bool Wilk::czyOdbilAtak(Organizm* attacker){

}
// void Wilk::kolizja(Organizm* other){
    
// }
