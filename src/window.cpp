#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <TGUI/TGUI.hpp>


void SfmlWindow() {
    sf::RenderWindow sfml_window(sf::VideoMode(1500,900), "Pathfinder Visualizer");
    tgui::GuiSFML gui{sfml_window};

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
        sfml_window.clear(sf::Color::White);
        gui.draw();  // draw all widgets in the gui
        sfml_window.display();
    }
}
