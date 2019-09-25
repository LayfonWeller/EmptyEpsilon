#ifndef CINEMATIC_VIEW_SCREEN_H
#define CINEMATIC_VIEW_SCREEN_H

#include "engine.h"
#include "gui/gui2_canvas.h"
#include "gui/gui2_label.h"
#include "screenComponents/viewport3d.h"

class GuiSelector;
class GuiToggleButton;

class CinematicViewScreen : public GuiCanvas, public Updatable
{
private:
    const double pi = M_PI;

    GuiViewport3D* viewport;
    P<PlayerSpaceship> target;
    GuiSelector* camera_lock_selector;
    GuiToggleButton* camera_lock_toggle;
    GuiToggleButton* camera_lock_tot_toggle;
    float min_camera_distance = 10.0f;
    float max_camera_distance = 1000.f;
    sf::Vector2f camera_rotation_vector;
    sf::Vector2f camera_destination;
    float angle_yaw = 0.0f;
    float angle_pitch = 0.0f;

    sf::Vector2f diff_2D;
    sf::Vector3f diff_3D;
    float distance_2D = 10.0f;
    float distance_3D = 10.0f;

    sf::Vector2f target_position_2D;
    sf::Vector3f target_position_3D;
    // camera_position is a Vector3, so no need to declare one here.
    sf::Vector2f camera_position_2D;
    float target_rotation = 0.0f;
    // float target_velocity = 0.0f;

    P<SpaceObject> target_of_target;

    sf::Vector2f tot_position_2D;
    sf::Vector3f tot_position_3D;
    sf::Vector2f tot_diff_2D;
    sf::Vector3f tot_diff_3D;
    float tot_angle = 0.0f;
    float tot_distance_2D = 0.0f;
    float tot_distance_3D = 0.0f;

public:
    CinematicViewScreen();
    
    virtual void update(float delta) override;
    
    virtual void onKey(sf::Event::KeyEvent key, int unicode) override;
};

#endif//CINEMATIC_VIEW_SCREEN_H
