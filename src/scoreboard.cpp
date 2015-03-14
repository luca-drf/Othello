#include "scoreboard.h"

Scoreboard::Scoreboard()
    :_p1(0), _p2(0) {}

void Scoreboard::update_p1(int score) {
    _p1 = score;
}

void Scoreboard::increment_p1() {
    _p1++;
}

void Scoreboard::decrement_p1() {
    _p1--;
}

int Scoreboard::p1() {
    return _p1;
}

void Scoreboard::update_p2(int score) {
    _p2 = score;
}

void Scoreboard::increment_p2() {
    _p2++;
}

void Scoreboard::decrement_p2() {
    _p2--;
}

int Scoreboard::p2() {
    return _p2;
}


