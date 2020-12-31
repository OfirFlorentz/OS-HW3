#include "Game.hpp"
#include "utils.hpp"
#include "ThreadP.hpp"

static const char *colors[7] = {BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN};
inline static void print_board(const char* header) ;

/*--------------------------------------------------------------------------------

--------------------------------------------------------------------------------*/
Game::Game(game_params m_gp) : m_gen_num(m_gp.n_gen), interactive_on(m_gp.interactive_on), print_on(m_gp.print_on),
m_filename(m_gp.filename), m_gen_hist(), m_tile_hist(), m_threadpool(), m_board() {}


void Game::run() {

	_init_game(); // Starts the threads and all other variables you need
	print_board("Initial Board");
	for (uint i = 0; i < m_gen_num; ++i) {
		auto gen_start = std::chrono::system_clock::now();
		_step(i); // Iterates a single generation 
		auto gen_end = std::chrono::system_clock::now();
		m_gen_hist.push_back((float)std::chrono::duration_cast<std::chrono::microseconds>(gen_end - gen_start).count());
		print_board(NULL);
	} // generation loop
	print_board("Final Board");
	_destroy_game();
}


void Game::_init_game() {
    // Create game fields
    vector<string> temp = utils::read_lines(m_filename);
    for (auto& it : temp) {
        m_board.push_back(utils::split(it, ' '));
        m_old_board.push_back(utils::split(it, ' '));
    }


    if (m_thread_temp > m_board.size()) {
        m_thread_num = m_board.size();
    } else {
        m_thread_num = m_thread_temp;
    }

    int div = m_board.size() / m_thread_num;
    int remain = m_board.size() % m_thread_num;


    // Create threads n-1 first threads
    for (int i = 0; i < m_thread_num - 1; i++) {
        //TODO init thred
        m_threadpool.push_back(new ThreadP(i));
    }
    //TODO init last_thread
    m_threadpool.push_back(new ThreadP(m_thread_num-1));



// Start the threads
	// Testing of your implementation will presume all threads are started here
}

void Game::_step(uint curr_gen) {
	// Push jobs to queue
	// Wait for the workers to finish calculating
	// Swap pointers between current and next field

    int div = m_board.size() / m_thread_num;
    int remain = m_board.size() % m_thread_num;

    // start threads
    for (int i = 0; i < m_thread_num; ++i) {
        m_threadpool[i]->start();
    }
    for (int i = 0; i < m_thread_num; ++i) {
        m_threadpool[i]->join();
    }


    // swap old and new board
    vector<vector<string>>& temp = m_board;
    m_board = m_old_board;
    m_old_board = temp;
}

void Game::_destroy_game(){
	// Destroys board and frees all threads and resources 
	// Not implemented in the Game's destructor for testing purposes. 
	// Testing of your implementation will presume all threads are joined here
    delete &m_board;
}

/*--------------------------------------------------------------------------------

--------------------------------------------------------------------------------*/
inline void Game::print_board(const char* header) {

	if(print_on){

		// Clear the screen, to create a running animation 
		if(interactive_on)
			system("clear");

		// Print small header if needed
		if (header != NULL) {
		    int field_width = m_board[0].size();
        int field_height  = m_board.size();

        cout << "<------------" << header << "------------>" << endl;

        cout << u8"╔" << string(u8"═") * field_width << u8"╗" << endl;
        for (uint i = 0; i < field_height; ++i) {
            cout << u8"║";
            for (uint j = 0; j < field_width; ++j) {
                if (m_board[i][j] > 0)
                    cout << colors[m_board[i][j] % 7] << u8"█" << RESET;
                else
                    cout << u8"░";
            }
            cout << u8"║" << endl;
        }
        cout << u8"╚" << string(u8"═") * field_width << u8"╝" << endl;
    }

		// Display for GEN_SLEEP_USEC micro-seconds on screen
		if(interactive_on)
			usleep(GEN_SLEEP_USEC);
	}

}


/* Function sketch to use for printing the board. You will need to decide its placement and how exactly 
	to bring in the field's parameters.


*/



