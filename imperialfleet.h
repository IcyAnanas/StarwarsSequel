#ifndef _IMPERIALFLEET_H_
#define _IMPERIALFLEET_H_

#include <cassert>
#include <vector>

using ShieldPoints = int;
using AttackPower = int;

class ImperialStarship {
protected:
    ShieldPoints shield_points;
    AttackPower attack_power;

public:
    ImperialStarship(ShieldPoints shield_points, AttackPower attack_power);

    ShieldPoints getShield() const;
    AttackPower getAttackPower() const;

    virtual void takeDamage(AttackPower damage);
    bool isAlive() const;

    virtual ~ImperialStarship() = default;

    virtual const int& numberOfAliveShips() const;
};

class DeathStar : public ImperialStarship {
public:
    DeathStar(ShieldPoints shield_points, AttackPower attack_power);
};

DeathStar* createDeathStar(ShieldPoints shield_points, AttackPower attack_power);

class ImperialDestroyer : public ImperialStarship {
public:
    ImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power);
};

ImperialDestroyer* createImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power);

class TIEFighter : public ImperialStarship {
public:
    TIEFighter(ShieldPoints shield_points, AttackPower attack_power);
};

TIEFighter* createTIEFighter(ShieldPoints shield_points, AttackPower attack_power);

class Squadron : public ImperialStarship{
    //todo - reference or not?
    const std::vector<ImperialStarship*> ships;
    int alive = 0;

public:
    Squadron(const std::vector<ImperialStarship*>& ships);
    //Squadron(const std::initializer_list<ImperialStarship>& ships);

    const int& numberOfAliveShips() const override;
    void takeDamage(AttackPower damage) override;
};

Squadron* createSquadron(const std::vector<ImperialStarship*>& ships);

//Squadron* createSquadron(const std::initializer_list<ImperialStarship*>& ships);

#endif //_IMPERIALFLEET_H_
