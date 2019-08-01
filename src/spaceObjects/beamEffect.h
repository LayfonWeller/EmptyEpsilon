#ifndef BEAM_EFFECT_H
#define BEAM_EFFECT_H

#include <limits>

#include "spaceObject.h"

class BeamEffect : public SpaceObject, public Updatable
{
    float lifetime = 1.0;
    int32_t sourceId = std::numeric_limits<int32_t>::max();
    int32_t target_id = std::numeric_limits<int32_t>::max();
    sf::Vector3f sourceOffset;
    sf::Vector3f targetOffset;
    sf::Vector2f targetLocation;
    sf::Vector3f hitNormal;
public:
    string beam_texture;
    BeamEffect();

#if FEATURE_3D_RENDERING
    virtual void draw3DTransparent() override;
#endif
    virtual void update(float delta) override;

    void setSource(P<SpaceObject> source, sf::Vector3f offset);
    void setTarget(P<SpaceObject> target, sf::Vector2f hitLocation);
};

#endif//BEAM_EFFECT_H
