#include "Swiat.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>


#include "Czlowiek.hpp"
#include "Trawa.hpp"
#include "Wilk.hpp"

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
    menu = newwin(HEIGHT, WIDTH*2, 1, WIDTH+1);
    next_human_move = 0;
    grid.resize(20, std::vector<Organizm*>(20, nullptr));
    Vector2d test = random_unoccupied_cords();
    std::string test_log = "X: " + std::to_string(test.x) + " Y: " + std::to_string(test.y) + "\n";
    add_log(test_log);

    generateInitialWorld();


}

Vector2d Swiat::random_unoccupied_cords(){
    
    Vector2d cords;
    int random_x = (std::rand()%19)+1;
    int random_y = (std::rand()%19)+1;
    
    while(grid[random_x][random_y] != nullptr){
        random_x = (std::rand()%19)+1;
        random_y = (std::rand()%19)+1;

    }
    cords.x = random_x;
    cords.y = random_y;

    return cords;


}

void Swiat::drawOrganism(Organizm* org){

    
    mvwaddch(win, org->getY(), org->getX(), org->getAscii());


}

Organizm* Swiat::getCell(Vector2d c){
    
    return grid[c.y][c.x];


}

bool Swiat::isOccupied(int x, int y){

    if(grid[y][x] == nullptr){
        return false;
    }
    return true;


}

void Swiat::render_logs(){
    int max_logs = 18;
    while((int)logs.size() > max_logs) {logs.erase(logs.begin());}
    
    werase(menu);
    mvwprintw(menu, 0, 0," Numer Tury: %d", this->numer_tury);
    for (int i = 0; i < (int)logs.size(); i++)
    {
        mvwprintw(menu, i+1, 1,"%s", logs[i].c_str());
    }
    wrefresh(menu);


}

void Swiat::add_log(std::string log){
    log = "L: " + log;
    logs.push_back(log);

}

void Swiat::generateInitialWorld(){

    Czlowiek* czlowiek = new Czlowiek(20,20,this);
    addOrganism(czlowiek);
    Trawa* trawa = new Trawa(1,1, this);
    addOrganism(trawa);

    // dodaj trawe
    int grass_number = 3;
    for (int i = 0; i < grass_number; i++)
    {
        Vector2d freeCords = this->random_unoccupied_cords();
        addOrganism(new Trawa(freeCords.x,freeCords.y, this));
    }

    int wolf_number = 5;

    for (int i = 0; i < wolf_number; i++)
    {
        Vector2d freeCords = this->random_unoccupied_cords();
        addOrganism(new Wilk(freeCords.x,freeCords.y, this));
    }



    
    // Vector2d ranCords;
    // ranCords.x = 10;
    // ranCords.y = 10;
    // czlowiek->setInitailCords(ranCords);
    // this->addOrganism()

}

void Swiat::updateGrid(Organizm* o, Vector2d old_cords, Vector2d new_cords){
    grid[old_cords.y][old_cords.x] = nullptr;
    grid[new_cords.y][new_cords.x] = o;
    
}

void Swiat::collision_handling(){

    for (int i = 0; i < (int)organizmy.size();)
    {
        if(organizmy[i]->is_alive() == false){
            this->removeOrganism(organizmy[i]);
        } else{
            i++;
        }
    }
    
    


}

void Swiat::wykonajTure(){
    logs.erase(logs.begin(), logs.end());
    add_log("Nowa Tura");

    
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
        organizm->incrementAge();
        
        
    }
    collision_handling();
    


    render_logs();
    // rysujSwiat();



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

void Swiat::removeOrganism(Organizm* organizm){
    if(grid[organizm->getY()][organizm->getX()] == organizm){
    grid[organizm->getY()][organizm->getX()] = nullptr;
    }
    for (int i = 0; i < organizmy.size(); i++)
    {
        if(organizmy[i] == organizm){
            organizmy.erase(i + organizmy.begin());
            break;
        }
    }
    delete(organizm);


}
int Swiat::get_human_dir() const{

    return next_human_move;

}


bool Swiat::handle_input(){
    
    int ch;
    bool end_of_check = false;

    while(!end_of_check){
        ch = getch();
        switch (ch)
        {
        case 'w':
            next_human_move = NORTH;
            end_of_check = true;
            break;
        case 'd':
            next_human_move = EAST;
            end_of_check = true;
            break;
        case 's':
            next_human_move = SOUTH;
            end_of_check = true;
            break;
        case 'a':
            next_human_move = WEST;
            end_of_check = true;
            break;
        case 'e':
            return true;
        
        default:
            break;
        }

        

    }
    return false;

}

void Swiat::run(){
    
    
    int GameOver = false;

    rysujSwiat();
    while(!GameOver){
        wrefresh(win);
        
        GameOver = handle_input();
        

        wykonajTure();
        
        

        numer_tury++;
        rysujSwiat();
    }
    



}