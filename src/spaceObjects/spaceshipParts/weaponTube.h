#ifndef WEAPON_TUBE_H
#define WEAPON_TUBE_H

#include "SFML/System/NonCopyable.hpp"
#include "shipTemplate.h"

class SpaceShip;

enum EWeaponTubeState
{
    WTS_Empty,
    WTS_Loading,
    WTS_Loaded,
    WTS_Unloading,
    WTS_Firing
};

class WeaponTube : public sf::NonCopyable
{
public:
    void setParent(SpaceShip* parent);
    void setIndex(int index);

    float getLoadTimeConfig() const;
    void setLoadTimeConfig(float load_time);

    void setDirection(float direction);
    float getDirection() const;
    
    /*!
     * Load a missile tube.
     * \param type Weapon type that is loaded.
     */
    void startLoad(EMissileWeapons type);
    void startUnload();
    /*!
     * Fire a missile tube.
     * \param target_angle Angle in degrees to where the missile needs to be shot.
     */
    void fire(float target_angle);

    bool canLoad(EMissileWeapons type) const;
    bool canOnlyLoad(EMissileWeapons type) const;
    void allowLoadOf(EMissileWeapons type);
    void disallowLoadOf(EMissileWeapons type);
    
    void forceUnload();
    
    void update(float delta);

    bool isEmpty() const;
    bool isLoaded() const;
    bool isLoading() const;
    bool isUnloading() const;
    bool isFiring() const;
    
    float getLoadProgress() const ;
    float getUnloadProgress() const;

    EMissileWeapons getLoadType() const;
    
    string getTubeName() const; //Get the tube name based on the direction of the tube.

    //Calculate a possible firing solution towards the target for this missile tube.
    //Will return the angle that the missile needs to turn to to possibly hit this target.
    //Will return infinity when no solution is found.
    float calculateFiringSolution(P<SpaceObject> target);
private:
    void spawnProjectile(float target_angle);

    SpaceShip* parent = nullptr;
    int tube_index = 0;
    
    //Configuration
    float load_time = 8.0;
    uint32_t type_allowed_mask  = (1 << MW_Count) - 1;
    float direction = 0;

    //Runtime state
    EMissileWeapons type_loaded = MW_None;
    EWeaponTubeState state = WTS_Empty;
    float delay = 0.0;
    int fire_count = 1;
};

#endif//WEAPON_TUBE_H
