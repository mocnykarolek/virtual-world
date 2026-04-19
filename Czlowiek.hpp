#pragma once

#include "Zwierze.hpp"

class Zwierze;
class Czlowiek : public Zwierze {


    private:
        // char asciiSymbol;
        bool special_ability_acticated;
        int round_of_activation;
        int current_round;
        int elixir_bonus;
        int cooldown_left;

    protected:


    public:

        Czlowiek(int x, int y, Swiat* world);
        void akcja();
        void handle_special_ability();
       
        void new_organism(Vector2d parent_cords);
       
        
        int getSila();


};