#ifndef _REBELFLEET_H_
#define _REBELFLEET_H_

#include <cassert>
#include <type_traits>
#include <memory>
#include "helper.h"

using Speed = int;

class LimitedSpeedVehicle {
private:
    void checkSpeed(Speed min, Speed max);
protected:
    const Speed speed;
    LimitedSpeedVehicle(Speed min, Speed max, Speed speed);
    virtual ~LimitedSpeedVehicle() = default;
public:
    Speed getSpeed() const;
};



// todo - public, private inheritance??
class RebelStarship : public SingleStarship, public LimitedSpeedVehicle {
public:
    RebelStarship(ShieldPoints shield_points, Speed speed, Speed min, Speed max);

    virtual ~RebelStarship() = default;
};



class Explorer : public RebelStarship {
public:
    Explorer(ShieldPoints, Speed);
};

std::shared_ptr<RebelStarship> createExplorer(ShieldPoints shield_points, Speed speed);



class StarCruiser : public Attacker, public RebelStarship {
public:
    StarCruiser(ShieldPoints, Speed, AttackPower);
};

std::shared_ptr<RebelStarship> createStarCruiser(ShieldPoints shield_points, Speed speed, AttackPower attack_power);



class XWing : public Attacker, public RebelStarship {
public:
    XWing(ShieldPoints, Speed, AttackPower);
};

std::shared_ptr<RebelStarship> createXWing(ShieldPoints shield_points, Speed speed, AttackPower attack_power);

#endif // _REBELFLEET_H_
