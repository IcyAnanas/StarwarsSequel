#include "imperialfleet.h"

// DeathStar
DeathStar::DeathStar(ShieldPoints shield_points, AttackPower attack_power) :
        ImperialStarship(shield_points, attack_power) {}

// ImperialDestroyer
ImperialDestroyer::ImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power) :
        ImperialStarship(shield_points, attack_power) {}

// TIEFIGHTER
TIEFighter::TIEFighter(ShieldPoints shield_points, AttackPower attack_power) :
        ImperialStarship(shield_points, attack_power) {}

