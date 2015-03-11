#ifndef COORDINATES_H
#define COORDINATES_H

struct coord {
    int x;
    int y;

    coord(int x, int y):
        x(x), y(y){}
    bool operator==(const coord& other) const {
        return (other.x == x && other.y == y);
    }
    bool operator!=(const coord& other) const {
    return !(other == *this);
    }
};

#endif
