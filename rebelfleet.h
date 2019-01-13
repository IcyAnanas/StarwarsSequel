#ifndef _REBELFLEET_H_
#define _REBELFLEET_H_

#include "helper.h"
#include "imperialfleet.h"
#include <cassert>
#include <type_traits>
#include <memory>

using Speed = int;

class LimitedSpeedVehicle {
private:
    const Speed speed;
    void checkSpeed(Speed min, Speed max);
protected:
    LimitedSpeedVehicle(Speed min, Speed max, Speed speed);
    virtual ~LimitedSpeedVehicle() = default;
public:
    Speed getSpeed() const;
};


class RebelStarship : public SingleStarship, public LimitedSpeedVehicle {
public:
    RebelStarship(ShieldPoints shield_points, Speed speed, Speed min, Speed max);

    virtual void attackBackIfAble(ImperialStarship& imp);

    virtual ~RebelStarship() = default;
};

class RebelAttacker : public RebelStarship, public Attacker {
public:
    RebelAttacker(ShieldPoints shield_points, Speed min, Speed max, Speed speed, AttackPower attack_power);

    void attackBackIfAble(ImperialStarship& imp) override;

    virtual ~RebelAttacker() = default;
};

class Explorer : public RebelStarship {
public:
    Explorer(ShieldPoints, Speed);
};

std::shared_ptr<RebelStarship> createExplorer(ShieldPoints shield_points, Speed speed);


class StarCruiser : public RebelAttacker {
public:
    StarCruiser(ShieldPoints, Speed, AttackPower);
};

std::shared_ptr<RebelStarship> createStarCruiser(ShieldPoints shield_points, Speed speed, AttackPower attack_power);


class XWing : public RebelAttacker {
public:
    XWing(ShieldPoints, Speed, AttackPower);
};

std::shared_ptr<RebelStarship> createXWing(ShieldPoints shield_points, Speed speed, AttackPower attack_power);

#endif // _REBELFLEET_H_
