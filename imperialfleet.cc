#include "imperialfleet.h"
#include <iostream>

// ImperialStarship
ImperialStarship::ImperialStarship(ShieldPoints shield_points, AttackPower attack_power) :
    Starship(shield_points),
    Attacker(shield_points, attack_power) {}

// SingleImperialStarship
SingleImperialStarship::SingleImperialStarship(ShieldPoints shield_points, AttackPower attack_power) :
    Starship(shield_points),
    SingleStarship(shield_points),
    ImperialStarship(shield_points, attack_power) {}

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

Squadron::Squadron(const std::initializer_list<std::shared_ptr<ImperialStarship>>& ships) :
        Squadron(std::vector<std::shared_ptr<ImperialStarship>>(ships)) {}

int Squadron::countAliveShips() const {
    return alive;
}


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

std::shared_ptr<ImperialStarship> createSquadron(const std::vector<std::shared_ptr<ImperialStarship>>& ships) {
    return std::make_shared<Squadron>(Squadron(ships));
}

std::shared_ptr<ImperialStarship> createSquadron(const std::initializer_list<std::shared_ptr<ImperialStarship>>& ships) {
    return std::make_shared<Squadron>(Squadron(ships));
}
