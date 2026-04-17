#include "Lis.hpp"


// void Czlowiek::setInitailCords(Vector2d cords){

//     this->cords = cords;
    


// }

Lis::Lis(int x, int y, Swiat* world) : Zwierze(x, y, world){

    asciiSymbol = 'L';
    this->inicjatywa = 7;
    this->sila = 3;
    this->age = 0;
    name="Lis";
    alive = true;

}

Vector2d Lis::randomMove(){
    // potencjalny segment
    
    std::vector<Vector2d> available_moves;


    Vector2d c = this->cords;
    if(c.x + 1 < WORLD_WIDTH){
        Organizm* cell = world->getCell({c.x+1, c.y});
        if(cell == nullptr || cell->getSila() <= this->getSila()){
            available_moves.push_back({c.x+1, c.y});
        }

    }
    if(c.x - 1 > 0){
        Organizm* cell = world->getCell({c.x-1, c.y});
        if(cell == nullptr || cell->getSila() <= this->getSila()){
            available_moves.push_back({c.x-1, c.y});
        }

    }
    if(c.y + 1 < WORLD_HEIGHT){
        Organizm* cell = world->getCell({c.x, c.y+1});
        if(cell == nullptr || cell->getSila() <= this->getSila()){
            available_moves.push_back({c.x, c.y+1});
        }

    }
    if(c.y - 1 > 0){
        Organizm* cell = world->getCell({c.x, c.y-1});
        if(cell == nullptr || cell->getSila() <= this->getSila()){
            available_moves.push_back({c.x, c.y-1});
        }

    }

    if(available_moves.empty()){
        return {this->getX(), this->getY()};

    }

    return available_moves[rand() % available_moves.size()];


}

// bool Wilk::czyOdbilAtak(Organizm* attacker){}

void Lis::new_organism(Vector2d child_cords){


    world->addOrganism(new Lis(child_cords.x, child_cords.y, world));
    world->add_log("Rodzi sie Lis");

}
