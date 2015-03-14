#include "game.h"
#include "disk.h"
#include "color.h"
#include "coordinates.h"
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::invalid_argument;


void Game::board_set_up() {
    board.set_dim(8);
    board.place_element(Disk(Color::LIGHT), coord(3, 3));
    board.place_element(Disk(Color::LIGHT), coord(4, 4));
    board.place_element(Disk(Color::DARK), coord(4, 3));
    board.place_element(Disk(Color::DARK), coord(3, 4));
}


void Game::print() {
    vector<string> x_label = {"a", "b", "c", "d", "e", "f", "g", "h"};
    vector<string> y_label = {"1", "2", "3", "4", "5", "6", "7", "8"};

    _print_board(x_label, y_label);
}

void Game::_print_hline(size_t dim) {
    for (unsigned int i = 0; i < dim; i++) {
        cout << " ---";
    }
    cout << endl;
}

void Game::_print_board(vector<string> x_label, vector<string> y_label) {
    short col = 0, row = 0;
    bool first_line = true;
    auto dim = board.get_dim();

    for (short i = 0; i < dim; i++) {
        cout << "  " << x_label.at(i) << " ";
    }
    
    for (auto dit = board.begin(); dit != board.end(); dit++, col++) {
        if (col % dim == 0) {
            if (!first_line) {
                cout << "| " << y_label.at(row);
                row++;
            }
            else {
                first_line = false;
            }
            cout << endl;
            _print_hline(dim);
        }
        cout << "| " << (*dit).get_color() << " ";
    }
    cout << "| " << y_label.at(row) << endl;
    _print_hline(dim);
}

void Game::register_player(Player* player, Color color) {
    if (color == Color::LIGHT) {
        player_l = player;
    }
    else if (color == Color::DARK) {
        player_d = player;        
    }
    else {
        throw invalid_argument("Invalid color");
    }
}

