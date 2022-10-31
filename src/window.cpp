#include "../include/window.h"

void SfmlWindow() {
    sf::RenderWindow sfml_window(sf::VideoMode(1500,900), "Pathfinder Visualizer");
    tgui::GuiSFML gui{sfml_window};
    LoadWidgets(gui);  // add widgets

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

void LoadWidgets(tgui::GuiBase& gui) {
    // Title
    auto title = tgui::Label::create();
    title->setText("Algorithm Visualizer");
    title->setTextSize(25);
    title->setPosition(40, 50);
    gui.add(title);

    // Map algorithm label 
    auto map_lbl = tgui::Label::create();
    map_lbl->setText("Map Generate");
    map_lbl->setTextSize(18);
    map_lbl->setPosition(40, 140);
    gui.add(map_lbl);
    
    // Map algorithm sidenote
    auto user_note = tgui::Label::create();
    user_note->setText("Note: You can choose either to generate \na map or create your own by manually \nclicking the squares");
    user_note->setTextSize(12);
    user_note->setPosition(40, 163);
    gui.add(user_note);

    // Map algorithm options
    auto map_btn = tgui::ComboBox::create();
    map_btn->addItem("Item 1");
    map_btn->addItem("Item 2");
    map_btn->addItem("Item 3");
    map_btn->setSize(250, 25);
    map_btn->setPosition(40, 210);
    gui.add(map_btn);

    // Generate Map Button
    auto generate_map_btn = tgui::Button::create();
    generate_map_btn->setText("Generate Map");
    generate_map_btn->setSize(250,40);
    generate_map_btn->setPosition(40, 240);
    gui.add(generate_map_btn);

    // Pathfinder algorithm label
    auto algo_lbl = tgui::Label::create();
    algo_lbl->setText("Algorithms");
    algo_lbl->setTextSize(18);
    algo_lbl->setSize(250, 25);
    algo_lbl->setPosition(40, 320);
    gui.add(algo_lbl);

    // Pathfinder algorithm options
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
    algo_btn->setPosition(40, 350);
    gui.add(algo_btn);

    // Legend
    auto legend_lbl = tgui::Label::create();
    legend_lbl->setText("Legend");
    legend_lbl->setTextSize(18);
    legend_lbl->setSize(250, 25);
    legend_lbl->setPosition(40, 440);
    gui.add(legend_lbl);

    // Reset Maze Button
    auto reset_maze_btn = tgui::Button::create();
    reset_maze_btn->setText("Reset Maze");
    reset_maze_btn->setSize(124,40);
    reset_maze_btn->setPosition(40, 739);
    gui.add(reset_maze_btn);
    
    // Reset Path Button
    auto reset_path_btn = tgui::Button::create();
    reset_path_btn->setText("Reset Path");
    reset_path_btn->setSize(124,40);
    reset_path_btn->setPosition(165, 739);
    gui.add(reset_path_btn);
    
    // Start Button
    auto button = tgui::Button::create();
    button->setText("VISUALIZE");
    button->setSize(250,50);
    button->setPosition(40, 780);
    gui.add(button);
}
