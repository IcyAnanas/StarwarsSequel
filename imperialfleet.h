#ifndef _IMPERIALFLEET_H_
#define _IMPERIALFLEET_H_

#include <cassert>

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
};

class DeathStar : public ImperialStarship {
public:
    DeathStar(ShieldPoints shield_points, AttackPower attack_power);
};

class ImperialDestroyer : public ImperialStarship {
public:
    ImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power);
};

class TIEFighter : public ImperialStarship {
    TIEFighter(ShieldPoints shield_points, AttackPower attack_power);
};

class Squadron {

public:
    ShieldPoints getShield() const;
    AttackPower getAttackPower() const;
    void takeDamage(AttackPower damage);
};



// ImperialStarship
ImperialStarship::ImperialStarship(ShieldPoints shield_points, AttackPower attack_power) :
    shield_points(shield_points), attack_power(attack_power) {}

ShieldPoints ImperialStarship::getShield() const {
    return shield_points;
}

AttackPower ImperialStarship::getAttackPower() const {
    return attack_power;
}

void ImperialStarship::takeDamage(AttackPower damage) {
    if(shield_points <= damage) {
        shield_points = ShieldPoints{0};
    }
    else {
        shield_points -= damage;
    }
}

bool ImperialStarship::isAlive() const {
    return shield_points > 0;
}


#endif //_IMPERIALFLEET_H_
