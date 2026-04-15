#include "Zwierze.hpp"


Zwierze::Zwierze(int x, int y, Swiat* world) : Organizm(x, y ,world){
                                                                                        
}

bool Zwierze::czyOdbilAtak(Organizm* attacker){

    attacker->getSila();
    

    return false;
}

// void Zwierze::kolizja(Organizm* other){

    

// }

void Zwierze::akcja(){
    // this->prev_cords = this->cords;
    
    Vector2d new_cords = randomMove();
    this->cords = new_cords;
    if(world->isOccupied(new_cords.x,new_cords.y)){
        kolizja(world->getCell(new_cords));
    }


    // this->world->add_log("Wilk idzie");




}

