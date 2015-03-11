#ifndef BOARD_H
#define BOARD_H

#include "coordinates.h"
#include <vector>

using std::vector;


template <class T>
class Board {
    public: 
    void set_dim(size_t value);
    size_t get_dim();
    size_t size();
    T& at(coord coords);
    void place_element(T element, coord coords);

    class iterator {
        public:
        iterator(Board* board, coord coords);
        iterator& operator++();
        iterator& operator--();
        iterator operator++(int);
        iterator operator--(int);

        T& operator*();
        bool operator==(const iterator& other) const;
        bool operator!=(const iterator& other) const;

        protected:
        Board* _board;
        coord _coords;
    };

    iterator begin();
    iterator end();


    protected:
    typedef vector< vector< T > > out_container;
    typedef vector< T > in_container;

    out_container _cells;
    size_t _dim;
};

#include "board.cpp"


#endif
