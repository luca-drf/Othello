#include "board.h"
#include "coordinates.h"
#include <vector>
#include <stdexcept>

using std::vector;
using std::out_of_range;


template <class T>
void Board<T>::set_dim(size_t value) {
    _dim = value;
    _cells.resize(_dim, vector< T >(_dim));
}

template <class T>
size_t Board<T>::get_dim() {
    return _dim;
}

template <class T>
size_t Board<T>::size() {
    return _dim * _dim;
}

template <class T>
T& Board<T>::at(coord coords) {
    return _cells.at(coords.x).at(coords.y);   
}

template <class T>
void Board<T>::place_element(T element, coord coords) {
    _cells.at(coords.x).at(coords.y) = element;   
}

template <class T>
typename Board<T>::iterator Board<T>::begin() {
    return iterator(this, coord(0, 0));
}

template <class T>
typename Board<T>::iterator Board<T>::end() {
    return iterator(this, coord(_dim, _dim - 1));
}

template <class T>
Board<T>::iterator::iterator(Board* board, coord coords)
    :_board(board), _coords(coords.x, coords.y) {}

template <class T>
typename Board<T>::iterator& Board<T>::iterator::operator++() {
    if (_coords.x >= _board->get_dim() - 1) {
        _coords.x = 0;
        _coords.y++;
    }
    else {
        _coords.x++;
    }
    if (_coords.y >= _board->get_dim()) {
        throw out_of_range("Incrementing iterator out of range");
    }
    return *this;
}

template <class T>
typename Board<T>::iterator& Board<T>::iterator::operator--() {
    if (_coords.x <= 0) {
        _coords.x = _board->get_dim() - 1;
        _coords.y--;
    }
    else {
        _coords.x--;
    }
    if (_coords.y < 0) {
        throw out_of_range("Decrementing iterator out of range");
    }
    return *this;
}

template <class T>
T& Board<T>::iterator::operator*() {
    return _board->at(_coords);
}

template <class T>
bool Board<T>::iterator::operator==(const iterator& other) {
    return (other._board == _board && other._coords == _coords);
}

template <class T>
bool Board<T>::iterator::operator!=(const iterator& other) {
    return (other._board != _board || other._coords != _coords);
}
