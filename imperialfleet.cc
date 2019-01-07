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

const int& ImperialStarship::numberOfAliveShips() const {
    return isAlive();
}

// DeathStar
DeathStar::DeathStar(ShieldPoints shield_points, AttackPower attack_power) :
        ImperialStarship(shield_points, attack_power) {}

DeathStar* createDeathStar(ShieldPoints shield_points, AttackPower attack_power) {
    return new DeathStar{shield_points, attack_power};
}


// ImperialDestroyer
ImperialDestroyer::ImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power) :
        ImperialStarship(shield_points, attack_power) {}

ImperialDestroyer* createImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power) {
    return new ImperialDestroyer{shield_points, attack_power};
}

// TIEFighter
TIEFighter::TIEFighter(ShieldPoints shield_points, AttackPower attack_power) :
        ImperialStarship(shield_points, attack_power) {}

TIEFighter* createTIEFighter(ShieldPoints shield_points, AttackPower attack_power) {
    return new TIEFighter{shield_points, attack_power};
}

// Squadron
// todo - brute or smart? (keeping alive&dead in 2 separates structures === smart)
Squadron::Squadron(const std::vector<ImperialStarship*>& ships) : ImperialStarship(ShieldPoints{0}, AttackPower{0}), ships(ships) {
    for (const auto ship : ships) {
        if(ship->isAlive()) {
            ++alive;
            shield_points += ship->getShield();
            attack_power += ship->getAttackPower();
        }
    }
}

// todo
// wouldn't it be better if we implemented a ctor for vector&& and use move then?
// because the creation of a new vector seems like using one too many vectors...
// or even to totally erase destroyed ships from Squadron
//Squadron::Squadron(const std::initializer_list<ImperialStarship*>& ships) :
//    Squadron(std::vector<ImperialStarship*>(ships)) {}

void Squadron::takeDamage(AttackPower damage) {
    for(auto ship : ships) {
        if(ship->isAlive()) {
            if(ship->getShield() <= static_cast<ShieldPoints>(damage)) {
                shield_points -= ship->getShield();
                attack_power -= ship->getAttackPower();
                --alive;
            }
            else {
                shield_points -= damage;
            }
            ship->takeDamage(damage);
        }
    }
}

const int& Squadron::numberOfAliveShips() const {
    return alive;
}

// clang suggested to move it instead - we could write a moving function as well, but do we really need to?
Squadron* createSquadron(const std::vector<ImperialStarship*>& ships) {
    return new Squadron(ships);
}

Squadron* createSquadron(const std::initializer_list<ImperialStarship*>& ships) {
    return new Squadron(ships);
}
