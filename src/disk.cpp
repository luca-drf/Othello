#include "disk.h"
#include "color.h"
#include <stdexcept>

using std::logic_error;


Disk::Disk()
    :_color(Color::NONE){}

Disk::Disk(Color color)
    :_color(color){}

Color Disk::get_color() {
    return _color;
}

bool Disk::operator==(const Disk& other) const {
    return _color == other._color;
}

bool Disk::operator!=(const Disk& other) const {
    return _color != other._color;
}

void Disk::set_color(Color color) {
    _color = color;
}

void Disk::flip() {
    if (_color == Color::DARK) {
        _color = Color::LIGHT;
    }
    else if (_color == Color::LIGHT) {
        _color = Color::DARK;
    }
    else {
        throw logic_error("Cannot flip a NONE Disk");
    }
}

