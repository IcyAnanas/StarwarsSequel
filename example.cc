#include "rebelfleet.h"
#include <iostream>

using namespace std;

int main () {

    RebelStarship *exp = new Explorer(3, 299796);
    RebelStarship *sc = new StarCruiser(200, 99999, 3);

    cout << sc->getSpeed() << endl;
    cout << sc->getShield() << endl;

    return 0;
}
