#pragma once


#include "Organizm.hpp"


class Roslina : public Organizm {

    private:
    
    
    protected:
        // virtual void akcja()=0;
        virtual bool czyOdbilAtak(Organizm* attacker)=0;
    
    public:
        Roslina(int x, int y, Swiat* world);
        virtual void akcja();
        virtual void kolizja(Organizm* other)=0;
        void rysowanie();



};