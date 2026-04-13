#pragma once


#include "Organizm.hpp"
class Organizm;

class Zwierze : public Organizm {
    private:

    protected:
        virtual void akcja()=0;
        virtual void randomMove()=0;
        // virtual void rozmnarzanie();
        virtual bool czyOdbilAtak(Organizm* attacker)=0;
        // virtual void setInitailCords(Vector2d cords);


    public:
        
        Zwierze(int x, int y, Swiat* world);
        int getSila() const;
        int getInicjatywa() const;
        int getAge();
        int getX();
        int getY() const;


        

};