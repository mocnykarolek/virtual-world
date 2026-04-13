#include "Zwierze.hpp"


Zwierze::Zwierze(int x, int y, Swiat* world) : Organizm(x, y ,world){
                                                                                        
}

bool Zwierze::czyOdbilAtak(Organizm* attacker){

    attacker->getSila();
    

    return false;
}



