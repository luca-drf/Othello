#include "game.h"
#include "disk.h"
#include "color.h"
#include "coordinates.h"


void Game::board_set_up() {
    board.set_dim(8);
    board.place_element(Disk(Color::LIGHT), coord(3, 3));
    board.place_element(Disk(Color::LIGHT), coord(4, 4));
    board.place_element(Disk(Color::DARK), coord(4, 3));
    board.place_element(Disk(Color::DARK), coord(3, 4));
}


void print() {
    
}

