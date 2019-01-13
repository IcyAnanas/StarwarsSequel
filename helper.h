#ifndef _HELPER_H_
#define _HELPER_H_

#include <cstring>

using ShieldPoints = int;
using AttackPower = int;

class Starship {
protected:
    ShieldPoints shield_points;
    Starship(ShieldPoints shield_points);

public:
    virtual ShieldPoints getShield() const;
    virtual ~Starship() = default;
    bool isAlive() const;
    virtual void takeDamage(AttackPower damage) = 0;
    virtual int countAliveShips() const = 0;
};

class Attacker : virtual public Starship {
protected:
    AttackPower attack_power;
    Attacker(ShieldPoints shield_points, AttackPower attack_power);
public:
    AttackPower getAttackPower() const;
    virtual ~Attacker() = default;
};

class SingleStarship : virtual public Starship {
protected:
    SingleStarship(ShieldPoints shield_points);
public:
    void takeDamage(AttackPower damage) override;
    int countAliveShips() const override;
    virtual ~SingleStarship() = default;
};


#endif //_HELPER_H_
