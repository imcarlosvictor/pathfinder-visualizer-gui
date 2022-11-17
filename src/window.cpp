#include "../include/window.h"
#include "../include/maze.h"

void SFMLWindow() {
    sf::RenderWindow sfml_window(sf::VideoMode(1500,900), "Pathfinder Visualizer");
    tgui::GuiSFML gui{sfml_window};
    LoadTGUIWidgets(sfml_window, gui);  // load TGUI widgets

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
        sfml_window.clear(sf::Color(19,19,19));
        LoadSFMLWidgets(sfml_window);  // load SFML widgets
        gui.draw();  // draw all widgets in the gui
        CreateMap(sfml_window);
        sfml_window.display();
    }
}

void LoadTGUIWidgets(sf::RenderWindow& window, tgui::GuiBase& gui) {
    // Labels
    CreateLegendLabel(gui, "Algorithm Visualizer", 18, 60, 50);  // GUI title
    CreateLegendLabel(gui, "Map Generation", 15, 40, 140);  // Content label
    CreateLegendLabel(gui, "Pathfinder Algorithms", 15, 40, 320);  // Content label
    CreateLegendLabel(gui, "Legend", 15, 40, 430);  // Startpoint label
    CreateLegendLabel(gui, "Startpoint", 12, 80, 467);  // Startpoint legend label
    CreateLegendLabel(gui, "Endpoint", 12, 80, 507);  // Endpoint legend label
    CreateLegendLabel(gui, "Path", 12, 80, 547);  // Path legend label
    CreateLegendLabel(gui, "Unexplored", 12, 80, 587);  // Unxplored legend label
    CreateLegendLabel(gui, "Explored", 12, 218, 467);  // Explored legend label
    CreateLegendLabel(gui, "Border", 12, 218, 507);  // Border legend label
    
    // Map algorithm sidenote
    auto user_note = tgui::Label::create();
    user_note->setText("Note: You can choose either to generate \na map or create your own by manually \nclicking the squares");
    user_note->getRenderer()->setTextColor(sf::Color(93,93,93));
    user_note->setTextSize(12);
    user_note->setPosition(40, 163);
    gui.add(user_note);

    // Map algorithm options
    auto map_btn = tgui::ComboBox::create();
    map_btn->addItem("Item 1");
    map_btn->addItem("Item 2");
    map_btn->addItem("Item 3");
    map_btn->getRenderer()->setBackgroundColor(sf::Color(213,213,213));
    map_btn->setSize(250, 25);
    map_btn->setPosition(40, 210);
    gui.add(map_btn);

    // Generate Map Button
    auto generate_map_btn = tgui::Button::create();
    generate_map_btn->setText("Generate Map");
    generate_map_btn->getRenderer()->setBackgroundColor(sf::Color(213,213,213));
    generate_map_btn->getRenderer()->setBorderColor(sf::Color(19,19,19));
    generate_map_btn->getRenderer()->setBackgroundColorHover(sf::Color(213,213,213,200));
    generate_map_btn->setSize(250,40);
    generate_map_btn->setPosition(40, 240);
    gui.add(generate_map_btn);
    // Add button functionality
    generate_map_btn->onPress([&]{
            CreateMap(window);
            PrintStatement();
            window.clear(sf::Color::White);
            /* generate_map_btn->getRenderer()->setBackgroundColor(sf::Color::Red); */
            std::cout << "button pressed" << std::endl;
            });
    /* generate_map_btn->onPress(ChangeBackground); */


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
    algo_btn->getRenderer()->setBackgroundColor(sf::Color(213,213,213));
    algo_btn->setSize(250, 25);
    algo_btn->setPosition(40, 350);
    gui.add(algo_btn);
    
    // Reset maze button
    auto reset_maze_btn = tgui::Button::create();
    reset_maze_btn->setText("Reset Maze");
    reset_maze_btn->getRenderer()->setBackgroundColor(sf::Color(213,213,213));
    reset_maze_btn->getRenderer()->setBorderColor(sf::Color(19,19,19));
    reset_maze_btn->getRenderer()->setBackgroundColorHover(sf::Color(213,213,213,200));
    reset_maze_btn->setSize(125,35);
    reset_maze_btn->setPosition(40, 744);
    gui.add(reset_maze_btn);
    
    // Reset path button
    auto reset_path_btn = tgui::Button::create();
    reset_path_btn->setText("Reset Path");
    reset_path_btn->getRenderer()->setBackgroundColor(sf::Color(213,213,213));
    reset_path_btn->getRenderer()->setBorderColor(sf::Color(19,19,19));
    reset_path_btn->getRenderer()->setBackgroundColorHover(sf::Color(213,213,213,200));
    reset_path_btn->setSize(125,35);
    reset_path_btn->setPosition(165, 744);
    gui.add(reset_path_btn);
    
    // Start button
    auto visualize_btn = tgui::Button::create();
    visualize_btn->setText("VISUALIZE");
    visualize_btn->getRenderer()->setBackgroundColor(sf::Color(0,0,220));
    visualize_btn->getRenderer()->setBorderColor(sf::Color(19,19,19));
    visualize_btn->getRenderer()->setTextColor(sf::Color(213,213,213));
    visualize_btn->getRenderer()->setBackgroundColorHover(sf::Color(0,0,220,200));
    visualize_btn->getRenderer()->setTextColorHover(sf::Color(213,213,213,200));
    visualize_btn->setSize(250,50);
    visualize_btn->setPosition(40, 780);
    gui.add(visualize_btn);
}

