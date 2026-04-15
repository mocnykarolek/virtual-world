#include "Czlowiek.hpp"


// void Czlowiek::setInitailCords(Vector2d cords){

//     this->cords = cords;
    


// }

Czlowiek::Czlowiek(int x, int y, Swiat* world) : Zwierze(x, y, world){

    asciiSymbol = 'H';
    this->inicjatywa = 4;
    this->sila = 5;
    age = 0;
    name="Czlowiek";
    alive = true;


}

void Czlowiek::akcja(){

}
void Czlowiek::randomMove(){
    


}
bool Czlowiek::czyOdbilAtak(Organizm* attacker){

}
void Czlowiek::kolizja(Organizm* other){
    
}
