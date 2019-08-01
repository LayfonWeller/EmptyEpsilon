#ifndef GUI2_PROGRESSBAR_H
#define GUI2_PROGRESSBAR_H

#include "gui2_element.h"

class GuiProgressbar : public GuiElement
{
private:
    float min;
    float max;
    float value;
    sf::Color color = sf::Color(255, 255, 255, 64);
    bool drawBackground = true;

    string text;
public:
    GuiProgressbar(GuiContainer* owner, string id, float min, float max, float value);

    virtual void onDraw(sf::RenderTarget& window) override;

    GuiProgressbar* setValue(float value);
    GuiProgressbar* setRange(float min, float max);
    GuiProgressbar* setText(string text);
    GuiProgressbar* setColor(sf::Color color);
    GuiProgressbar* setDrawBackground(bool drawBackground);
};

#endif//GUI2_PROGRESSBAR_H
