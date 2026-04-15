
#include "Roslina.hpp"
Roslina::Roslina(int x, int y, Swiat* world) : Organizm(x, y ,world){
    
    inicjatywa = 0;
    
    
}

void Roslina::akcja(){

    world->add_log("Roslina istnieje");


}

void Roslina::rysowanie(){
    this->world->drawOrganism(this);

}
