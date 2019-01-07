#ifndef _REBELFLEET_H_
#define _REBELFLEET_H_

#include <cassert>
#include <type_traits>
#include <memory>
#include "imperialfleet.h"

using Speed = int;
using ShieldPoints = int;
using AttackPower = int;

// todo - ctors with const references, move maybe?
// todo - no templates?

class RebelStarship {
protected:
    const Speed speed;
    ShieldPoints shield_points;
    virtual void checkSpeed();

public:
    RebelStarship(ShieldPoints shield_points, Speed speed);

    ShieldPoints getShield() const;
    Speed getSpeed() const;

    void takeDamage(AttackPower damage);
    bool isAlive() const;

    virtual void attackBackIfAble(ImperialStarship& imp);

    virtual ~RebelStarship() = default;
};

class Attacker : public RebelStarship {
    AttackPower attack_power;
public:
    AttackPower getAttackPower() const;
    Attacker(ShieldPoints shield_points, Speed speed, AttackPower attack_power);
    void attackBackIfAble(ImperialStarship& imp) override;
    virtual ~Attacker() = default;
};

class Explorer : public RebelStarship {
protected:
    void checkSpeed() override {
        assert(speed >= static_cast<Speed>(299796)&& speed <= static_cast<Speed>(2997960) &&
               "Given speed doesn't satisfy requirements");
    }
public:
    Explorer(ShieldPoints, Speed);
};

std::shared_ptr<Explorer> createExplorer(ShieldPoints shield_points, Speed speed);

class StarCruiser : public Attacker {
protected:
    void checkSpeed() override {
        assert(speed >= static_cast<Speed>(99999)&& speed <= static_cast<Speed>(299795) &&
               "Given speed doesn't satisfy requirements");
    }
public:
    StarCruiser(ShieldPoints, Speed, AttackPower);
};

std::shared_ptr<StarCruiser> createStarCruiser(ShieldPoints shield_points, Speed speed, AttackPower attack_power);

class XWing : public Attacker {
protected:
    void checkSpeed() override {
        assert(speed >= static_cast<Speed>(299796)&& speed <= static_cast<Speed>(2997960) &&
               "Given speed doesn't satisfy requirements");
    }
public:
    XWing(ShieldPoints, Speed, AttackPower);
};

std::shared_ptr<XWing> createXWing(ShieldPoints shield_points, Speed speed, AttackPower attack_power);

#endif // _REBELFLEET_H_
