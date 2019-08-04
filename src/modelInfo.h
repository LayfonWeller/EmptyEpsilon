#ifndef MODEL_INFO_H
#define MODEL_INFO_H

#include "modelData.h"

class ModelInfo : sf::NonCopyable
{
private:
    P<ModelData> data;
    float last_engine_particle_time = 0.0f;
    float last_warp_particle_time = 0.0f;
public:
    ModelInfo() = default;
    
    float engine_scale = 0.0f;
    float warp_scale = 0.0f;

    void render(sf::Vector2f position, float rotation);
    void renderOverlay(sf::Texture* texture, float alpha);
    void renderShield(float alpha);
    void renderShield(float alpha, float angle);
    
    void setData(P<ModelData> data) { this->data = data; }
    void setData(string name);
};

#endif//MODEL_INFO_H
