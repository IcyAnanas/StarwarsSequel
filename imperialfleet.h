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

class DeathStar : public ImperialStarship {
public:
    DeathStar(ShieldPoints shield_points, AttackPower attack_power);
};

std::shared_ptr<ImperialStarship> createDeathStar(ShieldPoints shield_points, AttackPower attack_power);

class ImperialDestroyer : public ImperialStarship {
public:
    ImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power);
};

std::shared_ptr<ImperialStarship> createImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power);

class TIEFighter : public ImperialStarship {
public:
    TIEFighter(ShieldPoints shield_points, AttackPower attack_power);
};

std::shared_ptr<ImperialStarship> createTIEFighter(ShieldPoints shield_points, AttackPower attack_power);

class Squadron : public ImperialStarship {
    //todo - reference or not?
    const std::vector<ImperialStarship*> ships;
    int alive = 0;

public:
    Squadron(const std::vector<ImperialStarship*>& ships);
    //Squadron(const std::initializer_list<ImperialStarship>& ships);

    const int& numberOfAliveShips() const;
    void takeDamage(AttackPower damage) override;
};

std::shared_ptr<ImperialStarship> createSquadron(const std::vector<ImperialStarship*>& ships);

//Squadron* createSquadron(const std::initializer_list<ImperialStarship*>& ships);

#endif //_IMPERIALFLEET_H_