void LoadSFMLWidgets(sf::RenderWindow& window) {
    CreateLegendTile(window, 30, 30, 34, 139, 34, 43, 460);  // Startpoint tile
    CreateLegendTile(window, 30, 30, 253, 184, 37, 43, 500);  // Endpoint tile
    CreateLegendTile(window, 30, 30, 0, 0, 220, 43, 540);  // Path tile
    CreateLegendTile(window, 30, 30, 213, 213, 213, 43, 580);  // Unexplored tile
    CreateLegendTile(window, 30, 30, 62, 62, 62, 180, 460);  // Explored tile
    CreateLegendTile(window, 30, 30, 0, 0, 0, 180, 500);  // Border tile
}

void CreateLegendLabel(tgui::GuiBase& gui, std::string text, int size, int x, int y) {
    auto lbl = tgui::Label::create();
    lbl->setText(text);
    lbl->getRenderer()->setTextColor(sf::Color(213,213,213));
    lbl->setTextSize(size);
    lbl->setSize(250, 25);
    lbl->setPosition(x, y);
    gui.add(lbl);
}

void CreateLegendTile(sf::RenderWindow& window, int length, int width, int r, int g, int b, int x, int y) {
    sf::RectangleShape legend_tile;
    legend_tile.setSize(sf::Vector2f(length, width));
    legend_tile.setFillColor(sf::Color(r,g,b));
    legend_tile.setOutlineColor(sf::Color(19,19,19));
    legend_tile.setPosition(x, y);
    window.draw(legend_tile);
}


// Test
void CreateMap(sf::RenderWindow& window) {
    int y = 0;
    for (int i = 0; i < 30; i++) {
        sf::RectangleShape tile(sf::Vector2f(30, 30));
        tile.setFillColor(sf::Color::White);
        tile.setOutlineColor(sf::Color::Black);
        tile.setOutlineThickness(1);
        tile.setPosition(330, y);
        window.draw(tile);
        y += 30;
    }
}

/*
 * Create the map for the visualizer
 */
/*void CreateMap(sf::RenderWindow& window) {*/
/*    Map map(39, 30);*/
/*    map.CreateMap(window);*/
/*}*/

void ChangeBackground(sf::RenderWindow& window) {
    window.clear(sf::Color::Red);
}

void PrintStatement() {
    std::cout << "hwllo world" << std::endl;
}
