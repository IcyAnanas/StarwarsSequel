#include "imperialfleet.h"

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

// DeathStar
DeathStar::DeathStar(ShieldPoints shield_points, AttackPower attack_power) :
        ImperialStarship(shield_points, attack_power) {}

DeathStar createDeathStar(ShieldPoints shield_points, AttackPower attack_power) {
    return DeathStar{shield_points, attack_power};
}


// ImperialDestroyer
ImperialDestroyer::ImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power) :
        ImperialStarship(shield_points, attack_power) {}

ImperialDestroyer createImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power) {
    return ImperialDestroyer{shield_points, attack_power};
}

// TIEFighter
TIEFighter::TIEFighter(ShieldPoints shield_points, AttackPower attack_power) :
        ImperialStarship(shield_points, attack_power) {}

TIEFighter createTIEFighter(ShieldPoints shield_points, AttackPower attack_power) {
    return TIEFighter{shield_points, attack_power};
}

// Squadron
// todo - brute or smart? (keeping alive&dead in 2 separates structures === smart)
Squadron::Squadron(const std::vector<ImperialStarship>& ships) : ships(ships) {
    for (const auto& ship : ships) {
        if(ship.isAlive()) {
            ++alive;
            total_shield += ship.getShield();
            total_attack_power += ship.getAttackPower();
        }
    }
}

// todo
// wouldn't it be better if we implemented a ctor for vector&& and use move then?
// because the creation of a new vector seems like using one too many vectors...
Squadron::Squadron(const std::initializer_list<ImperialStarship>& ships) :
    Squadron(std::vector<ImperialStarship>(ships)) {}

ShieldPoints Squadron::getShield() const {
    return total_shield;
}

AttackPower Squadron::getAttackPower() const {
    return total_attack_power;
}

void Squadron::takeDamage(AttackPower damage) {}

// clang suggested to move it instead
Squadron createSquadron(const std::vector<ImperialStarship>& ships) {
    return Squadron(ships);
}

Squadron createSquadron(const std::initializer_list<ImperialStarship>& ships) {
    return Squadron(ships);
}

