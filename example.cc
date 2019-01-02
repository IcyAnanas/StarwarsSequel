#include "rebelfleet.h"
#include <iostream>

using namespace std;

int main () {

    RebelStarship<int, long, unsigned int> exp = Explorer<int, long, unsigned int>(200, 3);
    RebelStarship<string, int, short int> sc = StarCruiser<string, int, short int>("200", 99999, 3);

    cout << sc.getSpeed() << endl;
    cout << sc.getShield() << endl;

    return 0;
}
