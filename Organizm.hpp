#pragma once
#include <string>
#include "structs.hpp"
#include "Swiat.hpp"

class Swiat;

class Organizm{
    private:
        

    protected:
        int sila;
        int inicjatywa;
        std::string name;
        struct Vector2d cords;
        Vector2d prev_cords;
        Swiat* world;
        int age;
        bool alive;
        
        
        virtual bool czyOdbilAtak(Organizm* attacker)=0;
        Vector2d randomMove();
        char asciiSymbol;
        

        
    public:
        Organizm(int x, int y, Swiat* world);
        void setInitailCords(Vector2d cords);
        virtual void kolizja(Organizm* other);
        void rysowanie();
        virtual void akcja()=0;
        int getSila();
        int getInicjatywa();
        int getAge();
        int getX();
        int getY();
        int getAscii();
        void incrementAge();
        bool is_alive();
        void kill();
        virtual ~Organizm() = default;

};  