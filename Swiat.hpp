#pragma once

#include "Organizm.hpp"
#include <ncurses.h>
#include <vector>
#include <string>

class Organizm;


class Swiat{
    private:
        // Organizm* organizmy;
        std::vector<Organizm*> organizmy;
        std::vector<std::vector<Organizm*>> grid;
        int next_human_move;
        int numer_tury;
        void wykonajTure();
        void rysujSwiat();
        WINDOW *win;
        WINDOW* menu;
        std::vector<std::string> logs;
        
        void removeOrganism(Organizm* organizm);
        bool handle_input();
        void drawFrame();
        void drawBackGround();
        void generateInitialWorld();
        // void get_human_dir();
        void render_logs();

        Vector2d random_unoccupied_cords();
        void collision_handling();


    protected:
        

    public:
        void updateGrid(Organizm* o, Vector2d old_cords, Vector2d new_cords);
        void add_log(std::string log);
        void run();
        Swiat();
        void addOrganism(Organizm* organizm);
        void drawOrganism(Organizm* org);
        Organizm* getCell(Vector2d c);
        bool isOccupied(int x, int y);
        Vector2d getFreeNeighbours(Vector2d vec);
        int get_human_dir() const;
        ~Swiat();

    
};