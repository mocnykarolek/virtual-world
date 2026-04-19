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
        int shift_range;
        
        
        virtual bool czyOdbilAtak(Organizm* attacker);
        virtual Vector2d randomMove();
        char asciiSymbol;
        bool can_organism_move;
        virtual void new_organism(Vector2d parent_cords)=0;
        virtual void eaten_plant(Organizm* attacker);
        virtual Vector2d action_modifier();
        
        
    public:
        Organizm(int x, int y, Swiat* world);
        void setInitailCords(Vector2d cords);
        virtual void kolizja(Organizm* other);
        void rysowanie();
        virtual bool is_plant();
        virtual void akcja()=0;
        void increaseStrength(int points);
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