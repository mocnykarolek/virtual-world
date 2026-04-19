#include "Mlecz.hpp"


Mlecz::Mlecz(int x, int y, Swiat* world) : Roslina::Roslina(x, y, world){

    asciiSymbol = 'M';
    sila = 0;
    age = 0;
    name="Mlecz";
    alive = true;



}


// void Trawa::akcja(){

// }
        
bool Mlecz::czyOdbilAtak(Organizm* attacker){
    (void)attacker;
    return false;}



void Mlecz::akcja(){
    int attempts = 3;
    
    for (int i = 0; i < attempts; i++)
    {
        double probality = (rand() % 44) ;

        if(probality == 3)
        {
            reporoduction_attempt(this);
            
        }

        
    }
    

    

    




}

void Mlecz::new_organism(Vector2d child_cords){
    world->addOrganism(new Mlecz(child_cords.x ,child_cords.y,world));
    world->add_log("Mlecz sie rozsiala");

}