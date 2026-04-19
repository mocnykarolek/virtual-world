#include "Czlowiek.hpp"




Czlowiek::Czlowiek(int x, int y, Swiat* world) : Zwierze(x, y, world){

    asciiSymbol = 'H';
    this->inicjatywa = 4;
    // this->sila = 5;
    age = 0;
    name="Czlowiek";
    alive = true;
    special_ability_acticated = false;
    elixir_bonus = 0;
    this->sila = 5 + elixir_bonus;
    cooldown_left = 0;

}


void Czlowiek::handle_special_ability(){

    if(special_ability_acticated && elixir_bonus > 0){
        elixir_bonus--;
    }
    
    if(special_ability_acticated && current_round - round_of_activation >= 5){
        special_ability_acticated = false;
        cooldown_left = 5;
        world->add_log("Czlowiekowi skonczyl sie eliksir");
    }


}


void Czlowiek::akcja(){
    if(world->human_special_ability_activated() != -1 && special_ability_acticated != true && cooldown_left == 0){
        special_ability_acticated = true;
        elixir_bonus = 5;
        world->add_log("Czlowiek wypil magiczny eliksir");
        round_of_activation = world->human_special_ability_activated();
    }
    if(cooldown_left >0) cooldown_left--;
    current_round = world->get_current_round();
    handle_special_ability();
    // world->add_log(std::to_string(getSila()));
    

    prev_cords = this->cords;

    Vector2d new_cords = this->cords;
    int next_move = world->get_human_dir();
    if(next_move == NORTH && this->cords.y > 1){
        new_cords.y--;
        world->add_log("Czlowiek idzie do gory");
    }else if(next_move == EAST && this->cords.x < WORLD_WIDTH){
        new_cords.x++;
        world->add_log("Czlowiek idzie w prawo");
    }else if(next_move == SOUTH && this->cords.y < WORLD_HEIGHT){
        world->add_log("Czlowiek idzie w dol");
        new_cords.y++;
    } else if(next_move == WEST && this->cords.x > 1){
        world->add_log("Czlowiek idzie w lewo");
        new_cords.x--;
    }


    
    
    
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
    
    

}

int Czlowiek::getSila(){
    return sila + elixir_bonus;
}

void Czlowiek::new_organism(Vector2d parent_cords){}