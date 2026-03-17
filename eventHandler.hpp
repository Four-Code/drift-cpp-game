#pragma once
#include <vector>
#include "UIElements/button.hpp"

class EventHandler{
    public:
    std::vector<GUIButton*> buttons;
    void addButton(GUIButton& btn);
    void handleClick(int x, int y);
};