#ifndef EXPLOSION_EFFECT_H
#define EXPLOSION_EFFECT_H

#include "spaceObject.h"

class ExplosionEffect : public SpaceObject, public Updatable
{
    constexpr static float maxLifetime = 2.0;
    constexpr static int particleCount = 1000;
    
    float lifetime= maxLifetime;
    float size = 1.0;
    sf::Vector3f particleDirections[particleCount];
    bool on_radar = false;
public:
    ExplosionEffect();

#if FEATURE_3D_RENDERING
    virtual void draw3DTransparent() override;
#endif
    virtual void drawOnRadar(sf::RenderTarget& window, sf::Vector2f position, float scale, bool longRange) override;
    virtual void update(float delta) override;
    
    void setSize(float size) { this->size = size; }
    void setOnRadar(bool on_radar) { this->on_radar = on_radar; }
};

#endif//EXPLOSION_EFFECT_H
