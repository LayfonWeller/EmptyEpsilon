#ifndef BEAM_TEMPLATE_H
#define BEAM_TEMPLATE_H

#include "SFML/System/NonCopyable.hpp"

#include "stringImproved.h"

class BeamTemplate : public sf::NonCopyable
{
public:
    BeamTemplate() = default;

    const string& getBeamTexture() const;

    void setBeamTexture(string texture);

    /**
     * Beam weapons are 'arc-ed' weapons, the direction is the center of the arc.
     * Will always return values between 0 and 360
     */
    float getDirection() const;

    /**
     * Set the direction of the beam weapon.
     */
    void setDirection(float direction);

    float getArc() const;
    void setArc(float arc);

    float getRange() const;
    void setRange(float range);

    float getTurretDirection() const;
    void setTurretDirection(float direction);

    float getTurretArc() const;
    void setTurretArc(float arc);

    float getTurretRotationRate() const;
    void setTurretRotationRate(float rotation_rate);

    float getCycleTime() const;
    void setCycleTime(float cycle_time);

    float getDamage() const;
    void setDamage(float damage);

    float getEnergyPerFire() const;
    void setEnergyPerFire(float energy);

    float getHeatPerFire() const;
    void setHeatPerFire(float heat);
    
    BeamTemplate& operator=(const BeamTemplate& other);

protected:
    string beam_texture = "beam_orange.png";
    float direction=0; // Value between 0 and 360 (degrees)
    float arc = 0; // Value between 0 and 360
    float range =0; // Value greater than 0
    float turret_direction=0; // Value between 0 and 360 (degrees)
    float turret_arc=0; // Value between 0 and 360
    float turret_rotation_rate=0; // Value between 0 and 25 (degrees/tick)
    float cycle_time=0; // Value greater than 0
    float damage=0;
    float energy_per_beam_fire = 3.0;
    float heat_per_beam_fire = 0.02;
};

#endif//BEAM_TEMPLATE_H
