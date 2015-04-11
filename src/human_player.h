#ifndef HUMAN_PLAYER_H
#define HUMAN_PLAYER_H

#include <string>
#include "game.h"
#include "coordinates.h"
#include "color.h"

using std::string;


class HumanPlayer: public Player {
    public:
        HumanPlayer();
        virtual string get_name();
        virtual void set_name(string name);
        virtual Game* get_game();
        virtual void set_game(Game* game);
        virtual coord move();
        virtual Color get_color();
        virtual void set_color(Color color);

        coord _compute_coords(string input);
        void _print_help();

    protected:
        string _name;
        Game* _game;
        Color _color;

};

#endif
