#include "human_player.h"
#include "color.h"
#include "game.h"
#include "coordinates.h"
#include <string>
#include <iostream>
#include <regex>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::regex;


HumanPlayer::HumanPlayer()
    :_name(""), _game(nullptr), _color(Color::NONE) {}

coord HumanPlayer::move() {
    string input;
    regex input_coords("\\d+[a-zA-Z]+|[a-zA-Z]+\\d");
    regex input_quit("q");
    regex input_help("h");
    while (true){
        cout << "Enter move: ";
        cin >> input;
        if (regex_match(input, input_coords)) {
            return _compute_coords(input);
        }
        else if (regex_match(input, input_help)) {
            _print_help();
        }
        else if (regex_match(input, input_quit)) {
            exit(0);
        }
        else {
            cout << "Invalid input. Enter 'h' for help." << endl;
        }
    }
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
