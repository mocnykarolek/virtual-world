#include "Zolw.hpp"


// void Czlowiek::setInitailCords(Vector2d cords){

//     this->cords = cords;
    


// }

Zolw::Zolw(int x, int y, Swiat* world) : Zwierze(x, y, world){

    asciiSymbol = 'Z';
    this->inicjatywa = 1;
    this->sila = 2;
    this->age = 0;
    name="Zolw";
    alive = true;

}

Vector2d Zolw::action_modifier(){
    int random = rand() % 4;
    if(random == 3){
        return randomMove();
    }
    else{
        return this->cords;
    }


}

bool Zolw::czyOdbilAtak(Organizm* attacker){
        if(attacker->getSila() < 5){
            // attacker->can_organism_move =false;
            return true;
        }
        else{

            return Organizm::czyOdbilAtak(attacker);
        }
        


}



// bool Owca::czyOdbilAtak(Organizm* attacker){}

void Zolw::new_organism(Vector2d child_cords){


    world->addOrganism(new Zolw(child_cords.x, child_cords.y, world));
    world->add_log("Rodzi sie Zolw");

}
