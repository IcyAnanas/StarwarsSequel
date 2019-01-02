#ifndef _REBELFLEET_H_
#define _REBELFLEET_H_

#include <cassert>
#include <type_traits>

template <typename ShieldPoints, typename Speed, typename AttackPower>
class RebelStarship {
    // protected at least probably
    const Speed speed;
    ShieldPoints shield_points;

protected:
    int min_speed = 0;
    int max_speed = 0;
    void checkSpeed() {
        assert(speed >= static_cast<Speed>(min_speed)&& speed <= static_cast<Speed>(max_speed) &&
               "Given speed doesn't satisfy requirements");
    }

public:
    RebelStarship(ShieldPoints shield_points, Speed speed);

    ShieldPoints getShield() const;
    Speed getSpeed() const;

    void takeDamage(AttackPower damage);
    bool isAlive() const;
};

template <typename ShieldPoints, typename Speed, typename AttackPower>
class Attacker : public RebelStarship<ShieldPoints, Speed, AttackPower> {
    AttackPower attack_power;
public:
    AttackPower getAttackPower() const;
    Attacker(ShieldPoints shield_points, Speed speed, AttackPower attack_power);
};

template <typename ShieldPoints, typename Speed, typename AttackPower>
class Explorer : public RebelStarship<ShieldPoints, Speed, AttackPower>{
public:
    Explorer(ShieldPoints, Speed);
};

template <typename ShieldPoints, typename Speed, typename AttackPower>
class StarCruiser : public Attacker<ShieldPoints, Speed, AttackPower>{
public:
    StarCruiser(ShieldPoints, Speed, AttackPower);
};


template <typename ShieldPoints, typename Speed, typename AttackPower>
class XWing : public Attacker<ShieldPoints, Speed, AttackPower>{
public:
    XWing(ShieldPoints, Speed, AttackPower);
};



// RebelStarship
template <typename ShieldPoints, typename Speed, typename AttackPower>
RebelStarship<ShieldPoints, Speed, AttackPower>::RebelStarship(
        ShieldPoints shield_points, Speed speed) : speed(speed), shield_points(shield_points) {}

template <typename ShieldPoints, typename Speed, typename AttackPower>
ShieldPoints RebelStarship<ShieldPoints, Speed, AttackPower>::getShield() const {return shield_points;}

template <typename ShieldPoints, typename Speed, typename AttackPower>
Speed RebelStarship<ShieldPoints, Speed, AttackPower>::getSpeed() const {return speed;}

template <typename ShieldPoints, typename Speed, typename AttackPower>
void RebelStarship<ShieldPoints, Speed, AttackPower>::takeDamage(AttackPower damage) {
    if(shield_points <= damage) {
        shield_points = ShieldPoints{0};
    }
    else {
        shield_points -= damage;
    }
}

template <typename ShieldPoints, typename Speed, typename AttackPower>
bool RebelStarship<ShieldPoints, Speed, AttackPower>::isAlive() const {
    return shield_points > 0;
}

// Attacker
template <typename ShieldPoints, typename Speed, typename AttackPower>
Attacker<ShieldPoints, Speed, AttackPower>::Attacker(
        ShieldPoints shield_points, Speed speed, AttackPower attack_power) :
            RebelStarship<ShieldPoints, Speed, AttackPower>(shield_points, speed),
            attack_power(attack_power) {}

template <typename ShieldPoints, typename Speed, typename AttackPower>
AttackPower Attacker<ShieldPoints, Speed, AttackPower>::getAttackPower() const {return attack_power;}


// Explorer
template <typename ShieldPoints, typename Speed, typename AttackPower>
Explorer<ShieldPoints, Speed, AttackPower>::Explorer(ShieldPoints shield_points, Speed speed) :
        RebelStarship<ShieldPoints, Speed, AttackPower>(shield_points, speed) {
            this->min_speed = 299796;
            this->max_speed = 2997960;
            this->checkSpeed();
}


// StarCruiser
template <typename ShieldPoints, typename Speed, typename AttackPower>
StarCruiser<ShieldPoints, Speed, AttackPower>::StarCruiser(
        ShieldPoints shield_points, Speed speed, AttackPower attack_power) :
        Attacker<ShieldPoints, Speed, AttackPower>(shield_points, speed, attack_power) {
            this->min_speed = 99999;
            this->max_speed = 299795;
            this->checkSpeed();
        }

// XWing
template <typename ShieldPoints, typename Speed, typename AttackPower>
XWing<ShieldPoints, Speed, AttackPower>::XWing(ShieldPoints shield_points, Speed speed, AttackPower attack_power) :
        Attacker<ShieldPoints, Speed, AttackPower>::Attacker(shield_points, speed) {
            this->min_speed = 299796;
            this->max_speed = 2997960;
            this->checkSpeed();
        }

#endif // _REBELFLEET_H_
