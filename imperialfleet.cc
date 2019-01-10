#include <iostream>
#include "imperialfleet.h"

// ImperialStarship
ImperialStarship::ImperialStarship(ShieldPoints shield_points, AttackPower attack_power) :
    Starship(shield_points),
    Attacker(shield_points, attack_power) {
}

// SingleImperialStarship
SingleImperialStarship::SingleImperialStarship(ShieldPoints shield_points, AttackPower attack_power) :
    Starship(shield_points),
    SingleStarship(shield_points),
    ImperialStarship(shield_points, attack_power) {
}

// DeathStar
DeathStar::DeathStar(ShieldPoints shield_points, AttackPower attack_power) :
    Starship(shield_points),
    SingleImperialStarship(shield_points, attack_power) {}

std::shared_ptr<ImperialStarship> createDeathStar(ShieldPoints shield_points, AttackPower attack_power) {
    return std::make_shared<DeathStar>(DeathStar(shield_points, attack_power));
}


// ImperialDestroyer
ImperialDestroyer::ImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power) :
    Starship(shield_points),
    SingleImperialStarship(shield_points, attack_power) {}

std::shared_ptr<ImperialStarship> createImperialDestroyer(ShieldPoints shield_points, AttackPower attack_power) {
    return std::make_shared<ImperialDestroyer>(ImperialDestroyer(shield_points, attack_power));
}

// TIEFighter
TIEFighter::TIEFighter(ShieldPoints shield_points, AttackPower attack_power) :
    Starship(shield_points),
    SingleImperialStarship(shield_points, attack_power) {}

std::shared_ptr<ImperialStarship> createTIEFighter(ShieldPoints shield_points, AttackPower attack_power) {
    return std::make_shared<TIEFighter>(TIEFighter(shield_points, attack_power));
}

// Squadron
Squadron::Squadron(const std::vector<std::shared_ptr<ImperialStarship>>& ships) :
Starship(ShieldPoints{0}),
ImperialStarship(ShieldPoints{0}, AttackPower{0}), ships(ships) {
    for (const auto& ship : ships) {
        if(ship->isAlive()) {
            alive += ship->countAliveShips();
            shield_points += ship->getShield();
            attack_power += ship->getAttackPower();
        }
    }
}

int Squadron::countAliveShips() const {
    return alive;
}

// todo
// wouldn't it be better if we implemented a ctor for vector&& and use move then?
// because the creation of a new vector seems like using one too many vectors...
// or even to totally erase destroyed ships from Squadron

//Squadron::Squadron(const std::initializer_list<ImperialStarship*>& ships) :
//    Squadron(std::vector<ImperialStarship*>(ships)) {}

void Squadron::takeDamage(AttackPower damage) {
    for(auto& ship : ships) {
        if(ship->isAlive()) {
            int killed = ship->countAliveShips();
            ShieldPoints shield_decrease = ship->getShield();
            AttackPower attack_power_decrease = ship->getAttackPower();

            ship->takeDamage(damage);

            killed -= ship->countAliveShips();
            shield_decrease -= ship->getShield();
            if(ship->isAlive()) attack_power_decrease -= ship->getAttackPower();

            alive -= killed;
            shield_points -= shield_decrease;
            attack_power -= attack_power_decrease;
        }
    }
}

// clang suggested to move it instead - we could write a moving function as well, but do we really need to?
std::shared_ptr<ImperialStarship> createSquadron(const std::vector<std::shared_ptr<ImperialStarship>>& ships) {
    return std::make_shared<Squadron>(Squadron(ships));
}

//// todo - casting initializer_list on a vector - not sure whether it's completely valid
//std::shared_ptr<ImperialStarship> createSquadron(const std::initializer_list<ImperialStarship*>& ships) {
//    return createSquadron(std::vector<ImperialStarship*>(ships));
//}
