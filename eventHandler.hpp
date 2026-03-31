#pragma once
#include <vector>
#include "UIElements/button.hpp"
#include "UIElements/clickableRectangle.hpp"

class EventHandler{
    public:
    std::vector<GUIButton*> buttons;
    std::vector<ClickableRectangle*> clickElements;
    void addButton(GUIButton& btn);
    void addClickableRect(ClickableRectangle& element);
    void handleClick(int x, int y);
    void handleHover(int x, int y);
};