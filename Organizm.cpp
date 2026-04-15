#include "Organizm.hpp"
#include <cstdlib>
#include <ctime>

Organizm::Organizm(int x, int y, Swiat* world){
    cords.x = x;
    cords.y = y;
    this->world = world;
    // this->asciiSymbol = 'd';
    // alive = true;

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

        vec.x = this->cords.x + hor;
        vec.y = this->cords.y + ver;

        condition_x = vec.x > 0 && vec.x < 20;

        condition_y = vec.y > 0 && vec.y < 20;

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

void Organizm::kolizja(Organizm* other){
    
    world->add_log("Kolizja");
    if (this->name == "Wilk") {
    // jeśli wypisujesz logi ncurses, zrób to tam. 
    // tu piszę pseudo-kodem:
    std::string ve = "Wilk zaatakowal organizm: " + other->name + " o sile " + std::to_string(other->getSila());
    this->world->add_log(ve);
}
    if(this->getSila() > other->getSila()){
        other->kill();
    }else if(this->getSila() < other->getSila()){
        this->kill();

    }else{

        other->kill();



    }


}

bool Organizm::czyOdbilAtak(Organizm* attacker){
    

    return false;

}

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