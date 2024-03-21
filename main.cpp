#include <iostream>
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"
#include "MSMouse.h"
#include "SFML/Graphics.hpp"
using namespace std;


int main()
{

    sf::RenderWindow window(sf::VideoMode(800, 600), "Grafika w C++/SFML");
    window.setVerticalSyncEnabled(false);
    window.setFramerateLimit(30);

    MinesweeperBoard board(10, 10, EASY);
    MSSFMLView view (board);
    MSMouse ctrl(board,view);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
            continue;
        }
        ctrl.Events(event);
        window.clear();
        view.draw(window);
        window.display();
    }


    return 0;

}
