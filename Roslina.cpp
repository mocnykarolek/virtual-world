
#include "Roslina.hpp"
Roslina::Roslina(int x, int y, Swiat* world) : Organizm(x, y ,world){
    
    inicjatywa = 0;
    
    
}
void Roslina::kolizja(Organizm* other){

}

void Roslina::akcja(){
    
    double probality = (rand() % 50) ;

    if(probality == 3)
    {
        reporoduction_attempt(this);
    }

    




}

void Roslina::reporoduction_attempt(Organizm* o){
    
    std::vector<Vector2d> free_cells = world->getFreeNeighbours({o->getX(), o->getY()});

    if(!free_cells.empty()){

        new_organism({free_cells[0].x,free_cells[0].y});

    }
    else{
        world->add_log("Brak miejsca na rozsianie rosliny");
    }
    


}


void Roslina::rysowanie(){
    this->world->drawOrganism(this);

}
