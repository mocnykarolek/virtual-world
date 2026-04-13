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

        int numer_tury;
        void wykonajTure();
        void rysujSwiat();
        WINDOW *win;
        WINDOW* menu;
        std::vector<std::string> logs;
        void addOrganism(Organizm* organizm);
        void removeOrganism(Organizm* organizm);
        void handle_input();
        void drawFrame();
        void drawBackGround();
        void generateInitialWorld();

        void render_logs();

        Vector2d random_unoccupied_cords();

    protected:
        

    public:
        void add_log(std::string log);
        void run();
        Swiat();
        void drawOrganism(Organizm* org);
        Vector2d getCell(int x, int y);
        Vector2d isOccupied(int x, int y);
        std::vector<Vector2d> getFreeNeighbours(int x, int y);

        ~Swiat();

    
};