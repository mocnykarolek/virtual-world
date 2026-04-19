#include "Antylopa.hpp"


// void Czlowiek::setInitailCords(Vector2d cords){

//     this->cords = cords;
    


// }

Antylopa::Antylopa(int x, int y, Swiat* world) : Zwierze(x, y, world){

    asciiSymbol = 'A';
    this->inicjatywa = 4;
    this->sila = 4;
    this->age = 0;
    name="Antylopa";
    alive = true;
    shift_range = 2;

}

bool Antylopa::czyOdbilAtak(Organizm* attacker){

    int chance = rand() %2;
    if(chance == 1){
        std::vector<Vector2d> available_cells = world->getFreeNeighbours(this->cords);

        if(!available_cells.empty()){

            

            world->updateGrid(this, this->cords, available_cells[0]);
            this->cords = available_cells[0];
            world->add_log("Antylopa uciekla");
            return true;
        }




        
    }
    

    return false;


}


// bool Wilk::czyOdbilAtak(Organizm* attacker){}

void Antylopa::new_organism(Vector2d child_cords){


    world->addOrganism(new Antylopa(child_cords.x, child_cords.y, world));
    world->add_log("Rodzi sie Antylopa");

}
