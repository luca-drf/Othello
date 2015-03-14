#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "scoreboard.h"
#include "color.h"
#include "player.h"
#include "disk.h"
#include "coordinates.h"
#include <list>
#include <vector>
#include <string>

using std::list;
using std::vector;
using std::string;


class Game {
    public:
    Board<Disk> board;
    Scoreboard score;
    Player* player_d;
    Player* player_l;
    
    void board_set_up();
    void play();
    bool game_over();
    void register_player(Player* player, Color color);
    void print();

    protected:
    list< coord > _available;
    void _print_hline(size_t dim);
    void _print_board(vector<string> x_label, vector<string> y_label);    
        
};

#endif
