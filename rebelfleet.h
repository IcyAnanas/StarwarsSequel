#ifndef _REBELFLEET_H_
#define _REBELFLEET_H_

#include <cassert>
#include <type_traits>

using Speed = int;
using ShieldPoints = int;
using AttackPower = int;

class RebelStarship {
protected:
    const Speed speed;
    ShieldPoints shield_points;
    virtual void checkSpeed() = 0;

public:
    RebelStarship(ShieldPoints shield_points, Speed speed);

    ShieldPoints getShield() const;
    Speed getSpeed() const;

    void takeDamage(AttackPower damage);
    bool isAlive() const;
};

class Attacker : public RebelStarship {
    AttackPower attack_power;
public:
    AttackPower getAttackPower() const;
    Attacker(ShieldPoints shield_points, Speed speed, AttackPower attack_power);
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

class StarCruiser : public Attacker {
protected:
    void checkSpeed() override {
        assert(speed >= static_cast<Speed>(99999)&& speed <= static_cast<Speed>(299795) &&
               "Given speed doesn't satisfy requirements");
    }
public:
    StarCruiser(ShieldPoints, Speed, AttackPower);
};


class XWing : public Attacker {
protected:
    void checkSpeed() override {
        assert(speed >= static_cast<Speed>(299796)&& speed <= static_cast<Speed>(2997960) &&
               "Given speed doesn't satisfy requirements");
    }
public:
    XWing(ShieldPoints, Speed, AttackPower);
};

#endif // _REBELFLEET_H_
