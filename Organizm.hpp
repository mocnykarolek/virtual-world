#pragma once

#include "structs.hpp"
#include "Swiat.hpp"
class Swiat;

class Organizm{
    private:
        int sila;
        int inicjatywa;

        struct Vector2d cords;
        Swiat* world;
        int age;

    public:

        virtual void akcja();
        virtual void kolizja();
        virtual void rysowanie();

};  