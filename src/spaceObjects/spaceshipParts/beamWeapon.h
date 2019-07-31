#ifndef BEAM_WEAPON_H
#define BEAM_WEAPON_H

#include "SFML/System/NonCopyable.hpp"
#include "stringImproved.h"
#include "spaceObjects/spaceObject.h"
class SpaceShip;

class BeamWeapon : public sf::NonCopyable
{
public:
    BeamWeapon() = default;

    void fire(P<SpaceObject> target, ESystem system_target);

    void setParent(SpaceShip* parent);

    void setArc(float arc);
    float getArc() const;;

    void setDirection(float direction);
    float getDirection() const;;

    void setRange(float range);
    float getRange() const;;

    void setTurretArc(float arc);
    float getTurretArc() const;;

    void setTurretDirection(float direction);
    float getTurretDirection() const;;

    void setTurretRotationRate(float rotation_rate);
    float getTurretRotationRate() const;;

    void setCycleTime(float cycle_time);
    float getCycleTime() const;;
    
    void setDamage(float damage);
    float getDamage() const;

    float getEnergyPerFire() const;
    void setEnergyPerFire(float energy);

    float getHeatPerFire() const;
    void setHeatPerFire(float heat);

    void setPosition(sf::Vector3f position);
    sf::Vector3f getPosition() const;;
    
    void setBeamTexture(string beam_texture);
    const string& getBeamTexture() const;

    float getCooldown() const;;
    
    void update(float delta);
protected:
    sf::Vector3f position;//Visual position on the 3D model where this beam is fired from.
    SpaceShip* parent = nullptr; //The ship that this beam weapon is attached to.

    //Beam configuration
    float arc = 0.0f;
    float direction = 0.0f;
    float range = 0.0f;
    float turret_arc = 0.0f;
    float turret_direction = 0.0f;
    float turret_rotation_rate = 0.0f;
    float cycle_time = 6.0f;
    float damage = 1.0f;//Server side only
    float energy_per_beam_fire = 3.0f;//Server side only
    float heat_per_beam_fire = 0.02f;//Server side only
    //Beam runtime state
    float cooldown = 0.0f;
    string beam_texture;
};

#endif//BEAM_WEAPON_H
