#include "imperialfleet.h"

// ImperialStarship
ImperialStarship::ImperialStarship(ShieldPoints shield_points, AttackPower attack_power) :
    Starship(shield_points),
    Attacker(shield_points, attack_power) {
    takeDamage(100);
}

// DeathStar
DeathStar::DeathStar(ShieldPoints shield_points, AttackPower attack_power) :
    Starship(shield_points),
    ImperialStarship(shield_points, attack_power) {}

std::shared_ptr<ImperialStarship> createDeathStar(ShieldPoints shield_points, AttackPower attack_power) {
    return std::make_shared<DeathStar>(DeathStar(shield_points, attack_power));
}


// ImperialDestroyer
ImperialDestroyer::ImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power) :
    Starship(shield_points),
    ImperialStarship(shield_points, attack_power) {}

std::shared_ptr<ImperialStarship> createImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power) {
    return std::make_shared<ImperialDestroyer>(ImperialDestroyer(shield_points, attack_power));
}

// TIEFighter
TIEFighter::TIEFighter(ShieldPoints shield_points, AttackPower attack_power) :
    Starship(shield_points),
    ImperialStarship(shield_points, attack_power) {}

std::shared_ptr<ImperialStarship> createTIEFighter(ShieldPoints shield_points, AttackPower attack_power) {
    return std::make_shared<TIEFighter>(TIEFighter(shield_points, attack_power));
}

// Squadron
// todo - brute or smart? (keeping alive&dead in 2 separates structures === smart)
Squadron::Squadron(const std::vector<ImperialStarship*>& ships) :
Starship(shield_points),
ImperialStarship(ShieldPoints{0}, AttackPower{0}), ships(ships) {
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
