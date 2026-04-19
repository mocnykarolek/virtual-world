#include "Trawa.hpp"


Trawa::Trawa(int x, int y, Swiat* world) : Roslina::Roslina(x, y, world){

    asciiSymbol = 'T';
    sila = 0;
    age = 0;
    name="Trawa";
    alive = true;



}


// void Trawa::akcja(){

// }
        
bool Trawa::czyOdbilAtak(Organizm* attacker){
    (void)attacker;
    return false;}





void Trawa::new_organism(Vector2d child_cords){
    world->addOrganism(new Trawa(child_cords.x ,child_cords.y,world));
    world->add_log("Trawa sie rozsiala");

}