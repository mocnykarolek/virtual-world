#include "Organizm.hpp"
#include <cstdlib>
#include <ctime>

Organizm::Organizm(int x, int y, Swiat* world){
    cords.x = x;
    cords.y = y;
    this->world = world;
    can_organism_move = 1;
    // this->asciiSymbol = 'd';
    // alive = true;

}

Vector2d Organizm::action_modifier(){

    return randomMove();
}

Vector2d Organizm::randomMove(){

    
    int side;
    int dir;
    Vector2d vec;
    bool condition_x;
    bool condition_y;

    do{
        int ver=0;
        int hor=0;
        side = rand()% 2;
        dir = rand()% 2;
        if(dir == 0) dir = -1;

        if(side) ver = dir;
        else hor = dir;
        // if(rand_x == 0) rand_x = -1;
        // if(rand_y == 0) rand_y = -1;

        vec.x = this->cords.x + hor*shift_range;
        vec.y = this->cords.y + ver*shift_range;

        condition_x = vec.x > 0 && vec.x <= WORLD_WIDTH;

        condition_y = vec.y > 0 && vec.y <= WORLD_HEIGHT;

    }while(!(condition_x && condition_y));


    return vec;
    

}

void Organizm::incrementAge(){

    this->age++;

}

bool Organizm::is_alive(){

    return alive;


}
void Organizm::kill(){
    this->alive = false;
}
bool Organizm::is_plant(){
    return false;
}


void Organizm::kolizja(Organizm* other){

    world->add_log("Kolizja");
    
    if(this->getAscii() == other->getAscii()){ // reporduction

        // new_organism(this->cords);
        can_organism_move = false;


        std::vector<Vector2d> child_cords = world->getFreeNeighbours(this->cords);
        if(!child_cords.empty()){
            
            new_organism(child_cords[0]);

            
        }else{


            world->add_log("Brak miejsca na rozmnazanie");
        }
        
    }
    else{ // combat


        if(other->czyOdbilAtak(this)){
            can_organism_move = false;
            world->add_log("Atak zostal unikniety");

        }else if(this->getSila() >= other->getSila()){
            other->eaten_plant(this);
            other->kill();
            // return true;
            
        }else{
            if(other->is_plant()) other->eaten_plant(this);
            this->kill();
        }

        
}
    // return can_move;

}

void Organizm::increaseStrength(int points){
    this->sila = this->sila + points;
}


bool Organizm::czyOdbilAtak(Organizm* attacker){
        return false;
        


}



void Organizm::eaten_plant(Organizm* attacker){}

void Organizm::setInitailCords(Vector2d cords){

    this->cords = cords;
    


}

int Organizm::getAge(){

    return this->age;

    
}

void Organizm::rysowanie(){
    
    world->drawOrganism(this);
    

}


int Organizm::getAscii(){

    return this->asciiSymbol;

}


int Organizm::getSila(){

    return this->sila;

    
}


int Organizm::getInicjatywa(){

    return this->inicjatywa;

    
}


int Organizm::getX(){

    return this->cords.x;

    
}


int Organizm::getY(){

    return this->cords.y;

    
}