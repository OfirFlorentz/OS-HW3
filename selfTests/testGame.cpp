
#include "../Code_Skeleton/Game.hpp"

Game* test1(struct game_params p) {

    Game* g = new  Game(p);
    return g;
}

int main(){
    struct game_params p1;
    p1.n_gen = 40;
    p1.n_thread = 2;
    p1.filename = "../Tools/example_IO_files/mid.txt";
    p1.interactive_on = false;
    p1.print_on = true;

    Game* g = test1(p1);
    g->run();


}