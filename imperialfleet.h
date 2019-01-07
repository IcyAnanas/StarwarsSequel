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

class SingleImperialShip : public ImperialStarship {
public:
    SingleImperialShip(ShieldPoints shield_points, AttackPower attack_power);
};

class DeathStar : public SingleImperialShip {
public:
    DeathStar(ShieldPoints shield_points, AttackPower attack_power);
};

std::shared_ptr<ImperialStarship> createDeathStar(ShieldPoints shield_points, AttackPower attack_power);

class ImperialDestroyer : public SingleImperialShip {
public:
    ImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power);
};

std::shared_ptr<ImperialStarship> createImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power);

class TIEFighter : public SingleImperialShip {
public:
    TIEFighter(ShieldPoints shield_points, AttackPower attack_power);
};

std::shared_ptr<ImperialStarship> createTIEFighter(ShieldPoints shield_points, AttackPower attack_power);

class Squadron : public ImperialStarship {
    //todo - reference or not?
    const std::vector<std::shared_ptr<SingleImperialShip>> ships;
    int alive = 0;

public:
    Squadron(const std::vector<std::shared_ptr<SingleImperialShip>>& ships);
    //Squadron(const std::initializer_list<ImperialStarship>& ships);

    const int& numberOfAliveShips() const;
    void takeDamage(AttackPower damage) override;
};

std::shared_ptr<ImperialStarship> createSquadron(const std::vector<std::shared_ptr<SingleImperialShip>>& ships);

//Squadron* createSquadron(const std::initializer_list<ImperialStarship*>& ships);

#endif //_IMPERIALFLEET_H_
