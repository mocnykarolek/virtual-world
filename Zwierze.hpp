#pragma once


#include "Organizm.hpp"
class Organizm;

class Zwierze : public Organizm {
    private:

    protected:
        virtual void akcja();
        

    public:
        
        Zwierze(int x, int y, Swiat* world);
       

        

};