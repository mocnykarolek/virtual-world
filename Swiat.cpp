#include "Swiat.hpp"

#define WIDTH 20
#define HEIGHT 20


Swiat::Swiat(){

    
    initscr();  

    noecho();             

    cbreak();            
    
    keypad(stdscr, TRUE); 

    curs_set(0);  

    
    win = newwin(HEIGHT+1, (WIDTH+1)*2,1,1);
    

}

Swiat::~Swiat(){


    delwin(win);
    endwin(); 


}

void Swiat::rysujSwiat(){

    werase(win);
    box(win, 0, 0);

    mvwprintw(win, 1,1 ,"#");

    wrefresh(win);


}

void Swiat::run(){
    
    int GameOver = false;

    while(!GameOver){

        this->rysujSwiat();


    }
    



}