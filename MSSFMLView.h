#ifndef CPP_MSSFMLVIEW_H
#define CPP_MSSFMLVIEW_H

#include "SFML/Graphics.hpp"
#include "MinesweeperBoard.h"

class MSSFMLView
{

    MinesweeperBoard & board;
    sf::RectangleShape r;
    sf::CircleShape bomb;
    sf::CircleShape flag;
    sf::RectangleShape k;

    sf::Font font;
    sf::Text t1,t2,t3,t4, wygrana, przegrana;

public:
    explicit MSSFMLView(MinesweeperBoard & b);

    void draw (sf::RenderWindow & win);
};




#endif //CPP_MSSFMLVIEW_H
