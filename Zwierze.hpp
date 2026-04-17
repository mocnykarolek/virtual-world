#pragma once


#include "Organizm.hpp"
class Organizm;

class Zwierze : public Organizm {
    private:

    protected:
        virtual void akcja();
        // Vector2d randomMove();
        // virtual void rozmnarzanie();
        // virtual bool czyOdbilAtak(Organizm* attacker);
        // virtual void setInitailCords(Vector2d cords);
        // virtual void kolizja();
        // virtual void kolizja(Organizm* other);

    public:
        
        Zwierze(int x, int y, Swiat* world);
        // int getSila() const;
        // int getInicjatywa() const;
        // int getAge();
        // int getX();
        // int getY() const;


        

};