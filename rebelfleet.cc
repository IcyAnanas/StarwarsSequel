#include "rebelfleet.h"
#include <cassert>
#include<iostream>

// LimitedSpeedVehicle

void LimitedSpeedVehicle::checkSpeed(Speed min, Speed max) {
     assert(speed >= static_cast<Speed>(min) && speed <= static_cast<Speed>(max));
}

LimitedSpeedVehicle::LimitedSpeedVehicle(Speed min, Speed max, Speed speed) : speed(speed) {
    checkSpeed(min, max);
}

Speed LimitedSpeedVehicle::getSpeed() const {
    return speed;
}

// RebelStarship
RebelStarship::RebelStarship(ShieldPoints shield_points, Speed min, Speed max, Speed speed) :
        Starship(shield_points), LimitedSpeedVehicle(min, max, speed) {}

// Explorer
// todo - 'class Explorer must explicitly initialize Starship which has no default ctor'
Explorer::Explorer(ShieldPoints shield_points, Speed speed) :
        Starship(shield_points),
        RebelStarship(shield_points, 299796, 2997960, speed) {}

std::shared_ptr<RebelStarship> createExplorer(ShieldPoints shield_points, Speed speed) {
    return std::make_shared<Explorer>(Explorer(shield_points, speed));
}

// StarCruiser
// todo - same as above with 'Attacker'
StarCruiser::StarCruiser(ShieldPoints shield_points, Speed speed, AttackPower attack_power) :
    Starship(shield_points),
    Attacker(shield_points, attack_power),
    RebelStarship(shield_points, 99999, 299795, speed) {}

std::shared_ptr<RebelStarship> createStarCruiser(ShieldPoints shield_points, Speed speed, AttackPower attack_power) {
    return std::make_shared<StarCruiser>(StarCruiser(shield_points, speed, attack_power));
}

// XWing
XWing::XWing(ShieldPoints shield_points, Speed speed, AttackPower attack_power) :
    Starship(shield_points),
    Attacker(shield_points, attack_power),
    RebelStarship(shield_points, 299796, 2997960, speed) {}

std::shared_ptr<RebelStarship> createXWing(ShieldPoints shield_points, Speed speed, AttackPower attack_power) {
    return std::make_shared<XWing>(XWing(shield_points, speed, attack_power));
}
