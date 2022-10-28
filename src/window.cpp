#include "../include/window.h"

void window() {
    sf::RenderWindow window(sf::VideoMode(1500,900), "Pathfinder Visualizer");
    tgui::GuiSFML gui{window};

    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            gui.handleEvent(event);  // inform tgui about the event

            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);

        // draw everything here...
        // end the current frame

        window.clear();
        gui.draw();  // draw all widgets in the gui
        window.display();
    }
}
