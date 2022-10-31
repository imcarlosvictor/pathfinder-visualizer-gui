#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <TGUI/TGUI.hpp>


void SfmlWindow();
void LoadWidgets(sf::RenderWindow& sfml_window, tgui::GuiBase& gui);
