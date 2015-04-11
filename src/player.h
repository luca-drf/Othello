#ifndef PLAYER_H
#define PLAYER_H

#include "coordinates.h"
#include "game.h"
#include "color.h"
#include <string>

using std::string;

class Game;


class Player {
    public:
        virtual string get_name() = 0;
        virtual void set_name(string name) = 0;
        virtual Game* get_game() = 0;
        virtual void set_game(Game* game) = 0;
        virtual coord move() = 0;
        virtual Color get_color() = 0;
        virtual void set_color(Color color) = 0;
};

#endif
