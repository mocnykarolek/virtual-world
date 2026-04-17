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

void Czlowiek::nextMove(int direction){

    
    
}

void Czlowiek::akcja(){
    Vector2d old_cords = this->cords;

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
    
    

}
void Czlowiek::randomMove(){
    


}
bool Czlowiek::czyOdbilAtak(Organizm* attacker){

}
void Czlowiek::kolizja(Organizm* other){
    
}
void Czlowiek::new_organism(Vector2d parent_cords){}