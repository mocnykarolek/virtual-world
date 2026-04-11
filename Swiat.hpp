#pragma once

#include "Organizm.hpp"
#include <ncurses.h>

class Swiat{
    private:
        Organizm* organizmy;
        int N,M;
        void wykonajTure();
        void rysujSwiat();
        WINDOW *win;
        

    public:
        
        void run();
        Swiat();
        
        
        ~Swiat();

    
};