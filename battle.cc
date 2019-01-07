#include "battle.h"
#include <iostream>

SpaceBattle::Builder &SpaceBattle::Builder::ship(RebelStarship ship) {
    rebelShips.push_back(ship);
    return *this;
}

SpaceBattle::Builder &SpaceBattle::Builder::ship(ImperialStarship ship) {
    imperialShips.push_back(ship);
    return *this;
}

SpaceBattle::Builder &SpaceBattle::Builder::maxTime(Time time) {
    t1 = time;
    return *this;
}

SpaceBattle::Builder &SpaceBattle::Builder::startTime(Time time) {
    t0 = time;
    return *this;
}

SpaceBattle &SpaceBattle::Builder::build() {
    SpaceBattle battle;
    battle.imperialShips = imperialShips;
    battle.rebelShips = rebelShips;
    battle.t0 = battle.currentTime = t0;
    battle.t1 = t1;
    return battle;
}

std::size_t SpaceBattle::countImperialFleet() const {
    std::size_t count;
    for (auto &imp : imperialShips) {
        count += imp.numberOfAliveShips();
    }
    return count;
}

std::size_t SpaceBattle::countRebelFleet() const {
    std::size_t count;
    for (auto &reb : rebelShips) {
        if (reb.isAlive()) {
            ++count;
        }
    }
    return count;
}

void SpaceBattle::tick(T timeStep) {
    int rebCount = countRebelFleet();
    int impCount = countImperialFleet();

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

    if (getTimingSTrategy().shouldAttack(timeStep)) {
        for (auto &imp : imperialShips) {
            for (auto &reb : rebelShips) {
                if (imp.isAlive() && reb.isAlive()) {
                    executeAttack(imp, reb);
                }
            }
        }
    }
}

void SpaceBattle::executeAttack(ImperialStarship &imp, RebelStarship &reb) {
    reb.takeDamage(imp.getAttackPower());
    if (Attacker *v = dynamic_cast<Attacker *>(&reb)) {
        imp.takeDamage(v->getAttackPower());
    }
}

TimingStrategy &SpaceBattle::getTimingSTrategy() {
    static Timing235 timing;
    return timing;
}

