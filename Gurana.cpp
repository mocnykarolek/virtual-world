#include "Guarana.hpp"


Guarana::Guarana(int x, int y, Swiat* world) : Roslina::Roslina(x, y, world){

    asciiSymbol = 'G';
    sila = 0;
    age = 0;
    name="Guarana";
    alive = true;



}


// void Trawa::akcja(){

// }
        
bool Guarana::czyOdbilAtak(Organizm* attacker){
    (void)attacker;
    return false;}


void Guarana::eaten_plant(Organizm* attacker){
    attacker->increaseStrength(3);
    world->add_log("Guarana dodala sile");
}


void Guarana::new_organism(Vector2d child_cords){
    world->addOrganism(new Guarana(child_cords.x ,child_cords.y,world));
    world->add_log("Guarana sie rozsiala");

}