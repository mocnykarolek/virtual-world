#include "Swiat.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>


#include "Czlowiek.hpp"

#define WIDTH 22
#define HEIGHT 22


Swiat::Swiat(){
    std::srand(std::time(NULL));
    
    initscr();  

    noecho();             

    cbreak();            
    
    keypad(stdscr, TRUE); 

    curs_set(0);  

    numer_tury = 1;
    win = newwin(HEIGHT, WIDTH,1,1);
    menu = newwin(HEIGHT, WIDTH, 1, WIDTH+1);

    grid.resize(20, std::vector<Organizm*>(20, nullptr));
    Vector2d test = random_unoccupied_cords();
    std::string test_log = "X: " + std::to_string(test.x) + " Y: " + std::to_string(test.y) + "\n";
    add_log(test_log);

    generateInitialWorld();


}

Vector2d Swiat::random_unoccupied_cords(){
    
    Vector2d cords;
    int random_x = std::rand()%20;
    int random_y = std::rand()%20;
    
    while(grid[random_x][random_y] != nullptr){
        random_x = std::rand()%20;
        random_y = std::rand()%20;

    }
    cords.x = random_x;
    cords.y = random_y;

    return cords;


}

void Swiat::drawOrganism(Organizm* org){

    
    mvwaddch(win, org->getY(), org->getX(), org->getAscii());


}

void Swiat::render_logs(){
    int max_logs = 18;
    while((int)logs.size() > max_logs) {logs.erase(logs.begin());}
    
    werase(menu);
    for (int i = 0; i < (int)logs.size(); i++)
    {
        mvwprintw(menu, i+1, 1,"%s", logs[i].c_str());
    }
    wrefresh(menu);


}

void Swiat::add_log(std::string log){

    logs.push_back(log);

}

void Swiat::generateInitialWorld(){

    Czlowiek* czlowiek = new Czlowiek(19,19,this);
    addOrganism(czlowiek);
    // Vector2d ranCords;
    // ranCords.x = 10;
    // ranCords.y = 10;
    // czlowiek->setInitailCords(ranCords);
    // this->addOrganism()

}



void Swiat::wykonajTure(){

    
    sort(organizmy.begin(), organizmy.end(), [](Organizm*a, Organizm* b){ 
        if(a->getInicjatywa() == b->getInicjatywa()){
            return a->getAge() < b->getAge();
        }
        else return a->getInicjatywa() < b->getInicjatywa();
    }
    );

    for (Organizm* organizm : organizmy)
    {
        organizm->akcja();
    }
    


    render_logs();
    rysujSwiat();



}

Swiat::~Swiat(){


    delwin(win);
    endwin(); 


}

void Swiat::drawFrame(){
    // gora
    int N = HEIGHT;
    int M = WIDTH;
    for (int x = 0; x < N; x++) {
        mvwaddch(win, 0, x, '#');
    }

    // dolna krawędź
    for (int x = 0; x < N; x++) {
        mvwaddch(win, M - 1, x, '#');
    }

    // lewa krawędź
    for (int y = 0; y < M; y++) {
        mvwaddch(win, y, 0, '#');
    }

    // prawa krawędź
    for (int y = 0; y < M; y++) {
        mvwaddch(win, y, N - 1, '#');
    }



}
void Swiat::drawBackGround(){

    for (int i = 1; i < HEIGHT-1; i++)
    {
        for (int j = 1; j < WIDTH-1; j++)
        {
            mvwaddch(win,i,j, '.');
        }
        
    }
    
    // mvwaddch(win, 20,20,'1');


}


void Swiat::rysujSwiat(){

    werase(win);
    drawFrame();
    drawBackGround();

    for (Organizm* organizm : organizmy)
    {
        organizm->rysowanie();
    }
    
    // mvwprintw(win, 1,1 ,"@");

    wrefresh(win);


}

void Swiat::addOrganism(Organizm* organizm){

    organizmy.push_back(organizm);

    grid[organizm->getY()][organizm->getX()] = organizm;
    

}


void Swiat::handle_input(){

    

}

void Swiat::run(){
    
    
    int GameOver = false;

    while(!GameOver){

        wykonajTure();

        numer_tury++;

    }
    



}