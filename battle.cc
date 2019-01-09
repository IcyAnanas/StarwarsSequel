#include "battle.h"
#include <iostream>
#include <memory>

//SpaceBattle

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

SpaceBattle& SpaceBattle::Builder::build() {
    SpaceBattle battle;
    battle.imperial_ships = imperial_ships;
    battle.rebel_ships = rebel_ships;
    battle.battleTiming = std::make_unique<Timing235>(t0, t1);
    return battle;
}

std::size_t SpaceBattle::countImperialFleet() const {
    std::size_t count = 0;
    for (auto &imp : imperial_ships) {
        count += imp->countAliveShips();
    }

    return count;
}

std::size_t SpaceBattle::countRebelFleet() const {
    std::size_t count = 0;
    for (auto &reb : rebel_ships) {
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

    if (battleTiming->shouldAttack(timeStep)) {
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
Timing235::Timing235(Time _t0, Time _t1) {
    t0 = _t0;
    t1 = _t1;
}

bool Timing235::shouldAttack(Time t) {
    if (t % 5 == 0) {
        return false;
    }
    if (t % 2 == 0 || t % 3 == 0) {
        return true;
    }
    return false;
}

void Timing235::stepTime(Time timeStep) {
    currentTime += timeStep;
    if (currentTime > t1) {
        currentTime = t0 + (currentTime % t1);
    }
}
