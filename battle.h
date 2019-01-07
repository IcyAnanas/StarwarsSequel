#ifndef _SPACEBATTLE_H_
#define _SPACEBATTLE_H_

#include <cstring>
#include "imperialfleet.h"
#include "rebelfleet.h"

using Time = int;
using T = int;

class TimingStrategy {
public:
    virtual bool shouldAttack(Time t) = 0;
};

class Timing235 : public TimingStrategy {
public:
    bool shouldAttack(Time t) override;
};

class SpaceBattle {
protected:
    Time t0;
    Time t1;
    Time currentTime;

    std::vector<ImperialStarship*> imperialShips;
    std::vector<RebelStarship*> rebelShips;

    virtual TimingStrategy& getTimingSTrategy();

    virtual void executeAttack(ImperialStarship* imp, RebelStarship* reb);

public:
//    SpaceBattle() = default;

    std::size_t countImperialFleet() const;
    std::size_t countRebelFleet() const;
    void tick(T timeStep);

    class Builder {
    private:
        std::vector<ImperialStarship*> imperialShips;
        std::vector<RebelStarship*> rebelShips;

        Time t0;
        Time t1;
    public:
        Builder& ship(ImperialStarship* ship);
        Builder& ship(RebelStarship* ship);
        Builder& startTime(Time time);
        Builder& maxTime(Time time);
        SpaceBattle& build();
    };
};

#endif //_SPACEBATTLE_H_
