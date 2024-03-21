
#include "MSMouse.h"
#include "SFML/Graphics.hpp"
#include "MinesweeperBoard.h"
#include "MSSFMLView.h"
#include <iostream>

MSMouse::MSMouse(MinesweeperBoard &b, MSSFMLView &v) : board(b), view(v)
{

}

void MSMouse::Events (sf::Event &event)
{
    int row = (event.mouseButton.y)/25;
    int col = (event.mouseButton.x)/25;
    if (event.type == sf::Event::MouseButtonReleased)
    {
        if (event.mouseButton.button == sf::Mouse::Right)
        {
            board.toggleFlag(row,col);
        }
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            board.revealField( row,col);
        }
    }
}