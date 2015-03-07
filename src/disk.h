#ifndef DISK_H
#define DISK_H

#include "color.h"


class Disk {
    public: 
        Disk();
        Disk(Color color);
        Color get_color();
        void set_color(Color color);
        void flip();

    protected:
        Color _color;        
};

#endif
