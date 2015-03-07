#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "scoreboard.h"
#include "color.h"
#include "player.h"
#include "disk.h"
#include "coordinates.h"
#include <list>

using std::list;


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
        
};

#endif
