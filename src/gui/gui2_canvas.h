#ifndef GUI2_CANVAS_H
#define GUI2_CANVAS_H

#include "engine.h"
#include "gui2_container.h"

class GuiCanvas : public Renderable, public GuiContainer, public InputEventHandler
{
private:
    GuiElement* click_element = nullptr;
    GuiElement* focus_element = nullptr;
    sf::Vector2f previous_mouse_position;
    sf::Vector2f previous_joystick_xy_position;
    float previous_joystick_z_position = 0.0;
    float previous_joystick_r_position = 0.0;
    bool enable_debug_rendering = false;
public:
    GuiCanvas() = default;
    virtual ~GuiCanvas() = default;

    virtual void render(sf::RenderTarget& window) override;
    virtual void handleKeyPress(sf::Event::KeyEvent key, int unicode) override;
    
    virtual void onClick(sf::Vector2f mouse_position);
    virtual void onHotkey(const HotkeyResult& key);
    virtual void onKey(sf::Event::KeyEvent key, int unicode);
    
    //Called when an element is destroyed in this tree. Recursive tests if the given element or any of it's children currently has focus, and unsets that focus.
    void unfocusElementTree(GuiElement* element);
};

#endif//GUI2_CANVAS_H
