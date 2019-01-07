#include "helper.h"
#include <iostream>

// Starship
ShieldPoints Starship::getShield() const {
    return shield_points;
}

Starship::Starship(ShieldPoints shield_points) : shield_points(shield_points) {}

bool Starship::isAlive() const {
    return getShield() > ShieldPoints{0};
}

void Starship::takeDamage(AttackPower damage) {
    if(shield_points <= damage) {
        shield_points = ShieldPoints{0};
    }
    else {
        shield_points -= damage;
    }
}

// Attacker

Attacker::Attacker(ShieldPoints shield_points, AttackPower attack_power) :
    Starship(shield_points), attack_power(attack_power) {
}

AttackPower Attacker::getAttackPower() const {
    return attack_power;
}
