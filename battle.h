#ifndef _SPACEBATTLE_H_
#define _SPACEBATTLE_H_

#include <cstring>
#include "rebelfleet.h"
#include "imperialfleet.h"

using T = int;

class SpaceBattle {
    T t0;
    T t1;
    std::vector<ImperialStarship*> imperial_fleet;
    int imperial_alive = 0;
    std::vector<RebelStarship*> rebel_fleet;
    int rebel_alive = 0;

public:
    class Builder {
    public:
        Builder ship(ImperialStarship* ship);
        Builder ship(RebelStarship* ship);
        Builder ship(Squadron* squadron);
        Builder startTime(T time);
        Builder maxTime(T max_time);
        SpaceBattle build();
    };

    SpaceBattle() = default;
    std::size_t countImperialFleet();
    std::size_t countRebelFleet();
    void tick(T timeStep);
};

#endif //_SPACEBATTLE_H_
