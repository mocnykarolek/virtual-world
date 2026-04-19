#include "Owca.hpp"


// void Czlowiek::setInitailCords(Vector2d cords){

//     this->cords = cords;
    


// }

Owca::Owca(int x, int y, Swiat* world) : Zwierze(x, y, world){

    asciiSymbol = 'S';
    this->inicjatywa = 4;
    this->sila = 4;
    this->age = 0;
    name="Owca";
    alive = true;

}

// bool Owca::czyOdbilAtak(Organizm* attacker){}




void Owca::new_organism(Vector2d child_cords){


    world->addOrganism(new Owca(child_cords.x, child_cords.y, world));
    world->add_log("Rodzi sie owca");

}
