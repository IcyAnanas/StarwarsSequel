#include "rebelfleet.h"
#include <cassert>

// RebelStarship
RebelStarship::RebelStarship(
        ShieldPoints shield_points, Speed speed) : speed(speed), shield_points(shield_points) {
}

ShieldPoints RebelStarship::getShield() const {return shield_points;}

Speed RebelStarship::getSpeed() const {return speed;}

void RebelStarship::takeDamage(AttackPower damage) {
    if(shield_points <= damage) {
        shield_points = ShieldPoints{0};
    }
    else {
        shield_points -= damage;
    }
}

bool RebelStarship::isAlive() const {
    return shield_points > 0;
}

// Attacker
Attacker::Attacker(
        ShieldPoints shield_points, Speed speed, AttackPower attack_power) :
        RebelStarship(shield_points, speed),
        attack_power(attack_power) {}

AttackPower Attacker::getAttackPower() const {return attack_power;}


// Explorer
Explorer::Explorer(ShieldPoints shield_points, Speed speed) :
        RebelStarship(shield_points, speed) {
    checkSpeed();
}

Explorer createExplorer(ShieldPoints shield_points, Speed speed) {
    return Explorer{shield_points, speed};
}

// StarCruiser
StarCruiser::StarCruiser(
        ShieldPoints shield_points, Speed speed, AttackPower attack_power) :
        Attacker(shield_points, speed, attack_power) {
    checkSpeed();
}

StarCruiser createStarCruiser(ShieldPoints shield_points, Speed speed, AttackPower attack_power) {
    return StarCruiser{shield_points, speed, attack_power};
}

// XWing
XWing::XWing(ShieldPoints shield_points, Speed speed, AttackPower attack_power) :
        Attacker::Attacker(shield_points, speed, attack_power) {
    checkSpeed();
}

XWing createXWing(ShieldPoints shield_points, Speed speed, AttackPower attack_power) {
    return XWing{shield_points, speed, attack_power};
}

