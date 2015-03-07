#ifndef COORDINATES_H
#define COORDINATES_H

struct coord {
    unsigned int x;
    unsigned int y;

    coord(unsigned int x, unsigned int y):
        x(x), y(y){}
};

#endif
