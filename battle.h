#ifndef _SPACEBATTLE_H_
#define _SPACEBATTLE_H_

#include <cstring>

using T = int;

class SpaceBattle {
private:
    T t0;
    T t1;

    class Builder {

    };

public:
    SpaceBattle() = default;
    std::size_t countImperialFleet();
    std::size_t countRebelFleet();
    void tick(T timeStep);
};

#endif //_SPACEBATTLE_H_
