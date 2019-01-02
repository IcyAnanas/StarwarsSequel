#ifndef _IMPERIALFLEET_H_
#define _IMPERIALFLEET_H_

#include <cassert>

template <typename ShieldPoints, typename AttackPower>
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

template <typename ShieldPoints, typename AttackPower>
class DeathStar : public ImperialStarship<ShieldPoints, AttackPower> {
public:
    DeathStar(ShieldPoints shield_points, AttackPower attack_power);
};

template <typename ShieldPoints, typename AttackPower>
class ImperialDestroyer : public ImperialStarship<ShieldPoints, AttackPower> {
public:
    ImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power);
};

template <typename ShieldPoints, typename AttackPower>
class TIEFighter : public ImperialStarship<ShieldPoints, AttackPower> {
    TIEFighter(ShieldPoints shield_points, AttackPower attack_power);
};

template <typename ShieldPoints, typename AttackPower>
class Squadron {

public:
    ShieldPoints getShield() const;
    AttackPower getAttackPower() const;
    void takeDamage(AttackPower damage);
};



// ImperialStarship
template <typename ShieldPoints, typename AttackPower>
ImperialStarship<ShieldPoints, AttackPower>::ImperialStarship(ShieldPoints shield_points, AttackPower attack_power) :
    shield_points(shield_points), attack_power(attack_power) {}

template <typename ShieldPoints, typename AttackPower>
ShieldPoints ImperialStarship<ShieldPoints, AttackPower>::getShield() const {
    return shield_points;
}

template <typename ShieldPoints, typename AttackPower>
AttackPower ImperialStarship<ShieldPoints, AttackPower>::getAttackPower() const {
    return attack_power;
}

template <typename ShieldPoints, typename AttackPower>
void ImperialStarship<ShieldPoints, AttackPower>::takeDamage(AttackPower damage) {
    if(shield_points <= damage) {
        shield_points = ShieldPoints{0};
    }
    else {
        shield_points -= damage;
    }
}

template <typename ShieldPoints, typename AttackPower>
bool ImperialStarship<ShieldPoints, AttackPower>::isAlive() const {
    return shield_points > 0;
}

// DeathStar
template <typename ShieldPoints, typename AttackPower>
DeathStar<ShieldPoints, AttackPower>::DeathStar(ShieldPoints shield_points, AttackPower attack_power) :
    ImperialStarship<ShieldPoints, AttackPower>(shield_points, attack_power) {}

// ImperialDestroyer
template <typename ShieldPoints, typename AttackPower>
ImperialDestroyer<ShieldPoints, AttackPower>::ImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power) :
    ImperialStarship<ShieldPoints, AttackPower>(shield_points, attack_power) {}

// TIEFIGHTER
template <typename ShieldPoints, typename AttackPower>
TIEFighter<ShieldPoints, AttackPower>::TIEFighter(ShieldPoints shield_points, AttackPower attack_power) :
    ImperialStarship<ShieldPoints, AttackPower>(shield_points, attack_power) {}


#endif //_IMPERIALFLEET_H_
