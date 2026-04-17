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
    Vector2d old_cords = this->cords;
    Vector2d new_cords = randomMove();
    this->cords = new_cords;
    if(world->isOccupied(new_cords.x,new_cords.y)){
        
        if(world->getCell(new_cords) != this){
            kolizja(world->getCell(new_cords));

            if(this->is_alive()){
                this->cords = new_cords;
                world->updateGrid(this, old_cords, new_cords);
            }

        }
        
    }else{

        this->cords = new_cords;
        world->updateGrid(this, old_cords, new_cords);
    }


    // this->world->add_log("Wilk idzie");




}

