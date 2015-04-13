#include "human_player.h"
#include "color.h"
#include "game.h"
#include "coordinates.h"
#include <string>
#include <iostream>
#include <regex>
#include <stdexcept>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::regex;
using std::smatch;
using std::invalid_argument;


HumanPlayer::HumanPlayer()
    :_name(""), _game(nullptr), _color(Color::NONE) {}

coord HumanPlayer::move() {
    string input;
    smatch sm;
    regex input_coords("(\\d+)([a-zA-Z]+)|([a-zA-Z]+)(\\d+)");    
    regex input_quit("q");
    regex input_help("h");
    regex input_confirm("[yY]");
    while (true){
        cout << "Enter move: ";
        cin >> input;
        if (regex_match(input, sm, input_coords)) {
            string y_label(string(sm[0]) + string(sm[3]));
            string x_label(string(sm[1]) + string(sm[2]));
            try {
                return _compute_coords(x_label, y_label);
            }
            catch (invalid_argument& e) {
                cout << "Invalid input " << e.what() << endl;
            }
        }
        else if (regex_match(input, input_help)) {
            _print_help();
        }
        else if (regex_match(input, input_quit)) {
            cout << "Are you sure you want to quit? [y/n]" << endl;
            if (regex_match(input, input_confirm)) {
                exit(0);
            }
            else {
                continue;
            }
        }
        else {
            cout << "Invalid input. Enter 'h' for help." << endl;
        }
    }
}

coord HumanPlayer::_compute_coords(string x_label, string y_label) {
    int count = 0;
    int x = -1;
    int y = -1;
    for (auto l : _game->x_labels) {
        if (x_label == l) {
            x = count;
            break;
        }
        else {
            count++;
        }
    }
    count = 0;
    for (auto l : _game->y_labels) {
        if (y_label == l) {
            y = count;
            break;
        }
        else {
            count++;
        }
    }
    if (x == -1 || y == -1) {
        throw invalid_argument("x_label: " + x_label + "y_label: " + y_label);
    }
    else {
        return coord(x, y);
    }
}

void HumanPlayer::_print_help() {
    cout << "Enter coordinates or q for quit" << endl;
}

string HumanPlayer::get_name() {
    return _name;
}

void HumanPlayer::set_name(string name) {
    _name = name;
}

Game* HumanPlayer::get_game() {
    return _game;
}

void HumanPlayer::set_game(Game* game) {
    _game = game;
}

Color HumanPlayer::get_color() {
    return _color;
}

void HumanPlayer::set_color(Color color) {
    _color = color;
}
