#include <iostream>
#include "board.h"
#include "coordinates.h"
#include "disk.h"
#include "color.h"

using namespace std;

void print_hline(size_t dim) {
    for (unsigned int i = 0; i < dim; i++) {
        cout << " ---";
    }
    cout << endl;
}

void print(Board<Disk> board) {
    int col = 0;
    bool first_line = true;
    auto dim = board.get_dim();
    
    for (auto dit = board.begin(); dit != board.end(); dit++, col++) {
        if (col % dim == 0) {
            if (!first_line) {
                cout << "|";
            }
            else {
                first_line = false;
            }
            cout << endl;
            print_hline(dim);
        }
        cout << "| " << (*dit).get_color() << " ";
    }
    cout << "|" << endl;
    print_hline(dim);
}



int main() {
    Board<Disk> board;
    board.set_dim(3);

    coord coords(0, 1);
    board.place_element(Disk(Color::LIGHT), coords);
    print(board);

    
    
    
    
    
    
/*     vector< Disk > expected(8, Disk(Color::NONE));
 *     expected.insert(expected.begin() + 3, Disk(Color::LIGHT));
 *     vector< Disk > actual;
 *     for (auto d : board) {
 *         actual.push_back(d);
 *     }
 * 
 *     cout << "Expected:" << endl;
 *     for (auto d : expected) {
 *         cout << d.get_color() << endl;
 *     }
 *     cout << "Actual:" << endl;
 *     for (auto d : actual) {
 *         cout << d.get_color() << endl;
 *     } */


/*     board.place_element(5, coord(1,1));
 * 
 *     for (auto i = --board.end(); i != board.begin(); i--) {
 *         cout << "Val: " << *i << endl;
 *         cout << "X: " << i._coords.x << endl;
 *         cout << "Y: " << i._coords.y << endl;
 * 
 *     } */

    return 0;
}

