#ifndef _IMPERIALFLEET_H_
#define _IMPERIALFLEET_H_

#include <cassert>
#include <vector>

using ShieldPoints = int;
using AttackPower = int;

class ImperialStarship {
    ShieldPoints shield_points;
    AttackPower attack_power;

public:
    ImperialStarship(ShieldPoints shield_points, AttackPower attack_power);

    ShieldPoints getShield() const;
    AttackPower getAttackPower() const;

    void takeDamage(AttackPower damage);
    bool isAlive() const;

    virtual ~ImperialStarship() = default;
};

class DeathStar : public ImperialStarship {
public:
    DeathStar(ShieldPoints shield_points, AttackPower attack_power);
};

DeathStar createDeathStar(ShieldPoints shield_points, AttackPower attack_power);

class ImperialDestroyer : public ImperialStarship {
public:
    ImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power);
};

ImperialDestroyer createImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power);

class TIEFighter : public ImperialStarship {
public:
    TIEFighter(ShieldPoints shield_points, AttackPower attack_power);
};

TIEFighter createTIEFighter(ShieldPoints shield_points, AttackPower attack_power);

class Squadron {
    std::vector<ImperialStarship> ships;
    int alive = 0;
    ShieldPoints total_shield = ShieldPoints{0};
    AttackPower total_attack_power = AttackPower{0};

public:
    explicit Squadron(const std::vector<ImperialStarship>& ships); // won't the compiler automatically cast initializer_list on vector?
    Squadron(const std::initializer_list<ImperialStarship>& ships);

    ShieldPoints getShield() const;
    AttackPower getAttackPower() const;
    void takeDamage(AttackPower damage);
};

Squadron createSquadron(const std::vector<ImperialStarship>& ships);

Squadron createSquadron(const std::initializer_list<ImperialStarship>& ships);

#endif //_IMPERIALFLEET_H_
