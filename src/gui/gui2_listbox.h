#ifndef GUI2_LISTBOX_H
#define GUI2_LISTBOX_H

#include "gui2_element.h"
#include "gui2_entrylist.h"
#include "gui2_button.h"
#include "gui2_scrollbar.h"

class GuiListbox : public GuiEntryList
{
protected:
    std::vector<GuiButton*> buttons;
    float text_size = 30;
    float button_height = 50;
    EGuiAlign text_alignment = ACenter;
    sf::Color selected_color = sf::Color::White;
    sf::Color unselected_color = sf::Color(192, 192, 192, 255);;
    GuiScrollbar* scroll;
    sf::FloatRect last_rect;
public:
    GuiListbox(GuiContainer* owner, string id, func_t func);

    GuiListbox* setTextSize(float size);
    GuiListbox* setButtonHeight(float height);

    virtual void onDraw(sf::RenderTarget& window) override final;
    virtual bool onMouseDown(sf::Vector2f position) override final;
    virtual void onMouseUp(sf::Vector2f position) override final;
private:
    virtual void entriesChanged() override;
};

#endif//GUI2_LISTBOX_H
