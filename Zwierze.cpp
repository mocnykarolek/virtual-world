#include "Zwierze.hpp"


Zwierze::Zwierze(int x, int y, Swiat* world) : Organizm(x, y ,world){
          shift_range =1;                                                                             
}

// bool Zwierze::czyOdbilAtak(Organizm* attacker){

//     attacker->getSila();
    

//     return false;
// }

// void Zwierze::kolizja(Organizm* other){

    

// }

void Zwierze::akcja(){
    // this->prev_cords = this->cords;
    prev_cords = this->cords;
    Vector2d new_cords = action_modifier();
    

    can_organism_move =true;
    if(world->isOccupied(new_cords.x,new_cords.y)){
        
        if(world->getCell(new_cords) != this){
            kolizja(world->getCell(new_cords));

            if(this->is_alive()){
                if(can_organism_move){
                this->cords = new_cords;
                world->updateGrid(this, prev_cords, new_cords);
                }
            }

        }
        
    }else{

        this->cords = new_cords;
        world->updateGrid(this, prev_cords, new_cords);
    }


    // this->world->add_log("Wilk idzie");




}

