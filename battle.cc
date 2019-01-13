#include "battle.h"
#include <iostream>
#include <memory>

//SpaceBattle
SpaceBattle::SpaceBattle(std::vector<std::shared_ptr<ImperialStarship>>&& imperial_ships,
                         std::vector<std::shared_ptr<RebelStarship>>&& rebel_ships,
                         Time t0, Time t1) :
                         imperial_ships(std::move(imperial_ships)),
                         rebel_ships(std::move(rebel_ships)) {
    battleTiming = std::make_unique<Timing235>(t0, t1);
}

SpaceBattle::Builder& SpaceBattle::Builder::ship(std::shared_ptr<RebelStarship> ship) {
    rebel_ships.push_back(ship);
    return *this;
}

SpaceBattle::Builder& SpaceBattle::Builder::ship(std::shared_ptr<ImperialStarship> ship) {
    imperial_ships.push_back(ship);
    return *this;
}


SpaceBattle::Builder& SpaceBattle::Builder::maxTime(Time time) {
    t1 = time;
    return *this;
}

SpaceBattle::Builder& SpaceBattle::Builder::startTime(Time time) {
    t0 = time;
    return *this;
}

SpaceBattle SpaceBattle::Builder::build() {
    return SpaceBattle(std::move(imperial_ships), std::move(rebel_ships), t0, t1);
}

std::size_t SpaceBattle::countImperialFleet() const {
    std::size_t count = 0;
    for (const auto &imp : imperial_ships) {
        count += imp->countAliveShips();
    }

    return count;
}

std::size_t SpaceBattle::countRebelFleet() const {
    std::size_t count = 0;
    for (const auto &reb : rebel_ships) {
           count += reb->countAliveShips();
    }
    return count;
}

void SpaceBattle::tick(Time timeStep) {
    std::size_t rebCount = countRebelFleet();
    std::size_t impCount = countImperialFleet();

    if (rebCount == 0 || impCount == 0) {
        if (rebCount == 0 && impCount == 0) {
            std::cout << "DRAW\n";
        } else if (rebCount == 0) {
            std::cout << "IMPERIUM WON\n";
        } else if (impCount == 0) {
            std::cout << "REBELLION WON\n";
        }
        return;
    }

    if (battleTiming->shouldAttack()) {
        for (const auto& imp : imperial_ships) {
            for (const auto& reb : rebel_ships) {
                if (imp->isAlive() && reb->isAlive()) {
                    executeAttack(*imp, *reb);
                }
            }
        }
    }

    battleTiming->stepTime(timeStep);
}

void SpaceBattle::executeAttack(ImperialStarship &imp, RebelStarship &reb) {
    reb.takeDamage(imp.getAttackPower());
    reb.attackBackIfAble(imp);
}

//Timing235
Timing235::Timing235(Time t0, Time t1) : t0(t0), t1(t1), currentTime(t0) {}

bool Timing235::shouldAttack() const {
    if (currentTime % 5 == 0) {
        return false;
    }
    if (currentTime % 2 == 0 || currentTime % 3 == 0) {
        return true;
    }
    return false;
}

void Timing235::stepTime(Time timeStep) {
    currentTime += timeStep;
    currentTime %= t1;
}
