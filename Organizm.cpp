#include "Organizm.hpp"


Organizm::Organizm(int x, int y, Swiat* world){
    cords.x = x;
    cords.y = y;
    this->world = world;

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