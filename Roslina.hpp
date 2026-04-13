#pragma once


#include "Organizm.hpp"


class Roslina : public Organizm {

    private:
        int inicjatywa = 0;
    
    protected:

    
    public:
        void akcja();
        void kolizja(Organizm* other);
        void rysowanie();



};