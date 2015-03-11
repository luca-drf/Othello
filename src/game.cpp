#include "game.h"
#include "disk.h"
#include "color.h"
#include "coordinates.h"
#include <iostream>

using std::cout;
using std::endl;


void Game::board_set_up() {
    board.set_dim(8);
    board.place_element(Disk(Color::LIGHT), coord(3, 3));
    board.place_element(Disk(Color::LIGHT), coord(4, 4));
    board.place_element(Disk(Color::DARK), coord(4, 3));
    board.place_element(Disk(Color::DARK), coord(3, 4));
}


void Game::print() {
    auto dim = board.get_dim();
    for (unsigned int i = 0; i <= dim; i++) {
        cout << "-----";
    }
    for (auto dit = board.begin(), col = 0; dit != board.end(); dit++, col++) {
        if (col % dim == 0) {
            cout << "|" << endl;
            for (unsigned int i = 0; i <= dim; i++) {
                cout << "-----";
            }
            cout << endl;
        }
        cout << "| " << (*dit).get_color() << " ";
    }
}


// -----
// | 1 |
