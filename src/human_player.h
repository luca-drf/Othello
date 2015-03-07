#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include <string>
#include "game.h"
#include "coordinates.h"

using std::string;


class HumanPlayer: public Player {
    public:
        virtual string get_name();
        virtual void set_name(string name);
        virtual Game* get_game();
        virtual void set_game(Game* game);
        virtual coord move();

    protected:
        string _name;
        Game* _game;

};

#endif
