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

bool Wilk::czyOdbilAtak(Organizm* attacker){}

void Wilk::new_organism(Vector2d parent_cords){


    world->addOrganism(new Wilk(parent_cords.x, parent_cords.y, world));

}
