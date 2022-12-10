#pragma once

#include <iostream>

#include "./grid.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <TGUI/TGUI.hpp>


void SFMLWindow();
void LoadTGUIWidgets(tgui::GuiBase& gui, Grid* grid_ptr);
void LoadSFMLWidgets(sf::RenderWindow& window);
void CreateLegendLabel(tgui::GuiBase& gui, std::string text, int size, int x, int y);
void CreateLegendTile(sf::RenderWindow& window, int length, int width, int r, int g, int b, int x, int y);

void TempResetGrid(Grid grid);

// Test
void ChangeBackground(sf::RenderWindow& window);
void PrintStatement();
