
#include "../Code2//Game.hpp"

void test1() {
    struct game_params p1;
    p1.n_gen = 40;
    p1.n_thread = 2;
    p1.filename = "../Tools/example_IO_files/mid.txt";
    p1.interactive_on = false;
    p1.print_on = true;

    Game* g = new  Game(p1);
    g->run();

}

void test2(int thread) {
    struct game_params p1;
    p1.n_gen = 40;
    p1.n_thread = thread;
    p1.filename = "../Tools/example_IO_files/mid.txt";
    p1.interactive_on = false;
    p1.print_on = false;

    Game* g = new  Game(p1);
    g->run();

}

int main(){


//    test1();

    auto gen_start = std::chrono::system_clock::now();
    test2(1);
    auto gen_end = std::chrono::system_clock::now();
    cout<< "time for 1 thread was " << ((float)std::chrono::duration_cast<std::chrono::microseconds>(gen_end-gen_start).count()) << endl;

    gen_start = std::chrono::system_clock::now();
    int t = 8;
    test2(t);
    gen_end = std::chrono::system_clock::now();
    cout<< "time for " << t << " threads was " << ((float)std::chrono::duration_cast<std::chrono::microseconds>(gen_end-gen_start).count()) << endl;


}