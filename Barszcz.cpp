#include "Barszcz.hpp"


Barszcz::Barszcz(int x, int y, Swiat* world) : Roslina::Roslina(x, y, world){

    asciiSymbol = 'B';
    sila = 10;
    age = 0;
    name="Trawa";
    alive = true;



}

std::vector<Organizm*> Barszcz::get_neighboring_animals(){
    std::vector<Organizm*> positions_array;
    Vector2d vec = this->cords;
    
    // std::vector<Vector2d> positions_array;
    if(vec.y < WORLD_HEIGHT){
        Organizm* org =  world->getCell({vec.x, vec.y+1});
        if(org != nullptr && org->is_plant() == false)
        positions_array.push_back(org);
    } 
    if(vec.y > 1){
        Organizm* org =  world->getCell({vec.x, vec.y-1});
        
        if(org != nullptr && org->is_plant() == false)
        positions_array.push_back(org);
        
    } 
    if(vec.x < WORLD_WIDTH){
        Organizm* org =  world->getCell({vec.x+1, vec.y});
        if(org != nullptr && org->is_plant() == false)
        positions_array.push_back(org);
       
    } 
    if(vec.x > 1){
        Organizm* org =  world->getCell({vec.x-1, vec.y});
        if(org != nullptr && org->is_plant() == false)
        positions_array.push_back(org);
        
    }
    return positions_array;


}
void Barszcz::akcja(){

    std::vector<Organizm*> neighboring_cells = get_neighboring_animals();
    for (int i = 0; i < neighboring_cells.size(); i++)
    {
        world->add_log("Barszcz zabil zwierze");
        neighboring_cells[i]->kill();
    }
    
    Roslina::akcja();


}
        
bool Barszcz::czyOdbilAtak(Organizm* attacker){return false;}


void Barszcz::eaten_plant(Organizm* attacker){

    this->kill();
    world->add_log("Barszcz Sosnowskiego zabija zwierze");
}


void Barszcz::new_organism(Vector2d child_cords){
    world->addOrganism(new Barszcz(child_cords.x ,child_cords.y,world));
    world->add_log("Barszcz Sosnowskiego sie rozsial");

}