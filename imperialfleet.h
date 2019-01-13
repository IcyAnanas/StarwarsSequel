#ifndef _IMPERIALFLEET_H_
#define _IMPERIALFLEET_H_

#include "helper.h"
#include <cassert>
#include <vector>
#include <memory>


class ImperialStarship : public Attacker {
public:
    ImperialStarship(ShieldPoints shield_points, AttackPower attack_power);

    virtual ~ImperialStarship() = default;
};

class SingleImperialStarship : public ImperialStarship, public SingleStarship {
public:
    SingleImperialStarship(ShieldPoints shield_points, AttackPower attack_power);

    virtual ~SingleImperialStarship() = default;
};


class DeathStar : public SingleImperialStarship {
public:
    DeathStar(ShieldPoints shield_points, AttackPower attack_power);
};

std::shared_ptr<ImperialStarship> createDeathStar(ShieldPoints shield_points, AttackPower attack_power);



class ImperialDestroyer : public SingleImperialStarship {
public:
    ImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power);
};

std::shared_ptr<ImperialStarship> createImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power);


class TIEFighter : public SingleImperialStarship {
public:
    TIEFighter(ShieldPoints shield_points, AttackPower attack_power);
};

std::shared_ptr<ImperialStarship> createTIEFighter(ShieldPoints shield_points, AttackPower attack_power);



class Squadron : public ImperialStarship {
    const std::vector<std::shared_ptr<ImperialStarship>> ships;
    int alive = 0;

public:
    Squadron(const std::vector<std::shared_ptr<ImperialStarship>>& ships);
    //Squadron(const std::initializer_list<ImperialStarship>& ships);

    void takeDamage(AttackPower damage) override;
    int countAliveShips() const override;
};

std::shared_ptr<ImperialStarship> createSquadron(const std::vector<std::shared_ptr<ImperialStarship>>& ships);

//Squadron* createSquadron(const std::initializer_list<ImperialStarship*>& ships);

#endif //_IMPERIALFLEET_H_
