#pragma once


#include "Organizm.hpp"


class Roslina : public Organizm {

    private:
    
    
    protected:
        // virtual void akcja()=0;
        virtual bool czyOdbilAtak(Organizm* attacker)=0;
        virtual void reporoduction_attempt(Organizm* o);
        bool is_plant();
    public:
        Roslina(int x, int y, Swiat* world);
        virtual void akcja();

        virtual void kolizja(Organizm* other);
        void rysowanie();



};