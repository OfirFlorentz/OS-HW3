
#include "../Code2//Game.hpp"

void test1() {
    struct game_params p1;
    p1.n_gen = 40;
    p1.n_thread = 5;
    p1.filename = "../Tools/example_IO_files/mid.txt";
    p1.interactive_on = false;
    p1.print_on = true;

    Game* g = new  Game(p1);
    g->run();

}

int main(){


    test1();

}