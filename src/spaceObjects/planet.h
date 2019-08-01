#ifndef PLANET_H
#define PLANET_H

#include "nebula.h"
#include "spaceObject.h"
#include "pathPlanner.h"

class Planet : public SpaceObject, public Updatable
{
public:
    Planet();

#if FEATURE_3D_RENDERING
    virtual void draw3D() override;
    virtual void draw3DTransparent() override;
#endif//FEATURE_3D_RENDERING
    virtual void drawOnRadar(sf::RenderTarget& window, sf::Vector2f position, float scale, bool long_range) override;
    virtual void drawOnGMRadar(sf::RenderTarget& window, sf::Vector2f draw_position, float scale, bool long_range) override;
    virtual void update(float delta) override;
    virtual void collide(Collisionable* target, float force) override;
    
    void setPlanetAtmosphereColor(float r, float g, float b);
    void setPlanetAtmosphereTexture(string texture_name);
    void setPlanetSurfaceTexture(string texture_name);
    void setPlanetCloudTexture(string texture_name);
    void setPlanetRadius(float size);
    void setPlanetCloudRadius(float size);
    void setDistanceFromMovementPlane(float distance_from_movement_plane);
    void setAxialRotationTime(float time);
    void setOrbit(P<SpaceObject> target, float orbit_time);
    
    virtual string getExportLine() override { return "Planet():setPosition(" + string(getPosition().x, 0) + ", " + string(getPosition().y, 0) + ")"; }

private:
    //Config:
    float planet_size = 5000.0f;
    float cloud_size = 5200.0f;
    float atmosphere_size;
    string planet_texture = "";
    string cloud_texture = "";
    string atmosphere_texture = "";
    sf::Color atmosphere_color = sf::Color(0, 0, 0);
    float distance_from_movement_plane = 0.0f;
    
    float axial_rotation_time = 0.0f;
    int32_t orbit_target_id = -1;
    float orbit_time = 0.0f;
    float orbit_distance = 0.0f;
    
    float collision_size = -2.0f;

    void updateCollisionSize();
};

#endif//WORM_HOLE_H

