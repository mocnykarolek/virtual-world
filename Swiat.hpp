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
        void addOrganism(Organizm* organizm);
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
        void add_log(std::string log);
        void run();
        Swiat();
        void drawOrganism(Organizm* org);
        Organizm* getCell(Vector2d c);
        bool isOccupied(int x, int y);
        std::vector<Vector2d> getFreeNeighbours(int x, int y);
        int get_human_dir() const;
        ~Swiat();

    
};