#include <iostream>
#include "battle.h"

// Builder
SpaceBattle::Builder SpaceBattle::Builder::ship(ImperialStarship* ship) {
    imperial_fleet.push_back(ship);
    if(ship->isAlive()) {
        ++imperial_alive;
    }
}

SpaceBattle::Builder SpaceBattle::Builder::ship(RebelStarship* ship) {
    rebel_fleet.push_back(ship);
    if(ship->isAlive()) {
        ++rebel_alive;
    }
}

SpaceBattle::Builder SpaceBattle::Builder::ship(Squadron* squadron) {
    imperial_fleet.push_back(squadron);
    imperial_alive += squadron->numberOfAliveShips();
}

SpaceBattle::Builder SpaceBattle::Builder::startTime(T time) {}

SpaceBattle::Builder SpaceBattle::Builder::maxTime(T max_time) {}

SpaceBattle SpaceBattle::Builder::build() {
    return SpaceBattle();
}

// SpaceBattle
std::size_t SpaceBattle::countImperialFleet() {}

std::size_t SpaceBattle::countRebelFleet() {}

void SpaceBattle::tick(T timeStep) {}
