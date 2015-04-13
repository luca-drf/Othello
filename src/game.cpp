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


void Game::set_up() {
    _board_set_up();
    scoreboard.update_p1(2);
    scoreboard.update_p2(2);
}

void Game::_board_set_up() {
    x_labels = {"a", "b", "c", "d", "e", "f", "g", "h"};
    y_labels = {"1", "2", "3", "4", "5", "6", "7", "8"};
    board.set_dim(8);
    board.place_element(Disk(Color::LIGHT), coord(3, 3));
    board.place_element(Disk(Color::LIGHT), coord(4, 4));
    board.place_element(Disk(Color::DARK), coord(4, 3));
    board.place_element(Disk(Color::DARK), coord(3, 4));
}

void Game::register_player(Player* player, Color color) {
    switch(color) {
        case Color::LIGHT:
            player_l = player;
            player->set_color(Color::LIGHT);
            player->set_game(this);
        case Color::DARK:
            player_d = player;
            player->set_color(Color::DARK);
            player->set_game(this);            
        case Color::NONE:
            throw invalid_argument("Invalid color");
    }
}

void Game::play() {
    while(!game_over()) {
        move(player_l);
        print();
        move(player_d);
        print();
    }
    cout << "Game Over." << endl;
}

void Game::move(Player* player) {
    coord coords = player->move();
    Color p_color = player->get_color();
    auto d_flipped = _update_board(coords, p_color);
    _update_score(d_flipped, p_color);
}

void Game::_update_score(int d_flipped, Color color) {
    auto score_p1 = scoreboard.p1();
    auto score_p2 = scoreboard.p2();
    switch(color) {
        case Color::LIGHT:
            scoreboard.update_p1(score_p1 + d_flipped + 1);
            scoreboard.update_p2(score_p2 - d_flipped);
        case Color::DARK:
            scoreboard.update_p2(score_p2 + d_flipped + 1);
            scoreboard.update_p1(score_p1 - d_flipped);
        case Color::NONE:
            throw invalid_argument("Invalid color");
    }
}

void Game::print() {
    _print_board();
}

void Game::_print_hline(size_t dim) {
    for (unsigned int i = 0; i < dim; i++) {
        cout << " ---";
    }
    cout << endl;
}

void Game::_print_board() {
    short col = 0, row = 0;
    bool first_line = true;
    auto dim = board.get_dim();

    for (size_t i = 0; i < dim; i++) {
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
