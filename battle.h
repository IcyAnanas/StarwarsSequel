#ifndef _SPACEBATTLE_H_
#define _SPACEBATTLE_H_

#include <cstring>
#include "imperialfleet.h"
#include "rebelfleet.h"

using Time = int;

class TimingStrategy {
public:
    TimingStrategy() = default;
    virtual ~TimingStrategy() = default;

    virtual bool shouldAttack(Time t) = 0;
    virtual void stepTime(Time timeStep) = 0;
};

class Timing235 : public TimingStrategy {
protected:
    Time t0;
    Time t1;
    Time currentTime;
public:
    Timing235(Time t0, Time t1);

    bool shouldAttack(Time t) override;
    void stepTime(Time timeStep) override;
};

class SpaceBattle {
protected:
    std::vector<std::shared_ptr<ImperialStarship>> imperialShips;
    std::vector<std::shared_ptr<RebelStarship>> rebelShips;

    std::unique_ptr<TimingStrategy> battleTiming;

    virtual void executeAttack(ImperialStarship& imp, RebelStarship& reb);

public:
    SpaceBattle() = default;
    virtual ~SpaceBattle() = default;

    std::size_t countImperialFleet() const;
    std::size_t countRebelFleet() const;
    void tick(Time timeStep);

    class Builder {
    private:
        std::vector<std::shared_ptr<ImperialStarship>> imperialShips;
        std::vector<std::shared_ptr<RebelStarship>> rebelShips;
        Time t0;
        Time t1;
    public:
        Builder& ship(std::shared_ptr<ImperialStarship> ship);
        Builder& ship(std::shared_ptr<RebelStarship> ship);
        Builder& startTime(Time time);
        Builder& maxTime(Time time);
        SpaceBattle& build();
    };
};

#endif //_SPACEBATTLE_H_
