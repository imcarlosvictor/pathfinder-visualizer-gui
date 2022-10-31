#include "../include/window.h"

void SfmlWindow() {
    sf::RenderWindow sfml_window(sf::VideoMode(1500,900), "Pathfinder Visualizer");
    tgui::GuiSFML gui{sfml_window};
    GuiWidget(gui);  // add widgets

    while(sfml_window.isOpen()) {
        sf::Event event;
        while (sfml_window.pollEvent(event)) {
            gui.handleEvent(event);  // inform tgui about the event

            if (event.type == sf::Event::Closed)
                sfml_window.close();
        }

        // draw everything here...
        // end the current frame

        sfml_window.clear();
        sfml_window.clear(sf::Color::Black);
        gui.draw();  // draw all widgets in the gui
        sfml_window.display();
    }
}

void GuiWidget(tgui::GuiBase& gui) {
    // Title
    auto title = tgui::Label::create();
    title->setText("Algorithm Visualizer");
    title->setTextSize(25);
    title->setPosition(40, 50);
    gui.add(title);

    // Map Algorithm Dropdown
    auto map_lbl = tgui::Label::create();
    map_lbl->setText("Map Generate");
    map_lbl->setTextSize(18);
    map_lbl->setPosition(40, 140);
    gui.add(map_lbl);

    auto map_btn = tgui::ComboBox::create();
    map_btn->addItem("Item 1");
    map_btn->addItem("Item 2");
    map_btn->addItem("Item 3");
    map_btn->setSize(250, 25);
    map_btn->setPosition(40, 170);
    gui.add(map_btn);

    // Algorithm Visualizer
    auto algo_lbl = tgui::Label::create();
    algo_lbl->setText("Algorithms");
    algo_lbl->setTextSize(18);
    algo_lbl->setSize(250, 25);
    algo_lbl->setPosition(40, 240);
    gui.add(algo_lbl);

    auto algo_btn = tgui::ComboBox::create();
    algo_btn->addItem("Dijkstra's Algorithm");
    algo_btn->addItem("A Search*");
    algo_btn->addItem("Greedy Best-first Search");
    algo_btn->addItem("Swarm Algorithm");
    algo_btn->addItem("Convergent Swarm Algorithm");
    algo_btn->addItem("Bidirectional Swarm Algorithm");
    algo_btn->addItem("Breath-first Search");
    algo_btn->addItem("Depth-first Search");
    algo_btn->setSize(250, 25);
    algo_btn->setPosition(40, 270);
    gui.add(algo_btn);

    // Legend
    auto legend_lbl = tgui::Label::create();
    legend_lbl->setText("Legend");
    legend_lbl->setTextSize(18);
    legend_lbl->setSize(250, 25);
    legend_lbl->setPosition(40, 340);
    gui.add(legend_lbl);

    // Reset Button
    auto reset_btn = tgui::Button::create();
    reset_btn->setText("RESET");
    reset_btn->setSize(120,60);
    reset_btn->setPosition(40, 780);
    gui.add(reset_btn);
    
    // Start Button
    auto button = tgui::Button::create();
    button->setText("START");
    button->setSize(120,60);
    button->setPosition(165, 780);
    gui.add(button);
}
