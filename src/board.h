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
        T& operator*();
        bool operator==(const iterator& other);
        bool operator!=(const iterator& other);

        protected:
        Board* _board;
        coord _coords;
    };

    iterator begin();
    iterator end();


    protected:
    vector< vector< T > > _cells;
    size_t _dim;
};

#include "board.cpp"


#endif
