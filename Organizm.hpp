#pragma once

#include "structs.hpp"
#include "Swiat.hpp"

class Swiat;

class Organizm{
    private:
        

    protected:
        int sila;
        int inicjatywa;

        struct Vector2d cords;
        Swiat* world;
        int age;

        
        virtual void kolizja(Organizm* other)=0;
        virtual bool czyOdbilAtak(Organizm* attacker)=0;
        char asciiSymbol;
        

        
    public:
        Organizm(int x, int y, Swiat* world);
        void setInitailCords(Vector2d cords);
        void rysowanie();
        virtual void akcja()=0;
        int getSila();
        int getInicjatywa();
        int getAge();
        int getX();
        int getY();
        int getAscii();

};  