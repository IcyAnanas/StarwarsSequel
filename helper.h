#ifndef _HELPER_H_
#define _HELPER_H_

using ShieldPoints = int;
using AttackPower = int;

class Starship {
protected:
    ShieldPoints shield_points;
    Starship(ShieldPoints shield_points);           // todo - explicit?

public:
    virtual ShieldPoints  getShield() const;
    virtual ~Starship() = default;
    bool isAlive() const;
};

class Attacker : virtual public Starship {
protected:
    AttackPower attack_power;
    Attacker(ShieldPoints shield_points, AttackPower attack_power);
public:
    AttackPower getAttackPower() const;
    virtual ~Attacker() = default;
};



#endif //_HELPER_H_
