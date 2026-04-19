#include "Jagoda.hpp"


Jagoda::Jagoda(int x, int y, Swiat* world) : Roslina::Roslina(x, y, world){

    asciiSymbol = 'J';
    sila = 99;
    age = 0;
    name="Jagoda";
    alive = true;



}



        
bool Jagoda::czyOdbilAtak(Organizm* attacker){
    (void)attacker;
    return false;}


void Jagoda::eaten_plant(Organizm* attacker){

    this->kill();
    attacker->kill();
    world->add_log("Wilcza jagoda zabija zwierze");
}


void Jagoda::new_organism(Vector2d child_cords){
    world->addOrganism(new Jagoda(child_cords.x ,child_cords.y,world));
    world->add_log("Jagoda sie rozsiala");

}