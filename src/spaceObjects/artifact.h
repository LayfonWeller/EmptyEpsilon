#ifndef ARTIFACT_H
#define ARTIFACT_H

#include "spaceObject.h"

class Artifact : public SpaceObject, public Updatable
{
private:
    string current_model_data_name;
    string model_data_name;
    bool allow_pickup = false;
public:
    Artifact();

    virtual void update(float delta) override;

    virtual void drawOnRadar(sf::RenderTarget& window, sf::Vector2f position, float scale, bool long_range) override;

    virtual void collide(Collisionable* target, float force) override;

    void setModel(string name);
    void explode();
    void allowPickup(bool allow);
    
    virtual string getExportLine() override;
};

#endif//ARTIFACT_H
