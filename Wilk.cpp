#include "Wilk.hpp"




Wilk::Wilk(int x, int y, Swiat* world) : Zwierze(x, y, world){

    asciiSymbol = 'W';
    this->inicjatywa = 5;
    this->sila = 9;
    this->age = 0;
    name="Wilk";
    alive = true;

}



void Wilk::new_organism(Vector2d child_cords){


    world->addOrganism(new Wilk(child_cords.x, child_cords.y, world));
    world->add_log("Rodzi sie wilk");

}
